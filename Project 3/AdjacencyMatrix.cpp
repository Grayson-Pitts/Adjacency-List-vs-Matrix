#include "AdjacencyMatrix.h"

void AdjacencyMatrix::addEdge(int src, int dest) {
    ensureNodeExists(src);
    ensureNodeExists(dest);
    matrix[nodeIndex[src]][nodeIndex[dest]] = 1;
}

void AdjacencyMatrix::addNode(int node) {
    if (nodeIndex.find(node) == nodeIndex.end()) {
        nodeIndex[node] = nextIndex++;
        for (auto& row : matrix) {
            row.push_back(0);
        }
        matrix.push_back(vector<int>(matrix.size() + 1, 0));
    }
}

void AdjacencyMatrix::deleteNode(int node) {
    if (nodeIndex.find(node) == nodeIndex.end()) return;
    int index = nodeIndex[node];
    for (auto& row : matrix) {
        row.erase(row.begin() + index);
    }
    matrix.erase(matrix.begin() + index);
    nodeIndex.erase(node);
    for (auto& pair : nodeIndex) {
        if (pair.second > index) --pair.second;
    }
    --nextIndex;
}

bool AdjacencyMatrix::search(int node) {
    return nodeIndex.find(node) != nodeIndex.end();
}

void AdjacencyMatrix::ensureNodeExists(int node) {
    if (nodeIndex.find(node) == nodeIndex.end()) {
        addNode(node);
    }
}