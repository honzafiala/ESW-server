#include <unistd.h>
#include <sys/epoll.h>
#include <cstring>
#include <stdexcept>
#include "epollinstance.h"
#include "epollfd.h"
#include <thread>
#include <iostream>

EpollInstance::EpollInstance()
{
    epollFd = epoll_create1(0);
    if (epollFd == -1) {
        throw std::runtime_error(std::string("epoll_create1: ") + std::strerror(errno));
    }
}

EpollInstance::~EpollInstance()
{
    close(epollFd);
}

void EpollInstance::registerFd(EpollFd &fd, uint32_t events)
{
    struct epoll_event ev;
    memset(&ev, 0, sizeof(ev));

    ev.events = events;
    ev.data.ptr = &fd;

    if (epoll_ctl(epollFd, EPOLL_CTL_ADD, fd.fd, &ev) == -1) {
        throw std::runtime_error(std::string("epoll_ctl: ") + std::strerror(errno));
    }
}

void EpollInstance::unregisterFd(EpollFd &fd)
{
    struct epoll_event ev;
    memset(&ev, 0, sizeof(ev));

    ev.events = 0;
    ev.data.ptr = &fd;

    if (epoll_ctl(epollFd, EPOLL_CTL_DEL, fd.fd, &ev) == -1) {
        throw std::runtime_error(std::string("epoll_ctl: ") + std::strerror(errno));
    }
}

void EpollInstance::waitAndHandleEvents()
{
    struct epoll_event events[EPOLL_MAX_EVENTS];
    int i, n;
    n = epoll_wait(epollFd, events, EPOLL_MAX_EVENTS, -1);
    std::cout << "Thread " << std::this_thread::get_id() << ": " << n << " events" << std::endl;
    if (n == -1) {
        throw std::runtime_error(std::string("epoll_wait: ") + std::strerror(errno));
    }
    for (i = 0; i < n; i++) {
        EpollFd *fd = static_cast<EpollFd *>(events[i].data.ptr);
        fd->handleEvent(events[i].events);
    }
}
