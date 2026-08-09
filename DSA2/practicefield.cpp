#include<iostream>
#include<cctype>
using namespace std;

struct A {
    char id;
    int start;
    int finish;

};

bool compare (A a, A b){
    return a.finish<b.finish;
}

int main(){
    A activities[] = {
        {'A', 1, 4},
        {'B', 3, 5},
        {'C', 0, 6},
        {'D', 5, 7},
        {'E', 3, 9},
        {'F', 5, 9},
        {'G', 6, 10},
        {'H', 8, 11},
        {'I', 8, 12},
        {'J', 2, 14},
        {'K', 12, 16}
    };


    int n = sizeof(activities)/sizeof(activities[0]);
    sort(activities,activities+n,compare);

    cout<<"Sorted activities: \n";
    for (int i=0;i<n;i++){
        cout<< activities[i].id << " "
        << activities[i].start<<" "
        <<activities[i].finish<<endl;
    }

    cout<<"\nSelected Activities \n";
    int lastFinish = -1;
    int count = 0;
    for(int i =0;i<n;i++){
        if(activities[i].start>=lastFinish){
            count++;
            cout<<activities[i].id<<" ";
            lastFinish = activities[i].finish;
        }
    }
    cout<<"\nYour total task: "<<count;
    return 0;
}