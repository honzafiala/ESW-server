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

#include "graph.h"

#include <algorithm>    // std::find

TCPConnection::TCPConnection(int cfd, EpollInstance &e) : EpollFd(-1, e)
{
    fd = cfd;
    //registerFd(EPOLLIN | EPOLLET);
    registerFd(EPOLLIN | EPOLLET);
    printf("New TCPConnection created\n");

    Graph::startTime = std::chrono::high_resolution_clock::now();
}

TCPConnection::~TCPConnection()
{
    // unregisterFd();
    // printf("delete this\n");
    // delete this;
}

void send_len(int fd, int len) {
    char msg[10];
    sprintf(msg, "%d\n", len);
    write(fd, msg, strlen(msg));
}

uint32_t total_read = 0;

void TCPConnection::sendResponse(Response responseMessage) {
    std::string serializedMessage;
    responseMessage.SerializeToString(&serializedMessage);

    uint32_t responseSize = htonl(serializedMessage.size());
    write(fd, (void *) &responseSize, sizeof(responseSize));

    write(fd, serializedMessage.c_str(), serializedMessage.size());
}



int get_depth(int64_t nodeId) {
    if (nodeId == -1) return -1;
    else if (graph.nodes[nodeId].right == -1 && graph.nodes[nodeId].left == -1) return 0;

    else {
        int left_depth = get_depth(graph.nodes[nodeId].left);
        int right_depth = get_depth(graph.nodes[nodeId].right);
        return left_depth > right_depth ? left_depth + 1: right_depth + 1;
    }
}


void TCPConnection::handleEvent(uint32_t events)
{
    printf("\nEvents: %d\n", events);
    if (events > 1) {
        close:
        unregisterFd();
        close(fd);
        printf("Closing connection\n");


        auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
   // std::chrono::duration<double> duration = end - Graph::startTime;

    // Print the execution time
    //std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

  // printf("Maximum graph depth: %d\n", get_depth(0));
  //  printf("Number of nodes: %d\n", graph.nodes.size());



        delete this;
    } else {

        static int total = 0;
        int rec;
        while (true) {
            if (readData == messageSize && messageSize != 0) {
              //  printf("Received request with size %d\n", messageSize);
                readData = 0;
                messageSize = 0;

                Request request;
                request.ParseFromString(messageBuffer);
                ServerRequest serverRequest;
                graph.m.lock();
                Response response = serverRequest.getResponse(request);
                graph.m.unlock();

                sendResponse(response);

            }
            if (messageSize == 0) {
                rec = read(fd, (void *) &messageSize, 4);
                if (rec == 0) goto close;
                if (rec <= 0) return;
                total += rec;
                messageSize = ntohl(messageSize);
                readData = 0;
               // printf("Size: %d\n", messageSize);
            } 
            if (readData < messageSize) {
                if (readData == 0) messageBuffer.resize(messageSize);
                rec = read(fd, &messageBuffer[readData], messageSize - readData);
                if (rec == 0) goto close;
                if (rec <= 0) return;
                total += rec;
                readData += rec;
               // printf("Read %d, %d\n", rec, total);
            }
        }
    }
}
