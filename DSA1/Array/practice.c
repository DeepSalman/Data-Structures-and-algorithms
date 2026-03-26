#include<stdio.h>
#include<math.h>

struct Element
{
    int realValue;
    int ValueUesdForSorting;
};

void Insertionsrt(struct Element A[], int size){
    for(int i=1;i<size;i++){
        struct Element key = A[i];
        int j=i-1;
        while(j>=0 && A[j].ValueUesdForSorting>key.ValueUesdForSorting){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}


int main(){
    int size;
    printf("Enter your array size: ");
    scanf("%d",&size);

    struct Element A[size];

    printf("Enter your array Elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&A[i].realValue);
    }

    //Converting elements 
    for(int i=0;i<size;i++){
        A[i].ValueUesdForSorting=abs(A[i].realValue);
    }

    Insertionsrt(A,size);
    printf("Your array is : ");
    for(int i=0;i<size;i++){
        printf("%d ",A[i].realValue);
    }
}

