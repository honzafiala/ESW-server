#include "request.h"
#include "stdio.h"
#include <iostream>
#include "graph.h"
#include <map>


#include "proto/messages.pb.h"

using namespace std;



static double dist_squared(pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b) {
    double dx = (double) a.first - (double) b.first;
    double dy = (double) a.second - (double) b.second;
    return dx * dx + dy * dy;
}


static void find_node(int64_t start, int rep, int64_t dst) {
    if (start == -1) return;
    for (int i = 0; i < rep; i++) printf(" ");
    printf("%d\n", start);


    find_node(graph.nodes[start].left, rep + 1, dst);
    find_node(graph.nodes[start].right, rep + 1, dst);
}



void ServerRequest::addWalk(Walk walk) {


    int64_t aId = -1;
    int64_t bId = -1;

    for (int i = 0; i < walk.locations_size() - 1; i++) {
        Point a = {walk.locations(i).x(), walk.locations(i).y()};
        Point b = {walk.locations(i + 1).x(), walk.locations(i + 1).y()};

        aId = bId;
        if (aId < 0) {
            aId = graph.findNear(0, a.x, a.y);
        }
        if (aId < 0) {
            aId = graph.addNode(0, a.x, a.y, true);
        }

        bId = graph.findNear(0, b.x, b.y);
        if (bId < 0) {
            bId = graph.addNode(0, b.x, b.y, true);
        }
        graph.nodes[aId].add_neighbor(walk.lengths(i), bId);
    }



    // int64_t prev_dest = -1;

    // Point a = {walk.locations(0).x(), walk.locations(0).y()};
    // for (int i = 0; i < walk.locations_size() - 1; i++) {

    //     Point a = {walk.locations(i).x(), walk.locations(i).y()};
    //     Point b = {walk.locations(i + 1).x(), walk.locations(i + 1).y()};
    //     int64_t prev_dest = graph.addPoints(a, b, prev_dest, walk.lengths(i));
    // }
}


Response ServerRequest::getResponse(Request requestMessage) {
    Response response;
    response.set_status(Response::OK);
    response.clear_errmsg();

    if (requestMessage.has_walk()) {
        addWalk(requestMessage.walk());
        
        response.set_shortest_path_length(0);
        response.set_total_length(0);
    } else if (requestMessage.has_onetoone()) {
        printf("OnetoOne request.\n"); 
        OneToOne oneToOne = requestMessage.onetoone();

        Point src = {oneToOne.origin().x(), oneToOne.origin().y()};
        Point dst = {oneToOne.destination().x(), oneToOne.destination().y()};

        int64_t srcId = graph.findNear(0, src.x, src.y);
        int64_t dstId = graph.findNear(0, dst.x, dst.y);


        int64_t ret = graph.oneToOne(srcId, dstId);

        printf("Path len: %d\n", ret);

        response.set_shortest_path_length(ret);

        response.set_total_length(0);
    } else if (requestMessage.has_onetoall()) {
        printf("OnetoAll request.\n");
        OneToAll oneToAll = requestMessage.onetoall();

        Point src = {oneToAll.origin().x(), oneToAll.origin().y()};

        int64_t srcId = graph.findNear(0, src.x, src.y);

        int64_t ret = graph.oneToAll(srcId);

        printf("Path len: %ld\n", ret);

        response.set_total_length(ret);

        response.set_shortest_path_length(0);
    }

    return response; 
}


ServerRequest::ServerRequest() {
}




