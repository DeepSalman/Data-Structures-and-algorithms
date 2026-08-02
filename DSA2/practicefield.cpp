#include<iostream>
#include<cctype>
using namespace std;

int maxCrossSumArray(int arr[],int low,int mid,int high){
    int sum = 0;
    int leftsum = INT_MIN;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        leftsum =max(sum,leftsum);
    }
    sum = 0;
    int rightsum = INT_MIN;
    for(int i=mid+1;i<=high;i++){
        sum += arr[low];
        leftsum = max(sum,rightsum);
    }
}

int MaxSubArray(int arr[],int left,int right){
    if(left==right) return arr[left];
    int mid = left+(right-left)/2;
    int right= MaxSubArray(arr,left,mid);
    int left = MaxSubArray(arr,mid+1,right);
}

