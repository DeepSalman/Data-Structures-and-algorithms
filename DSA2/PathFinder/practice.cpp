#include <iostream>
#include<stdio.h>
using namespace std;
const int MAXN = 105;
const int MAXE = 10005;
const int INF = 10000;

struct Edge{
    int u,v,w;
};

int n,m;
Edge e[MAXN];
int dist[MAXN],parent[MAXN];

bool bellmanFord(int src){
    for(int i=0;i<n;i++){
        dist[i]=INF;
        parent[i]=-1;
    }
    dist[src]=0;

    for(int j=0;j<n;j++){
        bool changed = false;
        int u=e[j].u;
        int v=e[j].v;
        int w=e[j].w;
        if(dist[u]!=INF && dist[u]+w<dist[v]){
            dist[v]=dist[u]+w;
            parent[v]=u;
            changed= true;
        }
    }
    for(int j=0;j<m;j++){
        int u=e[j].u;
        int v=e[j].v;
        int w=e[j].w;
        if(dist[u]!=INF && dist[u]+w<dist[v]){
            return false;
        }
    }
    return true;
}

