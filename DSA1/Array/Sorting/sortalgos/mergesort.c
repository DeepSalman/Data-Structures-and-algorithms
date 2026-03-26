#include<stdio.h>


void insertionsort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void bubble(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printing(int arr[], int n){
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}



int main(){
    int An,Bn;
    printf("Enter array size: ");
    scanf("%d",&An);
    int arr[An];
    printf("Enter array elements: ");
    for(int i=0;i<An;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d",&Bn);
    int arr2[Bn];
    printf("Enter second array elements: ");
    for(int i=0;i<Bn;i++){
        scanf("%d",&arr2[i]);
    }

    insertionsort(arr, An);
    insertionsort(arr2, Bn);


    int newA[An+1];
    int newB[Bn+1];
    for(int i=0;i<An;i++){
        newA[i] = arr[i];
    }
    for(int i=0;i<Bn;i++){
        newB[i] = arr2[i];
    }
    newA[An] = 9999; // Sentinel value
    newB[Bn] = 9999; // Sentinel value

    int merge[An+Bn];

    int i=0, j=0, k=0;
    for(k=0;k<An+Bn-1;k++){
        if(newA[i]<newB[j]){
            merge[k] = newA[i];
            i++;
        }
        else{
            merge[k] = newB[j];
            j++;
        }
    }

    printing(merge, An+Bn-1);

    return 0;



}

