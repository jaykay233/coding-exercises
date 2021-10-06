#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>


#define MEMSIZE 1024

int main(){
    pid_t pid;
    char* ptr = mmap(NULL,MEMSIZE,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    if(ptr == MAP_FAILED){
        perror("mmap()");
        exit(1);
    }

    pid = fork();
    if(pid<0)
    {
        perror("fork()");
        munmap(ptr,MEMSIZE);
        exit(1);
    }

    if(pid == 0) //child write 
    {
        strcpy(ptr,"Hello!");
        munmap(ptr,MEMSIZE);
        exit(0);
    }
    else
    {
        wait(NULL);
        puts(ptr);
        munmap(ptr,MEMSIZE);
        exit(0);
    }

    exit(0);
}