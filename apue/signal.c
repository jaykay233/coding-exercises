#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void int_handler(int s){
    write(1,"!",1);
}

int main(){
    int i;
    // signal(SIGINT,SIG_IGN);
    //并不是遇到就调用，而是说在程序未结束的情况下，遇到中断就调用
    signal(SIGINT,int_handler);
    for(i = 0;i < 10; i++){
        write(1,"*",1);
        sleep(1);
    }

}