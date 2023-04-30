#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "epollconn.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

#include "proto/messages.pb.h"


#include <algorithm>    // std::find

EpollConn::EpollConn(int cfd, EpollInstance &e) : EpollFd(-1, e)
{
    fd = cfd;
    registerFd(EPOLLIN | EPOLLET);
}

EpollConn::~EpollConn()
{
    unregisterFd();
    printf("delete this\n");
    delete this;
}

void send_len(int fd, int len) {
    char msg[10];
    sprintf(msg, "%d\n", len);
    write(fd, msg, strlen(msg));
}



void EpollConn::handleEvent(uint32_t events)
{
    #define BUF_SIZE 1024
    static char buffer[BUF_SIZE];
    if (events > 1) {
        unregisterFd();
        delete this;
    } else {
        uint32_t messageSize;
        int rec = read(fd, (void *) &messageSize, 4);
        messageSize = htonl(messageSize);
        printf("Message size: %d\n", messageSize);

        std::string messageBuffer(messageSize, 0);
        read(fd, &messageBuffer[0], messageSize);

        Request request;
        request.ParseFromString(messageBuffer);

        Walk walk = request.walk();

        for (int i = 0; i < walk.locations_size(); i++) 
            printf("%d %d\n", walk.locations(i).x(), walk.locations(i).y());

        int count = read(fd, buffer, BUF_SIZE-1);
        printf("Read: %.*s\n", count, buffer);
        for (int i = 0; i < count; i++) {
            if (buffer[i] == '\n') {
                send_len(fd, prev);
                prev = 0;
            }
            else prev++;
        }
    }
}
