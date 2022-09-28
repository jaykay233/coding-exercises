#pragma once 
#include <string>
#include <queue>
#include <mutex>
#include <atomic>
#include <thread>
#include <memory>
#include <functional>
#include <condition_variable>
using namespace std;
#include "Connection.h"

class ConnectionPool
{
public: 
    //获取
    static ConnectionPool* getConnectionPool();
    shared_ptr<Connection> getConnection();
private:
    ConnectionPool();
    bool LoadConfigFile(); //从配置文件中夹在配置项
    //运行在独立线程中，专门负责生产新连接
    void produceConnectionTask();
    // 扫描线程池的函数
    void scannerConnectionTask();
    string _ip; // mysql ip
    unsigned short _port; // mysql 端口号
    string _username; // mysql用户名
    string _password; // mysql密码
    string _dbname; // mysql数据库
    int _initSize; // 连接池初始连接量
    int _maxSize; // 连接池的最大连接量
    int _maxIdleTime; // 连接池最大空闲时间
    int _connectionTimeout; // 连接池获取连接的超时时间

    queue<Connection*>  _connectionQue;
    mutex _queueMutex; //维护连接队列的线程安全互斥锁
    atomic_int _connectionCnt;// 
    condition_variable cv;
};