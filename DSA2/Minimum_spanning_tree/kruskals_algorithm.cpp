#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Edges {
    char u,v;
    int weight;
};

bool compare(Edges a,Edges b){
    return a.weight<b.weight;
}

char find(char parent[],char x){
    if(parent[x]==x){
        return x;
    }
    return find(parent,parent[x]);
}

void unite(char parent[],char a,char b){
    char RootA = find(parent,a);
    char RootB = find(parent,b);

    parent[RootA]=RootB;
}

int main(){
    vector<Edges> edges{
        {'A', 'B', 1},
        {'B', 'C', 2},
        {'A', 'C', 3},
        {'C', 'D', 4},
        {'B', 'D', 5}
    };

    sort(edges.begin(),edges.end(),compare);

    char parent[256];

    for(char v='A';v<='D';v++){
        parent[v]=v;
    }

    int total =0;
    int count=0;

    for(Edges e:edges){
        char RootA=find(parent,e.u);
        char RootB=find(parent,e.v);

        if(RootA!=RootB){
            cout<<e.u<<"-"
                <<e.v<<"-"
                <<e.weight<<endl;

            total+=e.weight;
            count++;

            unite(parent,e.u,e.v);
        }
        
        if(count==3) break;
    }

    cout<<"Total cost: "<<total<<endl;

    


}