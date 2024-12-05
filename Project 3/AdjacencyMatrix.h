#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "Node.h"
#include <unordered_map>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class AdjacencyMatrix {
private:
    vector<vector<bool>> matrix;
    unordered_map<int, int> nodeIndex;
    unordered_map<int, shared_ptr<Node>> nodes;
    int nextIndex;

public:
    AdjacencyMatrix();
    void addNode(shared_ptr<Node> node);
    void deleteNode(int id);
    shared_ptr<Node> searchNode(int id);
};

#endif