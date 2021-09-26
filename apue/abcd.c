#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#define THRUM   4

static void *thr_func(void* p){
    int c = 'a' + (int)p;
    while(1)
        write(1,&c,1);
    pthread_exit(NULL);
}

int main(){
    int err;
    int i;
    pthread_t tid[THRUM];
    for(i =0;i<THRUM;i++){
        err = pthread_create(tid+i,NULL,thr_func, (void*)i);
        if(err){
            fprintf(stderr,"pthread_creete():%s\n",strerror(err));
            exit(1);
        }
    }

    alarm(5);

    for(i = 0;i<THRUM;i++){
        pthread_join(tid[i],NULL);
    }

    exit(0);
}