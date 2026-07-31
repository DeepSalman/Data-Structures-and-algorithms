#include<iostream>
using namespace std;

int veryMax(int arr[],int low,int high){
    if(low==high){
        return arr[low];
    }
    int mid = low+(high-low)/2;
    int leftMax = veryMax(arr,low,mid);
    int rightMax = veryMax(arr,mid+1,high);
    return max(leftMax,rightMax);
}

int veryMin(int arr[],int low,int high){
    if(low==high){
        return arr[low];
    }
    int mid = low+(high-low)/2;
    int leftMin = veryMin(arr,low,mid);
    int rightMin = veryMin(arr,mid+1,high);

    return min(leftMin,rightMin);
}

int main() {
    int arr[] = {2, -4, 3, -1, 5, -6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Element: " << veryMax(arr, 0, n - 1) << endl;
    cout << "Minimum Element: " << veryMin(arr, 0, n - 1) << endl;

    return 0;
}