#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "Node.h"
#include <unordered_map>
#include <vector>
#include <memory>

class AdjacencyMatrix {
private:
    unordered_map<int, shared_ptr<Node>> nodes;
    unordered_map<int, int> nodeIndex;
    vector<vector<int>> matrix;

    void resizeMatrix();

public:
    void addNode(shared_ptr<Node> node);
    void deleteNode(int id);
    bool searchNode(int id);
};

#endif // ADJACENCYMATRIX_H