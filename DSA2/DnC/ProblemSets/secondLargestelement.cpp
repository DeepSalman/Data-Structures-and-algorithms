#include <iostream>
#include <climits>
using namespace std;

struct Result {
    int largest;
    int secondLargest;
};

Result findSecondLargest(int arr[], int low, int high) {
    if (low == high)
        return {arr[low], INT_MIN};

    int mid = low + (high - low) / 2;

    Result left = findSecondLargest(arr, low, mid);
    Result right = findSecondLargest(arr, mid + 1, high);

    Result res;

    if (left.largest > right.largest) {
        res.largest = left.largest;
        res.secondLargest = max(left.secondLargest, right.largest);
    } else {
        res.largest = right.largest;
        res.secondLargest = max(right.secondLargest, left.largest);
    }

    return res;
}

int main() {
    int arr[] = {2, -4, 3, -1, 5, -6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Result ans = findSecondLargest(arr, 0, n - 1);

    cout << "Largest Element: " << ans.largest << endl;
    cout << "Second Largest Element: " << ans.secondLargest << endl;

    return 0;
}