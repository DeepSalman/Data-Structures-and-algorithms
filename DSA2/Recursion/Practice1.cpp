#include<iostream>
using namespace std;

int maxCross(int arr[],int l,int mid,int h){
    int sum = 0;
    int leftsum = INT_MIN;
    for(int i= mid;i>=l;i--){
        sum+=arr[i];
        leftsum = max(sum,leftsum);
    }
    sum = 0;
    int rightsum = INT_MIN;
    for(int i=mid+1;i<=h;i++){
        sum+=arr[i];
        rightsum = max(sum,rightsum);
    }

    return leftsum+rightsum;
}

int maxSubArray(int arr[],int low,int high){
    if(low==high) return arr[low];
    int mid = low+(high-low)/2;
    int left = maxSubArray(arr,low,mid);
    int right = maxSubArray(arr,mid+1,high);
    int cross = maxCross(arr,low,mid,high);

    return max(left,max(right,cross));

}


int main(){



    int arr[8]={2,-4,3,-1,5,-6,1,2};
    int n = 8;

    cout<<maxSubArray(arr,0,n-1)<<" ";

    
}