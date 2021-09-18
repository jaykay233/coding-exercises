#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#define N 3
#define LEFT 100000002
#define RIGHT 100000200

int main(){
    printf("[%d] start!\n",getpid());
    fflush(NULL);
    pid_t pid = 0;
    int i,j ,mark;
    for(int n=0;n<N;n++){
        pid = fork();
        if(pid<0){
            perror("ok");
            for(int k=0;k<n;k++){
                wait(NULL);
            }
            exit(1);
        }

        if(pid==0){
            for(int i = LEFT + n;i<=right; i += N){
                mark = 1;
                for( j = 2;j<=i/2;j++){
                    if(i%j==0){
                        mark = 0;
                        break;
                    }
                }
                if(mark){
                    printf("%d is a primer\n",i);
                }
            }
            printf("[%d] is a primer\n",i);
        }
        printf("[%d] exit\n",n);
        exit(0);
    }
}