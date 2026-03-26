#include<stdio.h>

void Bubblesrt(int arr[], int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


int main(){
    int size;
    printf("Enter array size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    Bubblesrt(arr,size);
    printf("Bubble Sorted array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}