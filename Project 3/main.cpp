#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <functional>

using namespace std;

// Tracks method execution time
void measureExecutionTime(const function<void()>& task, const string& taskName) {
    auto start = chrono::high_resolution_clock::now();
    task();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << taskName << " took " << duration << " microseconds" << endl;
}

int main() {
    AdjacencyList adjList;
    AdjacencyMatrix adjMatrix;
    bool usingList = true;

    // Open data file
    ifstream file("100k.csv");
    string line;

    if (!file) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    // Skip first 24 values in header row
    if (getline(file, line)) {
        stringstream ss(line);
        string token;

        for (int i = 0; i < 24; ++i) {
            getline(ss, token, ',');
        }
    }

    // Process the first 1,000 rows (For testing purposes)
    int rowCount = 0;
    while (getline(file, line) && rowCount < 1000) {
        stringstream ss(line);
        string token;
        vector<string> rowData;
        int id;

        if (!getline(ss, token, ',')) continue;

        try {
            id = stoi(token);
        } catch (const invalid_argument&) {
            continue;
        }

        while (getline(ss, token, ',')) {
            rowData.push_back(token);
        }

        auto node = make_shared<Node>(id, rowData);
        adjList.addNode(node);
        adjMatrix.addNode(node);
        rowCount++;
    }

    file.close();
    cout << "Loaded " << rowCount << " rows into the data structures." << endl;

    // Display option menu
    while (true) {
        cout << "\nUsing " << (usingList ? "Adjacency List" : "Adjacency Matrix") << endl;
        cout << "1. Add Node\n2. Delete Node\n3. Search Node\n4. Switch Structure\n5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        // Exit option
        if (choice == 5) break;

        switch (choice) {
            // Add Node
            case 1: {
                cout << "Enter Node ID: ";
                int id;
                cin >> id;

                cout << "Enter additional properties separated by commas: ";
                cin.ignore();
                string properties;
                getline(cin, properties);
                stringstream propStream(properties);

                vector<string> rowData;
                string token;
                while (getline(propStream, token, ',')) {
                    rowData.push_back(token);
                }

                auto node = make_shared<Node>(id, rowData);
                measureExecutionTime(
                        [&]() { usingList ? adjList.addNode(node) : adjMatrix.addNode(node); },
                        "Add Node"
                );
                break;
            }
            // Delete Node
            case 2: {
                cout << "Enter Node ID to delete: ";
                int id;
                cin >> id;
                measureExecutionTime(
                        [&]() { usingList ? adjList.deleteNode(id) : adjMatrix.deleteNode(id); },
                        "Delete Node"
                );
                break;
            }
            // Search Node
            case 3: {
                cout << "Enter Node ID to search: ";
                int id;
                cin >> id;
                measureExecutionTime(
                        [&]() {
                            auto node = usingList ? adjList.searchNode(id) : adjMatrix.searchNode(id);
                            if (node) {
                                cout << "Node found! Details:" << endl;
                                cout << node->toString() << endl;
                            } else {
                                cout << "Node not found" << endl;
                            }
                        },
                        "Search Node"
                );
                break;
            }
            // Switch Data Structure
            case 4:
                usingList = !usingList;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}