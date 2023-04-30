#ifndef EpollConn_H
#define EpollConn_H

#include <sys/epoll.h>
#include "epollfd.h"
#include "epollinstance.h"

class EpollConn : public EpollFd
{
public:
    EpollConn(int cfd, EpollInstance &e);
    ~EpollConn();
    void handleEvent(uint32_t events);
private:
    int prev = 0;
};

#endif // EpollConn_H
