#include "AdjacencyList.h"

void AdjacencyList::addNode(const shared_ptr<Node>& node) {
    int id = node->getId();
    if (nodes.find(id) == nodes.end()) {
        nodes[id] = node;
        edges[id] = {};
    }
}

void AdjacencyList::deleteNode(int id) {
    if (nodes.find(id) != nodes.end()) {
        nodes.erase(id);
        edges.erase(id);

        for (auto& pair : edges) {
            vector<int>& neighbors = pair.second;
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), id), neighbors.end());
        }
    }
}

shared_ptr<Node> AdjacencyList::searchNode(int id) {
    if (nodes.find(id) != nodes.end()) {
        return nodes[id];
    }
    return nullptr; // Node not found
}