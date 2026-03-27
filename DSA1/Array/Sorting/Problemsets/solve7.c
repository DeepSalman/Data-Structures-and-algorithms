#include<stdio.h>

void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n=6;
    int arr[6]={100,4,200,1,3,2};
    insertionSort(arr,n);
    int MaxStreak=1,CurrentStreak=1;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]) continue;
        if(arr[i]==arr[i-1]+1){
            CurrentStreak++;
        }
        else{
            CurrentStreak=1;
        }
        if(CurrentStreak>MaxStreak){
            MaxStreak=CurrentStreak;
        }
    }
    printf("%d",MaxStreak);
}