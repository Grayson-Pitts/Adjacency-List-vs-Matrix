#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "Node.h"
#include <unordered_map>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class AdjacencyList {
private:
    unordered_map<int, vector<int>> edges;
    unordered_map<int, shared_ptr<Node>> nodes;

public:
    void addNode(const shared_ptr<Node>& node);
    void deleteNode(int id);
    shared_ptr<Node> searchNode(int id); // Updated to return the node
};

#endif