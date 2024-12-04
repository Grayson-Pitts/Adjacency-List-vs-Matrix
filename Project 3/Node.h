#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

struct Node {
    int id;
    vector<string> data;

    Node(int id, const vector<string>& data) : id(id), data(data) {}
};

#endif // NODE_H