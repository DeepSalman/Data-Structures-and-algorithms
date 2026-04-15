#include<stdio.h>

void selectionSort(int A[],int n){


    int i,j,min_index,temp;

    for(i=0;i<n-1;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(A[j]>A[min_index]){
                min_index=j;
            }
        }
        temp = A[min_index];
        A[min_index]=A[i];
        A[i]=temp;
    }
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int n = sizeof(data) / sizeof(data[0]);

    selectionSort(data, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}