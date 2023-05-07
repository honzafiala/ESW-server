#ifndef EpollConn_H
#define EpollConn_H

#include <sys/epoll.h>
#include <string>
#include "epollfd.h"
#include "epollinstance.h"

#include "proto/messages.pb.h"


class TCPConnection : public EpollFd
{
public:
    TCPConnection(int cfd, EpollInstance &e);
    ~TCPConnection();
    void handleEvent(uint32_t events);
private:
    int prev = 0;
    uint32_t messageSize = 0;
    int readData = 0;
    std::string messageBuffer;
    void sendResponse(Response responseMessage);
};

#endif // EpollConn_H
