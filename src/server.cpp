/*
    filename: server.cpp
    author: Sitanshu Shrestha at (bit.ly/sitanshu)
    licence: BSD 3-Clause License
*/

#include "iostream"
#include "string"
#include "stdlib.h"
#include "unistd.h"
#include "netdb.h"
#include "cstring"

#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"

#define SA struct sockaddr

int main() {
    int sockfd, connfd;
    unsigned int len;
    struct sockaddr_in servaddr, cli;
   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("ERROR: Socket creation failed...\n");
        exit(0);
    } else {
        printf("STATUS: Socket successfully created..\n");
    }
    bzero(&servaddr, sizeof(servaddr));
   
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5555);
   
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("ERROR: Socket binding failed...\n");
        exit(0);
    } else {
        printf("STATUS!: Socket successfully binded..\n");
    }

    if ((listen(sockfd, 10)) != 0) {
        printf("ERROR: Listen failed...\n");
        exit(0);
    } else {
        printf("STATUS: Server listening..\n");
    }
    len = sizeof(cli);
   
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("ERROR: Server accept failed...\n");
        exit(0);
    } else {
        printf("STATUS!: Server accepted client...\n");
    }

    char* buff;
    int n;
    for (;;) {
        read(connfd, buff, sizeof(buff));
        printf("%s\n", buff);
        write(connfd, buff, sizeof(buff));
   
        if (strncmp("exit", buff, 4) == 0) {
            printf("STATUS!: Exitting...\n");
            break;
        }
    }
    
    close(sockfd);
}