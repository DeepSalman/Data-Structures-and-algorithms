#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int n,pos;
    cout<<"Enter your array size : ";
    cin>>n;

    cout<<"Enter Your elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter Your deleting position :";
    cin>>pos;

    for(int i=pos-1;i<n;i++){
        arr[i]=arr[i+1];
    }

    n--;
    cout<<"Your new array :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}