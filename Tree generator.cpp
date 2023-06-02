#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<vector<int>> adj;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void generateRandomTree(int n) {
    adj.resize(n + 1);  // Resize the adjacency list to accommodate 'n' vertices

    srand(time(0));  // Seed the random number generator

    int root = rand() % n + 1;  // Randomly select the root node

    // Connect each vertex to a randomly selected parent (except for the root vertex)
    for (int i = 2; i <= n; i++) {
        int parent = rand() % (i - 1) + 1;
        addEdge(parent, i);
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices (n): ";
    cin >> n;

    generateRandomTree(n);

    // Print the generated tree
    cout << "Generated Tree:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
