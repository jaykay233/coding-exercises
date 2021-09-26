#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#define THRUM   4
static pthread_mutex_t mut[THRUM];

static next(int n){
    if(n + 1 == THRUM)
        return 0;
    return n + 1;
}


static void *thr_func(void* p){
    int n = (int)p;
    int c = 'a' + n;
    while(1){
        pthread_mutex_lock(mut+n);
        write(1,&c,1);
        pthread_mutex_unlock(mut+next(n));
    }
    pthread_exit(NULL);
}

int main(){
    int err;
    int i;
    pthread_t tid[THRUM];
    for(i =0;i<THRUM;i++){
        pthread_mutex_init(mut+i, NULL);
        pthread_mutex_lock(mut+i);

        err = pthread_create(tid+i,NULL,thr_func, (void*)i);
        if(err){
            fprintf(stderr,"pthread_creete():%s\n",strerror(err));
            exit(1);
        }
    }

    pthread_mutex_unlock(mut+0);
    

    alarm(5);

    for(i = 0;i<THRUM;i++){
        pthread_join(tid[i],NULL);
    }

    exit(0);
}