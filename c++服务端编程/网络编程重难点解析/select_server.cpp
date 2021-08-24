#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/time.h>
#include <vector>
#include <errno.h>

#define INVALID_FD -1

int main(){
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == INVALID_FD){
        std::cout<<"create listen socket error." << std::endl;
        return -1;
    }

    struct sockaddr_in bindaddr;
    bindaddr.sin_family = AF_INET;
    bindaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bindaddr.sin_port = htons(3000);
    if(bind(listenfd, (struct sockaddr*)&bindaddr,sizeof(bindaddr)) == -1){
        std::cout << "bind listen socket error." << std::endl;
        close(listenfd);
        return -1; 
    }

    if(listen(listenfd, SOMAXCONN) == -1){
        std::cout<<"listen error." << std::endl;
        close(listenfd);
        return -1;
    }

    std::vector<int> clientfds;
    int maxfd;
    while(true){
        fd_set readset;
        FD_ZERO(&readset);

        FD_SET(listenfd, &readset);
        maxfd = listenfd;
        int clientfdslength = clientfds.size();
        for(int i =0;i<clientfdslength;i++){
            if(clientfds[i] != INVALID_FD){
                FD_SET(clientfds[i], &readset);
                if(maxfd < clientfds[i])
                    maxfd = clientfds[i];
            }
        }
        timeval tm;
        tm.tv_sec = 1;
        tm.tv_usec = 0;
        int ret = select(maxfd+1, &readset, NULL, NULL, &tm);
        if(ret==-1){
            if(errno != EINTR)
                break;
        }
        else if(ret==0)
            continue;
        else{
            if(FD_ISSET(listenfd, &readset)){
                struct sockaddr_in clientaddr;
                socklen_t clientaddrlen = sizeof(clientaddr);
                int clientfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientaddrlen);
                if(clientfd == INVALID_FD){
                    break;
                }
                std::cout << "accept a client connection, fd:" << clientfd << std::endl;
                clientfds.push_back(clientfd);
            }
            else{
                char recvbuf[64];
                int clientfdslength = clientfds.size();
                for(int i =0;i<clientfdslength;i++){
                    if(clientfds[i]!=INVALID_FD && FD_ISSET(clientfds[i],&readset)){
                        memset(recvbuf, 0, sizeof(recvbuf));
                        int length = recv(clientfds[i], recvbuf, 64,0);
                        if(length <= 0){
                            std::cout<<"recv data error, clientfd: "<<clientfds[i]<<std::endl;
                            close(clientfds[i]);
                            clientfds[i] = INVALID_FD;
                            continue;
                        }
                        std::cout<<"clientfd: "<<clientfds[i]<<", recv data: "<<recvbuf<<std::endl;
                    }
                }
            }
        }
    }

    int clientfdslength = clientfds.size();
    for(int i =0;i<clientfdslength;i++){
        if(clientfds[i] != INVALID_FD){
            close(clientfds[i]);
        }
    }
    close(listenfd);
    return 0;
}