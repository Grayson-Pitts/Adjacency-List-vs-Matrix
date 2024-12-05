#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix() : nextIndex(0) {}

void AdjacencyMatrix::addNode(shared_ptr<Node> node) {
    int id = node->getId();
    if (nodeIndex.find(id) == nodeIndex.end()) {
        nodeIndex[id] = nextIndex++;
        nodes[id] = node;

        for (auto& row : matrix) {
            row.push_back(false);
        }
        matrix.push_back(vector<bool>(nextIndex, false));
    }
}

void AdjacencyMatrix::deleteNode(int id) {
    if (nodeIndex.find(id) != nodeIndex.end()) {
        int idx = nodeIndex[id];
        nodeIndex.erase(id);
        nodes.erase(id);

        for (auto& row : matrix) {
            row[idx] = false;
        }
        matrix[idx] = vector<bool>(nextIndex, false);
    }
}

shared_ptr<Node> AdjacencyMatrix::searchNode(int id) {
    if (nodes.find(id) != nodes.end()) {
        return nodes[id];
    }
    return nullptr; // Node not found
}