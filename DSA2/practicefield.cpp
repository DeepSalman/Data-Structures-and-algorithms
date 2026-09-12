#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;

int main(){
    int V = 5;
    int graph[5][5] = {
        {0, 2, 3, 0, 0},
        {2, 0, 1, 4, 0},
        {3, 1, 0, 5, 6},
        {0, 4, 5, 0, 7},
        {0, 0, 6, 7, 0}
    };

    bool visited[5] = {false};
    int key[5];
    int parent[5];

    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
    }

    key[0]=0;

    for(int i=0;i<V;i++){
        int u=-1;
        for(int j=0;j<V;j++){
            if(!visited[j]&&(u==-1||key[j]<key[u])){
                u=j;
            }
        }
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 &&
                !visited[v] &&
                graph[u][v]<key[v]){
                    key[v]=graph[u][v];
                    parent[v]=u;
                }
        }
    }
    int total = 0;
    cout<<"MST"<<endl;

    for(int i=1;i<V;i++){
        cout<<parent[i]<<"-"<<i<<":"<<key[i]<<endl;
        total+=key[i];
    }
    cout<<"total cost: "<<total<<endl;
}