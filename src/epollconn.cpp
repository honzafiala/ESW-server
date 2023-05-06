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
#include <cerrno>

#include "proto/messages.pb.h"

#include "request.h"


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

uint32_t total_read = 0;

void EpollConn::handleEvent(uint32_t events)
{
    #define BUF_SIZE 1024
    static char buffer[BUF_SIZE];
    if (events > 1) {
        unregisterFd();
        delete this;
    } else {


        while (true) {

        uint32_t messageSize;
        int rec = read(fd, (void *) &messageSize, 4);
        

        if (rec < 0) {
            printf("Rec = %d, total: %d!\n", rec, total_read);
            exit(0);
        } else {
            total_read += rec;
        }

        if (rec == 0) {
            printf("EOF!\n");
            return;
        }


        messageSize = htonl(messageSize);
        printf("Message size: %d\n", messageSize);


        std::string messageBuffer(messageSize, 0);
        rec = read(fd, &messageBuffer[0], messageSize);
        printf("Received: %d, errno: %d\n", rec, errno);

        if (rec < 0) {
            printf("Rec = %d, total: %d!\n", rec, total_read);
            exit(0);
        } else {
            total_read += rec;
        }
      

        Request request;
        request.ParseFromString(messageBuffer);

        ServerRequest serverRequest;

        Response response = serverRequest.getResponse(request);
        
        }

    }
}
