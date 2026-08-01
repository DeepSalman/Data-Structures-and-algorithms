//Check whether an array is sorted 
//in ascending order using divide and conquer

#include <iostream>
using namespace std;

bool isSorted(int arr[], int low, int high) {
    if (low == high)
        return true;

    int mid = low + (high - low) / 2;

    bool left = isSorted(arr, low, mid);
    bool right = isSorted(arr, mid + 1, high);

    return left && right && (arr[mid] <= arr[mid + 1]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, 0, n - 1))
        cout << "Array is sorted.";
    else
        cout << "Array is not sorted.";

    return 0;
}