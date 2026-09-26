#include<iostream>
#include<vector>
#include<climits>

using namespace std;

const int INF = INT_MAX;

int n;
vector<vector<int>> adj;
vector<int> dist;
vector<int> parent;
vector<bool> visited;

void dijkstra(int src){

    for(int i=0;i<n;i++){
        dist[i]=INF;
        parent[i]=-1;
        visited[i]=false;
    }

    dist[src]=0;

    for(int steps=0;steps<n;steps++){
        int u=-1;
        for(int i=0;i<n;i++){
            if(!visited[i]&& (u==-1||dist[i]<dist[u])){
                u = i;
            }
        }

        if(u==-1||dist[u]==INF){
            break;
        }

        visited[u]=true;

        for(int v=0;v<n;v++){
            if(adj[u][v]==INF || visited[v]){
                continue;
            }

            if(dist[u]+adj[u][v]<dist[v]){
                dist[v]=dist[u]+adj[u][v];
                parent[v]=u;
            }
        }


    }
}

void printPath(int v){
    if(parent[v]!=1){
        printPath(parent[v]);
    }
    cout<<char('A' + v)<<" ";

}

int main(){
    n=5;
    adj.resize(n,vector<int>(n,INF));
    adj[0][1] = 1;   // A -> B
    adj[1][0] = 1;   // B -> A

    adj[0][2] = 4;   // A -> C
    adj[2][0] = 4;   // C -> A

    adj[1][3] = 5;   // B -> D
    adj[3][1] = 5;   // D -> B

    adj[1][4] = 2;   // B -> E
    adj[4][1] = 2;   // E -> B

    adj[2][4] = 1;   // C -> E
    adj[4][2] = 1;   // E -> C

    adj[4][3] = 3;   // E -> D
    adj[3][4] = 3;   // D -> E

    dijkstra(0);

    for(int v=0;v<n;v++){
        cout<<char('A' + v)<<" = \n";
        if(dist[v]==INF){
            cout<<"INF: No Path\n";
        }
        else{

            cout<<dist[v]<<" : ";
            printPath(v);
            cout<<"\n";
        }
        
    return 0;
}
}