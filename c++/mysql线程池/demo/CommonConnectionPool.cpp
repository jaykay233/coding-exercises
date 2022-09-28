#include "CommonConnectionPool.h"
#include <iostream>
#include <cstdio>
#include "public.h"
using namespace std;
//线程安全的懒汉单例模式
ConnectionPool *ConnectionPool::getConnectionPool()
{
    static ConnectionPool pool; //编译器会自动lock & unlock
    return &pool;
}

bool ConnectionPool::LoadConfigFile() //从配置文件中夹在配置项
{
    FILE *pf = fopen("mysql.ini", "r");
    if (pf == nullptr)
    {
        LOG("mysql.ini file not exists");
        return false;
    }

    while (!feof(pf))
    {
        char line[1024] = {0};
        fgets(line, 1024, pf);
        string str = line;
        int idx = str.find('=', 0);
        if (idx == -1) //无效配置项
        {
            continue;
        }

        // password = xxx\n
        int endidx = str.find('\n', idx);
        string key = str.substr(0, idx);
        string value = str.substr(idx + 1, endidx - idx - 1);

        if (key == "ip")
        {
            _ip = value;
        }
        else if (key == "port")
        {
            _port = atoi(value.c_str());
        }
        else if (key == "username")
        {
            _username = value;
        }
        else if (key == "password")
        {
            _password = value;
        }
        else if (key == "dbname")
        {
            _dbname = value;
        }
        else if (key == "initSize")
        {
            _initSize = atoi(value.c_str());
        }
        else if (key == "maxSize")
        {
            _maxSize = atoi(value.c_str());
        }
        else if (key == "maxIdleTime")
        {
            _maxIdleTime = atoi(value.c_str());
        }
        else if (key == "ConnectionTimeOut")
        {
            _connectionTimeout = atoi(value.c_str());
        }
    }
    return true;
}

//连接池构造
ConnectionPool::ConnectionPool()
{   
    //加在配置项
    if(!LoadConfigFile())
    {
        return;
    }

    //创建初始数量的连接
    for(int i = 0; i < _initSize;i++)
    {
        Connection *p = new Connection();
        p->connect(_ip, _port, _username, _password, _dbname);
        p->refreshAliveTime(); //刷新一下空闲时间
        _connectionQue.push(p);
        _connectionCnt ++;
    }

    // 启动一个新的线程，作为连接生产者
    thread produce(std::bind(&ConnectionPool::produceConnectionTask, this));
    produce.detach();
    // 启动一个新的定时线程，扫描超过maxIdleTime的空闲连接，进行对于连接的回收
    thread scanner(std::bind(&ConnectionPool::scannerConnectionTask, this));
    scanner.detach();
}

void ConnectionPool::produceConnectionTask()
{
    for(;;)
    {
        unique_lock<mutex> lock(_queueMutex);
        while(!_connectionQue.empty())
        {
            cv.wait(lock);
        }

        //连接数量没到上限，继续创建新的连接
        if(_connectionCnt < _maxSize)
        {
            Connection* p = new Connection();
            p->connect(_ip, _port, _username, _password, _dbname);
            p->refreshAliveTime();
            _connectionQue.push(p);
            _connectionCnt ++;
        }
        //通知消费者线程消费连接
        cv.notify_all();
    }
}

shared_ptr<Connection> ConnectionPool::getConnection()
{
    unique_lock<mutex> lock(_queueMutex);
    while( _connectionQue.empty())
    {
        if(cv_status::timeout == cv.wait_for(lock, chrono::milliseconds(_connectionTimeout))){
            if(_connectionQue.empty())
            {
                LOG("获取空闲连接超时了...获取连接失败!");
                return nullptr;
            }
        }
    }
    
    /*
        shared_ptr智能指针析构时，会把connection资源直接delete掉，相当于调用connection析构函数，connection就被close掉，所以需要自定义shared_ptr的释放资源的方式，把connection直接归还到queue中
    */
    shared_ptr<Connection> sp(_connectionQue.front(),[&](Connection *pcon){
        // 这里是在服务器应用线程中调用的，所以一定要考虑队列的线程安全操作
        unique_lock<mutex> lock(_queueMutex);
        pcon->refreshAliveTime();
        _connectionQue.push(pcon);
    });
    _connectionQue.pop();
    cv.notify_all(); //谁消费了队列中的最后一个connection，谁负责通知一下
    return sp;
}

void ConnectionPool::scannerConnectionTask()
{
    for(;;)
    {

        this_thread::sleep_for(chrono::seconds(_maxIdleTime));
        // 扫描整个队列，释放多余连接
        unique_lock<mutex> lock(_queueMutex);
        while(_connectionCnt > _initSize)
        {
            Connection* p = _connectionQue.front();
            if (p->getAliveeTime() > _maxIdleTime * 1000)
            {
                _connectionQue.pop();
                _connectionCnt --;
                delete p;
            }
            else break;
        }
    }
}