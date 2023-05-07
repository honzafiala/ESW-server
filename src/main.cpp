#include <iostream>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <unistd.h>
#include "epollinstance.h"
#include "epollsocket.h"
#include "graph.h"

#include <thread>
#include <vector>

using namespace std;

void threadFunction(int threadId) {

}



int main(int argc, char *argv[])
{
    if (argc < 3) {
        cout << "PORT_NUM and NUM_THREADS arguments required." << endl;
        return 1;
    }

    EpollInstance ep;
    EpollSocket socket(ep, atoi(argv[1]));

    //  std::vector<std::thread> threads; // Vector to store thread objects

    // for (int i = 0; i < atoi(argv[2]); ++i) {
    //     threads.emplace_back(threadFunction, i);
    // }

    // // Wait for all threads to finish
    // for (auto& thread : threads) {
    //     thread.join();
    // }

        while (1) {
        ep.waitAndHandleEvents();
    }

    return 0;
}
