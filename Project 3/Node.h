#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Node {
private:
    int id;
    vector<string> properties;
    const char* propertyNames[23] = {"click","hour","C1","banner_pos","site_id","site_domain","site_category","app_id",
                                     "app_domain","app_category","device_id","device_ip","device_model","device_type",
                                     "device_conn_type","C14","C15","C16","C17","C18","C19","C20","C21"};

public:
    Node(int id, const vector<string>& properties)
            : id(id), properties(properties) {}

    // Returns Node ID
    int getId() const {
        return id;
    }

    // Converts properties to strings to be displayed (Search Node option)
    string toString() const {
        stringstream ss;
        ss << "ID: " << id << endl;

        for (size_t i = 0; i < properties.size(); ++i) {
            ss << propertyNames[i] << ": " << properties[i] << "\n";
        }

        return ss.str();
    }
};

#endif