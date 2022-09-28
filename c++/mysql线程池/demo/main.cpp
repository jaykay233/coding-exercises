#include <mysql.h>
#include "public.h"
#include <iostream>
#include "Connection.h"
#include "CommonConnectionPool.h"
#include <string>
using namespace std;

//把下面配置信息修改为自己数据库的
const char host[] = "localhost";
const char user[] = "root";
const char pwd[] = "1qaz2WSX";
const char database[] = "chat";
unsigned int port = 3306;


int main()
{
    // MYSQL myCont;
    // mysql_init(&myCont);

    // if (mysql_real_connect(&myCont, host, user, pwd, database, port, NULL, 0)){
    //     cout << "Hello MySQL！" << endl;
    //     // string sql = "insert into user(name,age,sex) values('zhangsan', 20, 0)";
    //     // if(mysql_query(&myCont, sql.c_str())){
    //     //     LOG("更新失败");
    //     // }
    // }
    // else
    // {
    //     cout << "connect failed!" << endl;
    // }
    // mysql_close(&myCont);
    // return 0;

    // Connection conn;
    // char sql[1024] = {0};
    // sprintf(sql, "insert into user(name,age,sex) values('%s', %d, %d)", "zhangsan", 20, 0);
    // conn.connect("127.0.0.1",3306,"root","1qaz2WSX","chat");
    // conn.update(sql);
    // return 0;
    clock_t begin = clock();
    ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for(int i = 0;i<1000;i++)
    {
        // Connection conn;
        // conn.connect("127.0.0.1", 3306, "root", "1qaz2WSX","chat");
        // conn.update(sql);
        shared_ptr<Connection> sp = cp->getConnection();
        char sql[1024] = {0};
        sprintf(sql, "insert into user(name,age,sex) values('%s',%d,%d)","zhangsan",20,0);
        sp->update(sql);
    }
    clock_t end = clock();

    cout << (end - begin) << "ms" << endl;

    return 0;
}

