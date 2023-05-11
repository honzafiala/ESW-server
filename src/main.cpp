#include <iostream>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <unistd.h>
#include "epollinstance.h"
#include "epollsocket.h"
#include "graph.h"

#include <thread>
#include <vector>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>


using namespace std;

EpollInstance ep;


void threadFunction(int threadId) {
    while (1) {
        ep.waitAndHandleEvents();
    }
}


// void create_socket(int port_number) {
//     printf("Binding to port %d\n", port);

//         int sfd = socket(AF_INET, SOCK_STREAM, 0);
//     if(sfd < 0){
//         printf("Error while creating socket\n");
//     }

//     struct sockaddr_in receive_addr;
//     receive_addr.sin_family = AF_INET;
//     receive_addr.sin_port = htons(port);
//     receive_addr.sin_addr.s_addr = INADDR_ANY;

//     if(bind(sfd, (struct sockaddr*)&receive_addr, sizeof(receive_addr)) < 0){
//         printf("Couldn't bind to the port\n");
//     }
//     listen(sfd, SOMAXCONN);
//     return sfd;
// }



int main(int argc, char *argv[])
{
    if (argc < 3) {
        cout << "PORT_NUM and NUM_THREADS arguments required." << endl;
        return 1;
    }

    EpollSocket socket(ep, atoi(argv[1]));



    // Graph test;
    // test.addNode(0, 1100, 1000, true);
    // test.addNode(0, 400, 550, true);

    // for (auto pair : test.nodes_map) {
    //     printf("%d %d---------------\n", pair.first.x, pair.first.y);
    //     for (auto n : pair.second) {
    //         printf("%d\t%d %d\n", n.id, n.x, n.y);
    //     }
    // }

    // uint64_t id = test.findNear(510, 510);
    // printf("Found: %d\n", id);
    // printf("%d\n", test.nodeCount);
    // while (1);

  //   std::vector<std::thread> threads; // Vector to store thread objects

    // for (int i = 0; i < atoi(argv[2]); ++i) {
    //     threads.emplace_back(threadFunction, i);
    // }

    // // Wait for all threads to finish
    // for (auto& thread : threads) {
    //     thread.join();
    // }

   // int socket_fd = create_socket(atoi(argv[2]));


   // registerFd(EPOLLIN | EPOLLHUP);


     while (1) {
     ep.waitAndHandleEvents();
 }

    return 0;
}
