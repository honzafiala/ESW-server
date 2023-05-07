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

TCPConnection::TCPConnection(int cfd, EpollInstance &e) : EpollFd(-1, e)
{
    fd = cfd;
    //registerFd(EPOLLIN | EPOLLET);
    registerFd(EPOLLIN | EPOLLET);
    printf("New TCPConnection created\n");
}

TCPConnection::~TCPConnection()
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

void TCPConnection::handleEvent(uint32_t events)
{
    printf("\nEvents: %d\n", events);
    if (events > 1) {
        unregisterFd();
        printf("Closing connection\n");
        delete this;
    } else {

        static int total = 0;
        int rec;
        while (true) {
            if (readData == messageSize && messageSize != 0) {
                printf("Received request with size %d\n", messageSize);
                readData = 0;
                messageSize = 0;

                Request request;
                request.ParseFromString(messageBuffer);
                ServerRequest serverRequest;
                Response response = serverRequest.getResponse(request);

            }
            if (messageSize == 0) {
                rec = read(fd, (void *) &messageSize, 4);
                if (rec == 0) printf("EOF\n");
                if (rec <= 0) return;
                total += rec;
                messageSize = htonl(messageSize);
                readData = 0;
               // printf("Size: %d\n", messageSize);
            } 
            if (readData < messageSize) {
                if (readData == 0) messageBuffer.resize(messageSize);
                rec = read(fd, &messageBuffer[readData], messageSize - readData);
                if (rec == 0) printf("EOF\n");
                if (rec <= 0) return;
                total += rec;
                readData += rec;
               // printf("Read %d, %d\n", rec, total);
            }
        }

        // This handler should call read() until no more data are available (until -1 is returned by the function).
        // The handler is only called agan when more data is available in EPOLLET mode, so it will not be called 
        // again when not all data are read when the handler is called.


        // std::string messageBuffer(messageSize, 0);
        // rec = read(fd, &messageBuffer[0], messageSize);
        // printf("Received: %d, errno: %d\n", rec, errno);

        // if (rec < 0) {
        //     printf("Rec = %d, total: %d!\n", rec, total_read);
        //     exit(0);
        // } else {
        //     total_read += rec;
        // }
      

        // Request request;
        // request.ParseFromString(messageBuffer);

        // ServerRequest serverRequest;

        // Response response = serverRequest.getResponse(request);
        

    }
}
