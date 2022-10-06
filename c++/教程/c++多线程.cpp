#include <iostream>
#include <list>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

//共享变量多线程会进行缓存
//所以加上缓存，要访问原始变量
//防止多线程对共享变量进行缓存
volatile std::atomic_bool isReady(false);
volatile std::atomic_int mycount(0);

void task()
{
    while (!isReady)
    {
        std::this_thread::yield(); //线程让出当前的cpu时间片，等待下一次调度
    }

    for (int i = 0; i < 100; i++)
    {
        mycount++;
    }
}

void threadHandler()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "hello thread!" << endl;
}

std::mutex mtx;
std::condition_variable cv;

class Queue
{
public:
    void put(int val)
    {
        lock_guard<std::mutex> guard(mtx);
        while (!que.empty())
        {
            unique_lock<std::mutex> lck(mtx);
            cv.wait(lck);
        }
        que.push(val);
        // notify_all()
        // notify_one()
        cv.notify_all(); //通知其他所有线程，我生产了一个物品，你们赶紧消费吧
        //其他线程得到通知，就会从等待状态=》阻塞状态=》获取互斥锁才能继续执行
        cout << "生产者生产:" << val << "号物品" << endl;
    }

    int get()
    {
        lock_guard<std::mutex> guard(mtx);
        while (que.empty())
        {
            //消费者线程发现que是空的，通知生产者先生产物品
            //进入等待状态，把互斥锁mutex释放
            unique_lock<std::mutex> lck(mtx);
            cv.wait(lck); 
        }
        int val = que.front();
        que.pop();
        cv.notify_all(); //通知其他线程我消费完了
        cout << "消费者消费" << val << "号商品" << endl;
        return val;
    }

private:
    queue<int> que;
};

void producer(Queue *que)
{
    for (int i = 1; i <= 10; i++)
    {
        que->put(i);
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}

void consumer(Queue *que)
{
    for (int i = 1; i <= 10; i++)
    {
        que->get();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}

int main()
{
    // list<std::thread> tlist;
    // for (int i = 0; i < 10; i++)
    // {
    //     tlist.push_back(std::thread(task));
    // }

    // std::this_thread::sleep_for(std::chrono::seconds(3));
    // isReady = true;

    // for (std::thread &t : tlist)
    // {
    //     t.join();
    // }

    // cout << "count: " << mycount << endl;
    // return 0;

    // std::thread t1(threadHandler);
    // t1.join();

    Queue que; //两个线程共享的队列

    std::thread t1(producer, &que);
    std::thread t2(consumer, &que);

    t1.join();
    t2.join();

    return 0;
}