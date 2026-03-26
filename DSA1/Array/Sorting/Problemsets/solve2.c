#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float findMedian(int arr[], int n) {
    bubbleSort(arr, n);
    
    if(n % 2 != 0) {
        // Odd number of elements
        return arr[n / 2];
    } else {
        // Even number of elements
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}

int main() {
    int arraysize;
    printf("Enter the number of elements: ");
    scanf("%d", &arraysize);
    int arr[arraysize];

    printf("Enter the array elements: ");
    for(int i = 0; i < arraysize; i++) {
        scanf("%d", &arr[i]);
    }

    float median = findMedian(arr, arraysize);
    printf("The median is: %.2f\n", median);

    return 0;
}
