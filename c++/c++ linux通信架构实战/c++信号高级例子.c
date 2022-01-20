#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void sig_usr(int signo){
    if(signo == SIGUSR1)
    {
        printf("收到了SIGUSR1信号，我休息10s....!\n");
        sleep(10);
        printf("收到了SIGUSR1信号，我休息10s完毕，苏醒了....!\n");
    }
    else if(signo == SIGUSR2)
    {
        printf("收到了SIGUSR2信号，我休息了10s....!\n");
        sleep(10);
        printf("收到了SIGUSR2信号，我休息了10s再完毕，苏醒了....!\n");
    }
    else {
        printf("收到了未捕捉的信号%d!\n",signo);
    }
}


int main(int argc,char* const *argv){
    if(signal(SIGUSR1,sig_usr) == SIG_ERR)
    {
        printf("无法捕捉SIGUSR1信号!\n");
    }
    if(signal(SIGUSR2,sig_usr) == SIG_ERR)
    {
        printf("无法捕捉SIGUSR2信号！\n");
    }

    for(;;)
    {
        sleep(1);
        printf("休息1s～～～～!\n");
    }
    printf("再见！\n");
    return 0;
}