#include "TaskPool.h"

TaskPool::TaskPool():m_bRunning(false)
{

}

void TaskPool::init(int threadNum/*=5*/){
    if(threadNum<=0)
        threadNum = 5;
    m_bRunning = true;
    for(int i =0;i<threadNum;i++){
        std::shared_ptr<std::thread> spThread;
        spThread.reset(new std::thread(std::bind(&TaskPool::threadFunc, this)));
        m_threads.push_back(spThread);
    }
}