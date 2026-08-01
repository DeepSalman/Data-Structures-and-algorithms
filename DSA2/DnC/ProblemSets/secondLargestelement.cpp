//Find the second largest 
//element of an array using divide and conquer.



#include <iostream>
#include <climits>
using namespace std;

class Result {
public:
    int largest;
    int secondLargest;

    Result() {
        largest = 0;
        secondLargest = INT_MIN;
    }
};

Result findSecondLargest(int arr[], int low, int high) {

    // Base Case
    if (low == high) {
        Result ans;
        ans.largest = arr[low];
        ans.secondLargest = INT_MIN;
        return ans;
    }

    int mid = low + (high - low) / 2;

    Result left = findSecondLargest(arr, low, mid);
    Result right = findSecondLargest(arr, mid + 1, high);

    Result ans;

    if (left.largest > right.largest) {
        ans.largest = left.largest;
        ans.secondLargest = max(left.secondLargest, right.largest);
    }
    else {
        ans.largest = right.largest;
        ans.secondLargest = max(right.secondLargest, left.largest);
    }

    return ans;
}

int main() {

    int arr[] = {2, -4, 3, -1, 5, -6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Result result = findSecondLargest(arr, 0, n - 1);

    cout << "Largest Element: " << result.largest << endl;
    cout << "Second Largest Element: " << result.secondLargest << endl;

    return 0;
}