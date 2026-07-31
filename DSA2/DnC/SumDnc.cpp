#include<iostream>
using namespace std;


int summation(int arr[],int low,int high){
    if(low==high){
        return arr[low];
    }

    int mid = low+(high-low)/2;
    int leftSum = summation(arr,low,mid);
    int rightSum = summation(arr,mid+1,high);

    return leftSum+rightSum;
}


int main(){
    int arr[] = {2, -4, 3, -1, 5, -6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Sum of Array: " << summation(arr, 0, n - 1);

    return 0;
}