#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printAdjList(vector <  vector <int> > adjList){
    cout<<"\n***********************"<<endl;
    for(int i=0;i<adjList.size();i++){

        vector <int> smallContainer = adjList[i];

        for(int j=0;j<smallContainer.size();j++){
            cout<<smallContainer[j]<<" ";
        }

        cout<<endl;
    }
    cout<<"\n***********************"<<endl;
}

int WHITE = 1;
int GRAY = 2;
int BLACK = 3;

int color[100];
int d_time[100];
int f_time[100];

int timer;

void DFS_Visit(int v, vector <vector <int>> adjList ){
    // 1st phase
    color[v] = GRAY;
    timer = timer + 1;
    d_time[v] = timer;

    // 2nd phase
    for(int u : adjList[v]){
        if(color[u]==WHITE){
            DFS_Visit(u, adjList);
        }

    }

    // 3rd phase
    color[v] = BLACK;
    timer = timer + 1;
    f_time[v] = timer;
}


void DFS(vector <  vector <int> > adjList, int V, int E){
    for(int i=0;i<=V-1;i++){
        color[i]=WHITE;
    }
    timer=0;

    for(int i=0;i<=V-1;i++){
        if(color[i]==WHITE){
            DFS_Visit(i, adjList);
        }
    }
}

void printVertexProperties(int V){
    cout<<"\n******************************\n";
    for(int i=0;i<=V-1;i++){
        cout<<"v="<<i<<", color="<<color[i]<<", dtime= "<<d_time[i]<<", ftime="<<f_time[i]<<endl;
    }
    cout<<"\n******************************\n";
}

int main(){
    vector <  vector <int> > adjList;

    int V,E;
    cout<<"Enter the number of vertices "<<endl;
    cin>>V;
    cout<<"Enter the number of edges "<<endl;
    cin>>E;

    for(int i=1;i<=V;i++){
        vector <int> smallContainer;
        adjList.push_back(smallContainer);
    }
    cout<<"Enter the edges"<<endl;

    for(int i=1;i<=E;i++){
        int u,v;
        cin>>u;
        cin>>v;
        adjList[u].push_back(v);
    }

    printAdjList(adjList);

    DFS(adjList,V,E);

    printVertexProperties(V);
    return 0;
}

/*
8 14
0 1
0 6
0 4
1 7
1 4
2 1
2 7
2 3
3 4
4 5
5 0
6 5
6 4
7 4
*/

