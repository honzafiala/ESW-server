#ifndef EpollSocket_H
#define EpollSocket_H

#include <sys/epoll.h>
#include <vector>
#include "epollfd.h"
#include "epollinstance.h"
#include "epollconn.h"
#include <list>

class EpollSocket : public EpollFd
{
public:
    EpollSocket(EpollInstance &e, int port);
    ~EpollSocket();
    void handleEvent(uint32_t events);
private:
    EpollInstance &ep;
    std::list<EpollConn *> conns;
};

#endif // EpollSocket_H
