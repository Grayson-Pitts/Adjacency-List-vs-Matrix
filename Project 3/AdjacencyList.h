#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "Node.h"
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>

class AdjacencyList {
private:
    unordered_map<int, shared_ptr<Node>> nodes;
    unordered_map<int, vector<int>> edges;

public:
    void addNode(shared_ptr<Node> node);
    void deleteNode(int id);
    bool searchNode(int id);
};

#endif // ADJACENCYLIST_H