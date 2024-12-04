#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <unordered_map>
#include <vector>
using namespace std;

class AdjacencyMatrix {
public:
    void addEdge(int src, int dest);
    void addNode(int node);
    void deleteNode(int node);
    bool search(int node);

private:
    vector<vector<int>> matrix;
    unordered_map<int, int> nodeIndex;
    int nextIndex = 0;

    void ensureNodeExists(int node);
};

#endif // ADJACENCYMATRIX_H
