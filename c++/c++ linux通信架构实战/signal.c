#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int g_mysign = 0;
void muNEfunc(int value){
    g_mysign = value;

}

void sig_usr(int signo){
    printf("sig_usr");
}

int main(int argc,char** argv){
    if(signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        printf("无法捕捉SIGUSR信号\n");
    }

    for(;;)
    {
        sleep(1);
        printf("休息1秒\n");
        muNEfunc(15);
        printf("g_mysign=%d\n",g_mysign);
    }
    printf("再见\n");
    return 0;
}