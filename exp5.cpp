// Name: Ayush
// roll no. : 25/DA/018
// branch : CSDA

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
int visited[MAX];
int discovery[MAX];
int low[MAX];
int parent[MAX];
bool articulation[MAX];

int timer = 0;
int n;

// DFS function
void DFS(int u){
    visited[u] = 1;

    // Discovery time and low value
    discovery[u] = low[u] = ++timer;

    int children = 0;

    // Check all vertices connected to u
    for (int v = 0; v < n; v++){
        if (graph[u][v] == 1){
            // If v is not visited
            if (!visited[v]){
                parent[v] = u;
                children++;

                DFS(v);

                // Update low value
                low[u] = min(low[u], low[v]);

                // Case 1: u is root of DFS tree
                if (parent[u] == -1 && children > 1)
                    articulation[u] = true;

                // Case 2: u is not root
                if (parent[u] != -1 && low[v] >= discovery[u]) 
                    articulation[u] = true;
            }

            // Back edge
            else if (v != parent[u]){
                low[u] = min(low[u], discovery[v]);
            }
        }
    }
}

int main(){
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    // Initialize arrays
    for (int i = 0; i < n; i++){
        visited[i] = 0;
        parent[i] = -1;
        articulation[i] = false;
    }

    // Perform DFS for all vertices
    for (int i = 0; i < n; i++){
        if (!visited[i])
            DFS(i);
    }

    // Display articulation points
    cout << "\nCut Vertices (Articulation Points):\n";

    bool found = false;

    for (int i = 0; i < n; i++){
        if (articulation[i]){
            cout << "Node " << i << endl;
            found = true;
        }
    }

    if (!found) cout << "No articulation points found.";

    return 0;
}