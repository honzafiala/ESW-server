#ifndef GRAPH_H
#define GRAPH_H


#include <cstdint>
#include <map>
#include <vector>
#include <shared_mutex>

struct Edge {
    int64_t dist;
    int count;
};

struct Point {
    uint32_t x;
    uint32_t y;

    Point(uint32_t x_param, uint32_t y_param) : x(x_param), y(y_param) {}

};

class Node {
public:
    int64_t id;
    static int64_t id_count;
    uint32_t x, y;
    int64_t left;
    int64_t right;
    std::map<uint64_t, Edge> neighbors;

    Node(uint32_t x_val, uint32_t y_val) : x(x_val), y(y_val), left(-1), right(-1) {
       // m.lock();
        id = id_count++;
       // m.unlock();
    }

    void add_neighbor(uint32_t dist, int64_t neighbor_id) {
        if (neighbors.count(neighbor_id)) {
            Edge edge = neighbors[neighbor_id];
            neighbors[neighbor_id].dist = edge.dist + dist;
            neighbors[neighbor_id].count = edge.count + 1;
        } else {
            neighbors[neighbor_id] = {dist, 1};
        }
    }

    
};

class Graph {
public:
    Graph();
    std::vector<Node> nodes;
    int64_t addNode(int64_t nodeId, uint32_t x, uint32_t y, bool is_x_axis);
    void printTRee(int64_t nodeId);
    int64_t findNear(int64_t nodeId, uint32_t x, uint32_t y);
    int64_t searchTree(int64_t nodeId, std::pair<uint32_t, uint32_t> point, double distance_threshold, bool x_axis);
    void addPoints(Point a, Point b, int32_t dist);
    uint64_t oneToOne(int64_t aId, int64_t bId);
    int64_t oneToAll(int64_t aId);
    std::shared_mutex m;

};

#endif // GRAPH_H