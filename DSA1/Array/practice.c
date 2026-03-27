#include<stdio.h>
#include<math.h>
#include<limits.h>


void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n=5,m=6;
    int arr1[5]={1,16,13,14,4};
    int arr2[6]={15,12,5,3,7,22};

    insertionSort(arr1,n);
    insertionSort(arr2,m);

    int new1[n+1],new2[m+1];

    for(int i=0;i<n;i++){
        new1[i]=arr1[i];
    }
    for(int i=0;i<m;i++){
        new2[i]=arr2[i];
    }

    new1[n]=INT_MAX;
    new2[m]=INT_MAX;

    int merge[n+m];

    int i=0,j=0,k=0;
    for(k=0;k<(n+m);k++){
        if(new1[i]<new2[j]){
            merge[k]=new1[i];
            i++;
        }
        else{
            merge[k]=new2[j];
            j++;
        }
    }
    printf("Your merged array is :");
    for(int i=0;i<n+m;i++){
        printf("%d ",merge[i]);
    }
}