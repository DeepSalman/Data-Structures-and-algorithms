#include<stdio.h>
#include<math.h>
#include<string.h>

struct Element{
    char realValue [20];
    int valueUsedForSorting;
};

void printArray(struct Element A[],int n){
    printf("\n***************************\n");
    for(int i=0;i<n;i++){
        printf("(%s,%d) ",A[i].realValue,A[i].valueUsedForSorting);
    }
    printf("\n***************************\n");
}

void insertionSort(struct Element A[],int n){
    for(int i=1;i<=n-1;i++){
        struct Element key = A[i];
        int j=i-1;
        while(j>-1 && A[j].valueUsedForSorting>key.valueUsedForSorting){
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
    getchar();
    struct Element A[n];

    printf("Enter the array values\n");

    for(int i=0;i<n;i++){
        gets(A[i].realValue);
    }
    for(int i=0;i<n;i++){
        A[i].valueUsedForSorting = strlen(A[i].realValue);
    }

    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);

    return 0;
}
