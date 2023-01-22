#include <iostream>
#include <functional>
#include <thread>
#include <future>
using namespace std;

int sum1(int a,int b)
{
    //比较耗时
    return a + b;
}

int sum2(int a,int b,int c)
{
    return a + b + c;
}

int main(){
    packaged_task<int(int,int)> task(sum1);
    future<int> res = task.get_future();
    // task(10,20);
    // cout << res.get() << endl;
    thread t(std::move(task), 10,20);
    t.detach();
    cout << res.get() << endl;
    // thread t1(sum1, 10, 20);
    // thread t2(sum2, 1, 2, 3);
    // t1.join();
    // t2.join();
    return 0;
}