#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
int minimumDifference(int arr[],int size){
    if(size<2) return 0;
    int mindiff=INT_MAX;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            int diff=abs(arr[i]-arr[j]);
            if(diff<mindiff){
                mindiff=diff;
            }
        }
    }
    return mindiff;

}

int main(){
    int arraysize;
    printf("Enter the number of elements: ");
    scanf("%d", &arraysize);
    int arr[arraysize];

    printf("Enter the array elements: ");
    for(int i=0;i<arraysize;i++){
        scanf("%d", &arr[i]);
    }

    Bubblesrt(arr,arraysize);
    int difference = minimumDifference(arr,arraysize);
    printf("Minimum Difference in this array is : %d",difference);

    return 0;

}