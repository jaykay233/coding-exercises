#include <unistd.h>
#include <stdio.h>

int main(int argc, char* const* argv){
    pid_t pid;
    printf("非常高兴，大家和老师一起学习《linux c++通讯架构实战》\n");

    pid = fork();
    if( pid < 0)
    {
        printf("fork()进程出错!\n");
    }
    else if(pid == 0)
    {
        //子进程条件满足
        printf("fork()进程出错！\n");
        setsid();
        for(;;)
        {
            sleep(1);
            printf("休息1秒\n");
        }
        return 0;
    }else{
        //父进程条件满足
        for(;;)
        {
            sleep(1);
            printf("父进程休息1秒\n");
        }
    }
    return 0;
}