#include<stdio.h>
void printArray(int A[],int n){
    printf("\n*******************\n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n*******************\n");
}

void insertionSortAscending(int A[],int n){
    for(int i=1;i<=n-1;i++){
        int key = A[i];
        int j = i-1;
        while(j>-1 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

void insertionSortDescending(int A[],int n){
    for(int i=1;i<=n-1;i++){
        int key = A[i];
        int j = i-1;
        while(j>-1 && A[j]<key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main(){
    printf("Enter the array size\n");
    int n;

    scanf("%d",&n);
    int A[n];

    printf("Enter the array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printArray(A,n);

    int oddArrSize = n/2;
    int evenArrSize;

    if(n%2==0){
        evenArrSize=n/2;
    }else{
        evenArrSize=n-n/2;
    }

    int oddArray[oddArrSize];
    int evenArray[evenArrSize];

    for(int i=0,j=1;i<oddArrSize;i++,j=j+2){
        oddArray[i]=A[j];
    }
    for(int i=0,j=0;i<evenArrSize;i++,j=j+2){
        evenArray[i]=A[j];
    }

    printf("Odd array and Even array before sorting\n");
    printArray(oddArray,oddArrSize);
    printArray(evenArray,evenArrSize);

    insertionSortAscending(evenArray,evenArrSize);
    insertionSortDescending(oddArray,oddArrSize);

    printf("Odd array and Even array after sorting\n");
    printArray(oddArray,oddArrSize);
    printArray(evenArray,evenArrSize);

    for(int i=0,j=1;i<oddArrSize;i++,j=j+2){
//        oddArray[i]=A[j];
        A[j]=oddArray[i];
    }
    for(int i=0,j=0;i<evenArrSize;i++,j=j+2){
//        evenArray[i]=A[j];
        A[j]=evenArray[i];
    }
    printf("After completions\n");
    printArray(A,n);
    return 0;
}

/*
8
16 17 4 18 1 20  5 12
*/