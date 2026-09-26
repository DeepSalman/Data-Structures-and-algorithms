#include <iostream>
using namespace std;

const int MAXN = 105;
const int MAXE = 10005;
const int INF = 1000000000;

struct Edge {
    int u, v, w;
};

int n, m;
Edge e[MAXE];
int dist[MAXN], parent[MAXN];

bool bellmanFord(int src) {
    // Step 1: Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Step 2: Relax all edges (V - 1) times
    for (int pass = 1; pass <= n - 1; pass++) {
        bool changed = false;
        for (int j = 0; j < m; j++) {
            int u = e[j].u, v = e[j].v, w = e[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                changed = true;
            }
        }
        // Early stop if no update occurred in this pass
        if (!changed) break;
    }

    // Step 3: Check for negative-weight cycles (Pass V)
    for (int j = 0; j < m; j++) {
        int u = e[j].u, v = e[j].v, w = e[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false; // Reachable negative cycle found
        }
    }

    return true;
}

int main() {
    cin >> n >> m;
    for (int j = 0; j < m; j++) {
        cin >> e[j].u >> e[j].v >> e[j].w;
    }

    if (!bellmanFord(0)) {
        cout << "Negative cycle found\n";
        return 0;
    }

    for (int v = 0; v < n; v++) {
        cout << char('A' + v) << " = ";
        if (dist[v] == INF) 
            cout << "INF\n";
        else 
            cout << dist[v] << "\n";
    }

    return 0;
}