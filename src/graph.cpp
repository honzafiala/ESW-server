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


    std::vector<uint64_t> dist(nodes.size(), numeric_limits<uint64_t>::max());
    dist[aId] = 0;

    std::vector<int64_t> prev(nodes.size(), -1);
    
    std::vector<bool> closed(nodes.size(), false);



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
        int64_t aId = findNear(0, a.x, a.y);
        if (aId < 0) aId = addNode(0, a.x, a.y, true);
        
        int64_t bId = prev_dest;
        if (bId < 0) bId = findNear(0, b.x, b.y);
        if (bId < 0) bId = addNode(0, b.x, b.y, true);
        int64_t ret = bId;
        nodes[aId].add_neighbor(dist, bId);
  //  m.unlock();
    return ret;
}

int64_t Graph::addNode(int64_t nodeId, uint32_t x, uint32_t y, bool is_x_axis) {
    if (nodes.empty()) {
        nodes.push_back(Node(x, y));
        return nodes.back().id;

    }
    enum side_t {LEFT, RIGHT};
    side_t side;
    int64_t nextNodeId;
    if (is_x_axis) {
        if (x < nodes[nodeId].x) {
            nextNodeId = nodes[nodeId].left;
            side = LEFT;
        } else {
            nextNodeId = nodes[nodeId].right;
            side = RIGHT;
        }
    } else {
        if (y < nodes[nodeId].y) {
            nextNodeId = nodes[nodeId].left;
            side = LEFT;
        } else {
            nextNodeId = nodes[nodeId].right;
            side = RIGHT;
        }
    }

    if (nextNodeId == -1) {
        nodes.push_back(Node(x, y));
        if (side == LEFT) nodes[nodeId].left = nodes.back().id;
        else nodes[nodeId].right = nodes.back().id;
        return nodes.back().id;
    } else {
        addNode(nextNodeId, x, y, !is_x_axis);
    }
    
    // if (*child_ptr == -1) {
    //     nodes.push_back(Node(x, y));
    //     printf("Adding %d %d\n", x, y);
    //     //*child_ptr = nodes.back().id;
    //     printf("-------> right = %d (%p %p)\n", nodes[nodeId].right, &nodes[nodeId].right, child_ptr);
    // } else {
    //     addNode(*child_ptr, x, y, !is_x_axis);
    // }
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

int64_t Graph::findNear(int64_t nodeId, uint32_t x, uint32_t y) {
    int64_t ret = searchTree(nodeId, make_pair(x, y), (double) 500, true);
    return ret;
}
