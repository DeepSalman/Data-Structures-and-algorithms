#include<iostream>
using namespace std;
#include <climits>


int maxCrossSArray(int arr[],int low,int mid, int high){
    int sum = 0;
    int leftsum = INT_MIN;
    for(int i = mid;i>=low;i--){
        sum+=arr[i];
        leftsum = max(sum,leftsum);
    }
    sum = 0;
    int rightsum = INT_MIN;
    for(int i = mid+1;i<=high;i++){
        sum+=arr[i];
        rightsum = max(sum,rightsum);
    }

    return leftsum+rightsum;
}

int maxSubarray(int arr[], int low, int high){
    if(low==high) return arr[low];
    int mid = low+(high-low)/2;
    int left = maxSubarray(arr,low,mid);
    int right = maxSubarray(arr,mid+1,high);
    int cross = maxCrossSArray(arr,low,mid,high);

    return max(left,max(right,cross));
}


int main(){
    int arr[8] = {2, -4, 3, -1, 5, -6, 1, 2};

    int n = 8;

    cout << maxSubarray(arr, 0, n - 1);

    return 0;

    

}