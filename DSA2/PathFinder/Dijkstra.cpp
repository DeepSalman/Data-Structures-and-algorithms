#include <iostream>
using namespace std;

const int MAXN = 105;
const int INF = 1000000000;

int n, m;
int adj[MAXN][MAXN];
int dist[MAXN], parent[MAXN];
bool visited[MAXN];

void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == INF || visited[v]) continue;
            if (dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }
}

void printPath(int v) {
    if (parent[v] != -1) {
        printPath(parent[v]);
    }
    cout << char('A' + v) << " ";
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w; // Remove this line for one-way roads
    }

    dijkstra(0);

    for (int v = 0; v < n; v++) {
        cout << char('A' + v) << " = ";
        cout << dist[v] << " : ";
        printPath(v);
        cout << "\n";
    }

    return 0;
}