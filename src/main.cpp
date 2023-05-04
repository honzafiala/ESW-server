#include <iostream>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <unistd.h>
#include "epollinstance.h"
#include "epollsocket.h"
#include "graph.h"


using namespace std;

int main(int argc, char *argv[])
{

    EpollInstance ep;
    EpollSocket socket(ep, atoi(argv[1]));



    while (1) {
        ep.waitAndHandleEvents();
    }

    return 0;
}
