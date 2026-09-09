#include <iostream>
using namespace std;

#define INF 99999

void prim(int cost[][100], int n)
{
    bool visited[100] = {false};
    int minCost[100];
    int parent[100];

    // Initially, all costs are infinity
    for (int i = 0; i < n; i++)
    {
        minCost[i] = INF;
        parent[i] = -1;
    }

    // Start from vertex 0
    minCost[0] = 0;

    int totalCost = 0;

    for (int count = 0; count < n; count++)
    {
        // Find the unvisited vertex with minimum cost
        int u = -1;
        int minimum = INF;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && minCost[i] < minimum)
            {
                minimum = minCost[i];
                u = i;
            }
        }

        // Mark vertex as visited
        visited[u] = true;

        // Update costs of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (cost[u][v] != 0 &&
                !visited[v] &&
                cost[u][v] < minCost[v])
            {
                minCost[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    cout << "Edges in MST:\n";

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << " = " << cost[i][parent[i]] << endl;

        totalCost += cost[i][parent[i]];
    }

    cout << "Total Cost = " << totalCost << endl;
}

int main()
{
    int n;
    cin >> n;

    int cost[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    prim(cost, n);

    return 0;
}