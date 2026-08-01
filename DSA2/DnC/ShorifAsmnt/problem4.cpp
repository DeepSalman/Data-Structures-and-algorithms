#include <iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right) {

    int count = 0;

    // Count reverse pairs
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[i] > 2LL * arr[j])
            j++;

        count += (j - (mid + 1));
    }

    // Merge Step
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0;
    j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return count;
}

int reversePairs(int arr[], int left, int right) {

    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int leftCount = reversePairs(arr, left, mid);
    int rightCount = reversePairs(arr, mid + 1, right);
    int mergeCount = merge(arr, left, mid, right);

    return leftCount + rightCount + mergeCount;
}

int main() {

    int arr[] = {1, 3, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Reverse Pairs: " << reversePairs(arr, 0, n - 1);

    return 0;
}