#include <stdio.h>

#define MAX 20
#define INF 99999

// ---------- PRIM'S ALGORITHM ----------

void prims(int graph[MAX][MAX], int n)
{
    int selected[MAX] = {0};
    int edges = 0, min, x, y, total = 0;

    selected[0] = 1;

    printf("\nMinimum Spanning Tree using Prim's Algorithm:\n");
    printf("Edge\tWeight\n");

    while (edges < n - 1)
    {
        min = INF;
        x = y = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d\t%d\n", x, y, min);
        total += min;
        selected[y] = 1;
        edges++;
    }

    printf("Total weight = %d\n", total);
}


// ---------- KRUSKAL'S ALGORITHM ----------

struct Edge
{
    int u, v, weight;
};

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int u, int v)
{
    parent[find(u)] = find(v);
}

void kruskal(int graph[MAX][MAX], int n)
{
    struct Edge edges[MAX * MAX];
    int count = 0;

    // Convert adjacency matrix into edge list
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[count].u = i;
                edges[count].v = j;
                edges[count].weight = graph[i][j];
                count++;
            }
        }
    }

    // Sort edges according to weight
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int selectedEdges = 0;
    int total = 0;

    printf("\nMinimum Spanning Tree using Kruskal's Algorithm:\n");
    printf("Edge\tWeight\n");

    for (int i = 0; i < count && selectedEdges < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v))
        {
            printf("%d - %d\t%d\n", u, v, edges[i].weight);

            total += edges[i].weight;
            unionSet(u, v);
            selectedEdges++;
        }
    }

    printf("Total weight = %d\n", total);
}


// ---------- MAIN FUNCTION ----------

int main()
{
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    prims(graph, n);
    kruskal(graph, n);

    return 0;
}