#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <list>
#include <semaphore.h>
#include <iostream>

class Task{
public: 
    Task(int taskID){
        this->taskID = taskID;
    }

    void doTask(){
        std::cout<<"handle a task, taskID: "<<taskID<<", threadID: "<<pthread_self()<<std::endl;
    }
private: 
    int taskID;
};

pthread_mutex_t mymutex;
std::list<Task*> tasks;
sem_t mysemaphore;

void* consumer_thread(void* param){
    Task* pTask = NULL;
    while(true){
        if(sem_wait(&mysemaphore)!=0)
            continue;
        if(tasks.empty())
            continue;
        pthread_mutex_lock(&mymutex);
        pTask = tasks.front();
        tasks.pop_front();
        pthread_mutex_unlock(&mymutex);
        
        pTask->doTask();
        delete pTask;
    }
    return NULL;
}

void* producer_thread(void* param){
    int taskID = 0;
    Task* pTask = NULL;
    while(true){
        pTask = new Task(taskID);
        pthread_mutex_lock(&mymutex);
        tasks.push_back(pTask);
        std::cout << "produce a task,taskID: "<<taskID<<", threadID"<<pthread_self()<<std::endl;
        pthread_mutex_unlock(&mymutex);
        sem_post(&mysemaphore);
        taskID ++;
        sleep(5);
    }
    return NULL;
}

int main(){
    pthread_mutex_init(&mymutex, NULL);
    // sem_init(&mysemaphore, 0, 0);
    sem_open("mysemaphore", O_CREAT|O_EXCL, S_IRWXU, 0);
    pthread_t consumerthreadID[5];
    for(int i =0;i<5;i++)
        pthread_create(&consumerthreadID[i],NULL,consumer_thread,NULL);
    
    pthread_t producerThreadID;
    pthread_create(&producerThreadID, NULL, producer_thread, NULL);
    pthread_join(producerThreadID, NULL);
    for(int i =0;i<5;i++)
        pthread_join(consumerthreadID[i],NULL);
    // sem_destroy(&mysemaphore);
    sem_unlink("mysemaphore");
    pthread_mutex_destroy(&mymutex);
    return 0;
}