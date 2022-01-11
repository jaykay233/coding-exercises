#include <signal.h>
#include <cstdio>
#include <unistd.h>
#include <signal.h>

void sig_quit(int signo){
    printf("receive sigquit\n");
}

int main(int argc, char* const * argv)
{
    sigset_t newmask, oldmask, pendmask;
    if(signal(SIGQUIT, sig_quit) == SIG_ERR)
    {
        printf("no catch sigusr1\n");
        _exit(1);
    }

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);

    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    {
        printf("sigprocmask failed!\n");
        _exit(1);
    }
    printf("我要开始休息10s了一一-begin—′此时我无法接收SIGQU∏信号!\n");
    sleep(10);
    printf("我已经休息了10s\n");
    if(sigismember(&newmask,SIGQUIT))
    {
        printf("SIGQUIT信号被屏蔽了\n");
    }else{
        printf("S工GQUIT信号没有被屏蔽!!! !!!\n");
    }
    if(sigismember(&newmask, SIGHUP))
    {
        printf("SIGHUP信号被屏蔽了\n");
    }else{
        printf("SIGHUP信号没有被屏蔽\n");
    }

    if(sigprocmask(SIG_SETMASK,&oldmask,NULL) < 0)
    {
        printf("sigprocmask failed\n");
        _exit(1);
    }
    printf("sigprocmask success\n");
    if(sigismember(&oldmask, SIGQUIT))//测试-个指定的信号位是否被置位′这里测试的是oldmask
    {
        printf("S1GQUIT信号被屏蔽了!\n");
    }else{
        printf("SIGQUIT信号没有被屏蔽，您可以发送SIGQUIT信号，我要sleep 10s钟");
        int mys1 = sleep(10);
        if(mys1>0)
        {
            printf("sleep还没睡够，剩余%ds\n",mys1);
        }
    }
    return 0;
}