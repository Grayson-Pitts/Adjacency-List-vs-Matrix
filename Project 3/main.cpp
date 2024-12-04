#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <functional>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

using namespace std;
using namespace std::chrono;

void readData(const string& filename, AdjacencyList& adjList, AdjacencyMatrix& adjMatrix) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int src, dest;
        char comma;
        ss >> src >> comma >> dest;
        adjList.addEdge(src, dest);
        adjMatrix.addEdge(src, dest);
    }
}

void measureExecutionTime(const function<void()>& task, const string& taskName) {
    auto start = high_resolution_clock::now();
    task();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << taskName << " took " << duration << " microseconds" << endl;
}

void menu() {
    cout << "\nOptions:\n";
    cout << "1. Add a node\n";
    cout << "2. Delete a node\n";
    cout << "3. Search for a node\n";
    cout << "4. Switch to the other data structure\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    AdjacencyList adjList;
    AdjacencyMatrix adjMatrix;

    string filename = "data/100k.csv"; // Ensure the file is in the working directory
    readData(filename, adjList, adjMatrix);

    bool usingList = true;
    int choice;

    do {
        cout << "\nCurrently using: " << (usingList ? "Adjacency List" : "Adjacency Matrix") << "\n";
        menu();

        while (!(cin >> choice)) {  // Handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid option: ";
        }

        int node;
        switch (choice) {
            case 1:
                cout << "Enter node to add: ";
                cin >> node;
                measureExecutionTime(
                        [&]() { usingList ? adjList.addNode(node) : adjMatrix.addNode(node); },
                        "Add node"
                );
                break;
            case 2:
                cout << "Enter node to delete: ";
                cin >> node;
                measureExecutionTime(
                        [&]() { usingList ? adjList.deleteNode(node) : adjMatrix.deleteNode(node); },
                        "Delete node"
                );
                break;
            case 3:
                cout << "Enter node to search: ";
                cin >> node;
                measureExecutionTime(
                        [&]() {
                            cout << "Node " << (usingList
                                                ? (adjList.search(node) ? "found" : "not found")
                                                : (adjMatrix.search(node) ? "found" : "not found"))
                                 << endl;
                        },
                        "Search for node"
                );
                break;
            case 4:
                usingList = !usingList;
                cout << "Switched to " << (usingList ? "Adjacency List" : "Adjacency Matrix") << "\n";
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}