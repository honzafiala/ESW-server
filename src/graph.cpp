#include <cstdint>
#include <iostream>
#include "stdio.h"

#include "math.h"

#include "graph.h"

#include <limits>
#include <queue>

using namespace std;


int64_t Node::id_count = 0;


static double dist_squared(pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b) {
    double dx = (double) a.first - (double) b.first;
    double dy = (double) a.second - (double) b.second;
    return dx * dx + dy * dy;
}



Graph::Graph() {
   printf("Created a graph instance\n");
}

struct PathNode {
    int nodeId;
    uint64_t distance;

    PathNode(int64_t id, int64_t dist) : nodeId(id), distance(dist) {}

    bool operator>(const PathNode& other) const {
        return distance > other.distance;
    }
};


int64_t Graph::oneToAll(int64_t aId) {
  //  m.lock_shared();

    std::vector<uint64_t> dist(nodes.size(), static_cast<uint64_t>(std::numeric_limits<uint64_t>::max()));
    dist[aId] = 0;

    std::priority_queue<PathNode, std::vector<PathNode>, std::greater<>> pq;
    pq.push(PathNode(aId, 0));



    while (!pq.empty()) {
        PathNode u = pq.top();
        pq.pop();

        for (auto v : nodes[u.nodeId].neighbors) {
            int64_t vId = v.first;
            int64_t alt = u.distance + v.second.dist / v.second.count;
            if (alt < dist[vId]) {
                pq.push(PathNode(vId, alt));
                dist[vId] = alt;
               // printf("Setting %d to %d\n", vId, alt);
            }
        }
    }

   // m.unlock_shared();

    int64_t ret = 0;
    for (auto d : dist){
        if (d < std::numeric_limits<uint64_t>::max()) {
            ret += d;
            //printf("ret = %ld\n", ret);
        }
    }
    
    return ret;
}



uint64_t Graph::oneToOne(int64_t aId, int64_t bId) {
   // m.lock_shared();


    std::vector<uint64_t> dist(nodeCount, numeric_limits<uint64_t>::max());
    dist[aId] = 0;

    std::vector<int64_t> prev(nodeCount, -1);
    
    std::vector<bool> closed(nodeCount, false);



    std::priority_queue<PathNode, std::vector<PathNode>, std::greater<>> pq;
    pq.push(PathNode(aId, 0));
    

    while (!pq.empty()) {
        
        PathNode u = pq.top();
        pq.pop();

        if (u.nodeId == bId) break;

        for (auto v : nodes[u.nodeId].neighbors) {
            int64_t vId = v.first;
            int alt = u.distance + v.second.dist / v.second.count;; 
            if (alt < dist[vId]) {
                pq.push(PathNode(vId, alt));
                dist[vId] = alt;
                prev[vId] = u.nodeId;
            }
        }
    }
   // m.unlock_shared();

   
    
    return dist[bId];
}




int64_t Graph::addPoints(Point a, Point b, int64_t prev_dest, int32_t dist) {
   // m.lock();
        int64_t aId = findNear(a.x, a.y);
        if (aId < 0) aId = addNode(0, a.x, a.y, true);
        
        int64_t bId = prev_dest;
        if (bId < 0) bId = findNear(b.x, b.y);
        if (bId < 0) bId = addNode(0, b.x, b.y, true);
        int64_t ret = bId;
        nodes[aId].add_neighbor(dist, bId);
  //  m.unlock();
    return ret;
}

int64_t Graph::addNode(int64_t nodeId, uint32_t x, uint32_t y, bool is_x_axis) {
    if (nodes_map.count(Point(x / 500, y / 500)) == 0) {
        printf("Tile %d %d is empty\n", x / 500, y / 500);
        nodes_map.insert(make_pair(Point(x / 500, y / 500), std::vector<Node>()));
        nodes_map[Point(x / 500, y / 500)].emplace_back(Node(x, y));
    }
        else nodes_map[Point(x / 500, y / 500)].emplace_back(Node(x, y));
    nodeCount++;
}

void Graph::printTRee(int64_t nodeId) {
    if (nodeId < 0 || nodeId >= nodes.size()) return;
    printf("%d\t%d\n", nodes[nodeId].x, nodes[nodeId].y);
    printTRee(nodes[nodeId].left);
    printTRee(nodes[nodeId].right);
}

int64_t Graph::searchTree(int64_t nodeId, pair<uint32_t, uint32_t> point, double distance_threshold, bool x_axis) {
    if (nodeId == -1 || nodes.empty()) {
        return - 1;
    }
    double dist = dist_squared(point, make_pair(nodes[nodeId].x, nodes[nodeId].y));
    if (dist <= distance_threshold * distance_threshold) {
        return nodeId;
    } 

    int64_t ret = -1;
    if (x_axis) {
        if (point.first - distance_threshold <= nodes[nodeId].x) {
            ret = searchTree(nodes[nodeId].left, point, distance_threshold, !x_axis);
        }
        if (point.first + distance_threshold >= nodes[nodeId].x) {
            if (ret == - 1) ret = searchTree(nodes[nodeId].right, point, distance_threshold, !x_axis);
        }
    } else {
       if (point.second - distance_threshold <= nodes[nodeId].y) {
            ret = searchTree(nodes[nodeId].left, point, distance_threshold, !x_axis);
        }
        if (point.second + distance_threshold >= nodes[nodeId].y) {
            if (ret == - 1) ret = searchTree(nodes[nodeId].right, point, distance_threshold, !x_axis);
        }
    }
    return ret;
}

int64_t Graph::findNear(uint32_t x, uint32_t y) {
   for (int x_move = -1; x_move <= 1; x_move++) {
        for (int y_move = -1; y_move <= 1; y_move++) {
            //if (nodes_map.count(Point(x /500 + x_move, y /500 + y_move)) == 0) continue;
            printf("Tile %d %d:\n", x / 500 + x_move, y / 500 + y_move);
            for (auto n : nodes_map[Point(x / 500 + x_move, y / 500 + y_move)]) {
                printf("    %d %d %f\n", n.x, n.y, dist_squared(make_pair(x, y), make_pair(n.x, n.y)));
                if (dist_squared(make_pair(x, y), make_pair(n.x, n.y)) < 500 * 500) {
                    printf("Fount point near: %d %d\n", n.x, n.y);
                    return n.id;
                }
            }
        }
   }
   return -1;
}
