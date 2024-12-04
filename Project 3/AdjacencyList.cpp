#include "AdjacencyList.h"
#include <algorithm>

void AdjacencyList::addEdge(int src, int dest) {
    graph[src].push_back(dest);
}

void AdjacencyList::addNode(int node) {
    if (graph.find(node) == graph.end()) {
        graph[node] = {};
    }
}

void AdjacencyList::deleteNode(int node) {
    graph.erase(node);
    for (auto& pair : graph) {
        auto& neighbors = pair.second;
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), node), neighbors.end());
    }
}

bool AdjacencyList::search(int node) {
    return graph.find(node) != graph.end();
}