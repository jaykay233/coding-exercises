#include <pthread.h>
#include <mutex>
#include <deque>
#include <cassert>
#include <condition_variable>
using namespace std;
std::mutex mu;
std::condition_variable cv;
std::deque<int> queue;

int dequeue(){
    std::unique_lock<std::mutex> lck(mu);
    while(queue.empty()){
        cv.wait(lck);
    }
    assert(!queue.empty());
    int top = queue.front();
    queue.pop_front();
    return top;
}

void enqueue(int x){
    std::unique_lock<std::mutex> lck(mu);
    queue.push_back(x);
    cv.notify_one();
}

int main(){


    return 0;
}