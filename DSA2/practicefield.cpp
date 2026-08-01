#include<iostream>
#include<cctype>
using namespace std;


void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;int n2 = r-m; int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n1;i++) R[i]=arr[l+i];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[i++];
    }

    while(i<n1) arr[k++]=L[i++];
    while(i<n2) arr[k++]=R[j++];
    
}

void mergeSort(int arr[],int low,int high){
    if(left<right){
        int mid = low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main(){
    int arr[]={-1, 2, -5, 10, 2, 4, 5, -3, 2, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}