#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <unordered_map>
#include <vector>
using namespace std;

class AdjacencyList {
public:
    void addEdge(int src, int dest);
    void addNode(int node);
    void deleteNode(int node);
    bool search(int node);

private:
    unordered_map<int, vector<int>> graph;
};

#endif // ADJACENCYLIST_H
