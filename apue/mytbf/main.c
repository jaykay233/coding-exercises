#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <math.h>
#include "mytbf.h"

static const int SIZE = 1024;
static const int CPS = 10;
static const int BURST = 100; //最大令牌数

static volatile int token = 0; //持有令牌数

int main(int argc, char* argv[]){
    if(argc<2){
        fprintf(stdout, "Usage...");
        exit(1);
    }
    
    mytbf_t * tbf;
    tbf = mytbf_init(CPS,BURST);
    if(tbf == NULL){
        fprintf(stderr,"tbf init error");
        exit(1);
    }

    int sfd, dfd =0;
    do{
        sfd = open(argv[1],O_RDONLY);
        if(sfd < 0){
            if(errno == EINTR)
                continue;
            fprintf(stderr, "%s\n", strerror(errno));
            exit(1);
        }
    }while(sfd<0);

    char buf[SIZE];
    while(1){
        int len,ret,pos =0;
        int size = mytbf_fetchtoken(tbf,SIZE);

        if(size < 0){
            fprintf(stderr,"mytbf_fetchtoken()%s\n",strerror(-size));
            exit(1);
        }

        len = read(sfd,buf,size);
        while(len<0){
            if(errno == EINTR)
                continue;
            strerror(errno);
            break;
        }

        if(len == 0){
            break;
        }

        while(len>0){
            ret = write(dfd, buf+pos,len);
            while(ret<0){
                if(errno==EINTR){
                    continue;
                }
                printf("%s\n",strerror(errno));
                exit(1);
            }
            
            pos += ret;
            len -= ret;
        }
        close(sfd);
        mytbf_destroy(tbf);
    }
}


