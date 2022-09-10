/*
    filename: main.cpp
    author: Sitanshu Shrestha at (bit.ly/sitanshu)
    licence: BSD 3-Clause License
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <enc/sha526.hpp>

#define SA struct sockaddr

int main(int argc, char* argv[]) {
    int sockfd, connfd;
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
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(5555);
   
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("ERROR: Connection with the server failed...\n");
        exit(0);
    } else {
        printf("STATUS!: Connected to the server..\n");
        const char* connect_msg = ("usr: %s, pwd: %s = %s ", argv[2], argv[1], (SHA256(argv[1], argv[2])).c_str());
        int connect_msg_len = strlen(connect_msg);
        send(sockfd, connect_msg, connect_msg_len, 0);
    }

    close(sockfd);
} 