#include <iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    int violations = 0;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
            violations += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return violations;
}

int countViolations(int arr[], int left, int right) {

    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int leftCount = countViolations(arr, left, mid);
    int rightCount = countViolations(arr, mid + 1, right);
    int mergeCount = merge(arr, left, mid, right);

    return leftCount + rightCount + mergeCount;
}

int main() {

    int arr[] = {4, 5, 6, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int violations = countViolations(arr, 0, n - 1);

    cout << "Total Violations: " << violations << endl;

    return 0;
}