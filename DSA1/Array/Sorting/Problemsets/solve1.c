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

int main() {
    int arraysize,kth_element;
    printf("Enter the number of elements: ");
    scanf("%d", &arraysize);
    int arr[arraysize];

    printf("Enter the array elements: ");
    for(int i=0;i<arraysize;i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the k-th element to find: ");
    scanf("%d", &kth_element);

    // Check if k is valid
    if(kth_element < 1 || kth_element > arraysize) {
        printf("Invalid value of k\n");
        return 0;
    }

    bubbleSort(arr, arraysize);

    printf("The %d-th smallest element is: %d\n", kth_element, arr[kth_element - 1]);

    return 0;
}