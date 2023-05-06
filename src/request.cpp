#include "request.h"
#include "stdio.h"
#include <iostream>
#include "graph.h"


#include "proto/messages.pb.h"

using namespace std;

Graph graph;

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
    for (int i = 0; i < walk.locations_size() - 1; i++) {
        printf("-------------------------------------\n");

        Point a = {walk.locations(i).x(), walk.locations(i).y()};
        Point b = {walk.locations(i + 1).x(), walk.locations(i + 1).y()};
        printf("Adding points (%d, %d), (%d, %d) %d\n", a.x, a.y, b.x, b.y, walk.lengths(i));

        graph.addPoints(a, b, walk.lengths(i));
    }
}


Response ServerRequest::getResponse(Request requestMessage) {
    Response response;
    response.set_status(Response::OK);
    response.clear_errmsg();

    if (requestMessage.has_walk()) {
        printf("Walk request.\n");
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


        for (auto node : graph.nodes) {
            if (dist_squared(make_pair(src.x, src.y), make_pair(node.x, node.y)) <= 500 * 500) printf("src close to %d\n", node.id);
            if (dist_squared(make_pair(dst.x, dst.y), make_pair(node.x, node.y)) <= 500 * 500) printf("dst close to %d\n", node.id);
        }



        response.set_shortest_path_length(ret);

        response.set_total_length(0);
    }

    return response; 
}


ServerRequest::ServerRequest() {
}




