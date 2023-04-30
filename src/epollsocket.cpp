#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "epollsocket.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

EpollSocket::EpollSocket(EpollInstance &e, int port) : EpollFd(-1, e), ep(e)
{
    printf("Binding to port %d\n", port);

        int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd < 0){
        printf("Error while creating socket\n");
    }

    struct sockaddr_in receive_addr;
    receive_addr.sin_family = AF_INET;
    receive_addr.sin_port = htons(port);
    receive_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sfd, (struct sockaddr*)&receive_addr, sizeof(receive_addr)) < 0){
        printf("Couldn't bind to the port\n");
    }


    /*
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in saddr;

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family      = AF_INET;              // IPv4
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);    // Bind to all available interfaces
    saddr.sin_port        = htons(port);          // Requested port
 
    int ret = bind(sfd, (struct sockaddr *) &saddr, sizeof(saddr));
    printf("Bind %d\n", ret);

    */

    int ret = listen(sfd, SOMAXCONN);

    fd = sfd;
    registerFd(EPOLLIN | EPOLLHUP);
}

EpollSocket::~EpollSocket()
{
    unregisterFd();
}

void EpollSocket::handleEvent(uint32_t events)
{
    std::string line;
    if ((events & EPOLLERR) || (events & EPOLLHUP) || !(events & EPOLLIN)) {
        unregisterFd();
    } else {
    int cfd = accept4(fd, NULL, NULL, O_NONBLOCK);
    printf("New connection: %cfd!\n");
    EpollConn * conn = new EpollConn(cfd, ep);
    }
}
