#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int main()
{
    int n, source;
    int graph[MAX][MAX];
    int dist[MAX];
    bool visited[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex: ";
    cin >> source;

    // Convert to 0-based indexing
    source--;

    // Initialize distances and visited array
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < n - 1; count++)
    {
        int minDist = INT_MAX;
        int u = -1;

        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Display shortest distances
    cout << "\nShortest distances from source vertex "
         << source + 1 << ":\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i + 1 << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}