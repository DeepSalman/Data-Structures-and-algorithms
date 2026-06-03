#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector <int> v1;

    // CRUD operations

    // Create
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    v1.insert(  v1.begin() + 2 , 1000  );

    cout<<"size of v1 is now "<<v1.size()<<endl;

    // Read
    cout<<"\n*******************"<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<"\n*******************"<<endl;

    // Update
    v1[2] = 3000;
    // Read
    cout<<"\n*******************"<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<"\n*******************"<<endl;

    // Delete
    int x = v1.back();
    cout<<"x="<<x<<endl;
    v1.pop_back();
        // Read
    cout<<"\n*******************"<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<"\n*******************"<<endl;

    x = v1[1];// we may store the value before deleting it
    cout<<"The value stored in x before deleting "<<endl;
    v1.erase(v1.begin() + 2  );

    // Read
    cout<<"\n*******************"<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<"\n*******************"<<endl;
    return 0;

}

//Logging in 
