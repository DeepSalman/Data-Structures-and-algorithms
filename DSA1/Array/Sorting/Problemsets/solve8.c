#include <stdio.h>

int main() {
    int a[] = {4,3,1,6,1,3,4,4};
    int n = 8;
    int freq[100] = {0};
    int i,j,temp;

    // Count frequency
    for(i=0;i<n;i++){
        freq[a[i]]++;
    }

    // Sort array based on frequency
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){

            if(freq[a[j]] < freq[a[j+1]] ||(freq[a[j]] == freq[a[j+1]] && a[j] > a[j+1])){

                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // Print result
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}