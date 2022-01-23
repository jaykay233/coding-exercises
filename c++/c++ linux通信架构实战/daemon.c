#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

int ngx_daemon(){
    int fd;
    switch(fork()){
        case -1:
            return -1;
        case 0:
            break;
        default:
            exit(0);
    }
    if (setsid()==-1){
        return -1;
    }
    umask(0); //设置为0，不要让它来限制文件权限，以免引起混乱
    fd = open("/dev/null",O_RDWR);
    if(fd==-1){
        return -1;
    }
    if(dup2(fd,STDIN_FILENO)==-1){
        return -1;
    }
    if(dup2(fd,STDOUT_FILENO)==-1){
        return -1;
    }
    if(fd>STDERR_FILENO){
        if(close(fd) == -1){
            //记录错误日志
            return -1;
        }
    }
}

int main(int argc, char** argv){
    if(ngx_daemon()!=1)
    {
        return 1;
    }
    else
    {
        for(;;)
        {
            sleep(1);
            printf("休息1秒，进程id=%d!\n",getpid());
        }
    }
    return 0;
}