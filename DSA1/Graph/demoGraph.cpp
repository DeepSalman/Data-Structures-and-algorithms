#include<iostream>
#include<vector>
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
        adjList[v].push_back(u);
    }

    printAdjList(adjList);

    return 0;
}

/*

5
6
0 1
0 4
1 3
4 3
1 2
2 3
*/
