#include "AdjacencyList.h"

void AdjacencyList::addNode(shared_ptr<Node> node) {
    nodes[node->id] = node;
}

void AdjacencyList::deleteNode(int id) {
    nodes.erase(id);
    edges.erase(id);

    for (auto& pair : edges) {
        auto& neighbors = pair.second;
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), id), neighbors.end());
    }
}

bool AdjacencyList::searchNode(int id) {
    return nodes.find(id) != nodes.end();
}