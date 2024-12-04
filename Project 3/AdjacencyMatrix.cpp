#include "AdjacencyMatrix.h"
#include <algorithm>

void AdjacencyMatrix::resizeMatrix() {
    int size = nodeIndex.size();
    matrix.resize(size);
    for (auto& row : matrix) {
        row.resize(size, 0);
    }
}

void AdjacencyMatrix::addNode(shared_ptr<Node> node) {
    if (nodeIndex.find(node->id) == nodeIndex.end()) {
        int idx = nodeIndex.size();
        nodeIndex[node->id] = idx;
        nodes[node->id] = node;
        resizeMatrix();
    }
}

void AdjacencyMatrix::deleteNode(int id) {
    if (nodeIndex.find(id) != nodeIndex.end()) {
        int idx = nodeIndex[id];
        nodeIndex.erase(id);
        nodes.erase(id);

        for (auto& row : matrix) {
            row.erase(row.begin() + idx);
        }
        matrix.erase(matrix.begin() + idx);
    }
}

bool AdjacencyMatrix::searchNode(int id) {
    return nodeIndex.find(id) != nodeIndex.end();
}