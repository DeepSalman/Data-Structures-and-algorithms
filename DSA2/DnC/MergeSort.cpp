#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1; int n2 = r - m; int L[n1], R[n2];
    for (int x = 0; x < n1; x++) L[x] = arr[l + x];
    for (int x = 0; x < n2; x++) R[x] = arr[m + 1 + x];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[10] = {-1, 2, -5, 10, 2, 4, 5, -3, 2, 6};
    int n = 10;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

