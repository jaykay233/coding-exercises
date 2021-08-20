#include <pthread.h>
#include <unistd.h>
#include <iostream>

int resourceID = 0;
pthread_rwlock_t myrwlock;

void* read_thread(void* param){
    while(true){
        pthread_rwlock_rdlock(&myrwlock);
        std::cout << "read thread ID: "<<pthread_self() << ", resourceID: "<<resourceID << std::endl;
        sleep(1);
        pthread_rwlock_unlock(&myrwlock);
    }
    return NULL;
}

void* write_thread(void* param){
    while(true){
        pthread_rwlock_wrlock(&myrwlock);
        ++resourceID;
        std::cout<<"write thread ID: "<<pthread_self()<<", resourceID: "<<resourceID << std::endl;
        sleep(1);
        pthread_rwlock_unlock(&myrwlock);
    }
    return NULL;
}

int main(){
    pthread_rwlock_init(&myrwlock, NULL);
    pthread_t readThreadID[5];
    for(int i =0;i<5;i++)
        pthread_create(&readThreadID[i],NULL,read_thread, NULL);
    pthread_t writeThreadID;
    pthread_create(&writeThreadID, NULL, write_thread,NULL);
    
    for(int i =0;i<5;i++)
        pthread_join(readThreadID[i],NULL);
    pthread_rwlock_destroy(&myrwlock);
    return 0;
}