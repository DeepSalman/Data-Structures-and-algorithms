#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of your desired array: \n");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the array Elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int freq[1000]={0};

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(freq[arr[j]]<freq[arr[j+1]]||(freq[arr[j]]==freq[arr[j+1]] && arr[j]>arr[j+1])){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}