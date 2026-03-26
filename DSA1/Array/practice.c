#include<stdio.h>
#include<math.h>
#include<string.h>


struct StElm
{
    char realValue[20];
    int sortValue;
};

void insertionsort(struct StElm A[],int size){
    for(int i=0;i<size;i++){
        struct StElm key = A[i];
        int j=i-1;
        while(j>=0 && A[j].sortValue>key.sortValue){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main(){
    int size;
    printf("Enter your Char array Size: ");
    scanf("%d",&size);
    getchar();

    struct StElm A[size];

    printf("Enter your strings: ");
    for(int i=0;i<size;i++){
        fgets(A[i].realValue,sizeof(A[i].realValue),stdin);
    }

    for(int i=0;i<size;i++){
        A[i].sortValue=strlen(A[i].realValue);
    }

    
    printf("Your provided array: ");
    for(int i=0;i<size;i++){
        printf("%s ",A[i].realValue);
    }

    insertionsort(A,size);

    printf("Sorted array: ");
    for(int i=0;i<size;i++){
        printf("%s ",A[i].realValue);
    }
}