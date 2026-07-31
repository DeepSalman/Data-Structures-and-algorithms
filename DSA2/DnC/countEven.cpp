#include <iostream>
using namespace std;

int countEven(int arr[], int low, int high) {
    if (low == high)
        return (arr[low] % 2 == 0);

    int mid = low + (high - low) / 2;

    int left = countEven(arr, low, mid);
    int right = countEven(arr, mid + 1, high);

    return left + right;
}

int main() {
    int arr[] = {2, -4, 3, -1, 5, -6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Number of Even Elements: " << countEven(arr, 0, n - 1);

    return 0;
}