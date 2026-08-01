#include <iostream>
#include <climits>
using namespace std;

class Result {
public:
    int sum;
    int start;
    int end;
};

Result maxCrossSubArray(int arr[], int low, int mid, int high) {

    int sum = 0;
    int leftSum = INT_MIN;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    int maxRight = mid + 1;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    Result ans;
    ans.sum = leftSum + rightSum;
    ans.start = maxLeft;
    ans.end = maxRight;

    return ans;
}

Result maxSubArray(int arr[], int low, int high) {

    if (low == high) {
        Result ans;
        ans.sum = arr[low];
        ans.start = low;
        ans.end = high;
        return ans;
    }

    int mid = low + (high - low) / 2;

    Result left = maxSubArray(arr, low, mid);
    Result right = maxSubArray(arr, mid + 1, high);
    Result cross = maxCrossSubArray(arr, low, mid, high);

    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}

int main() {

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Result ans = maxSubArray(arr, 0, n - 1);

    cout << "Maximum Sum = " << ans.sum << endl;
    cout << "Start Index = " << ans.start << endl;
    cout << "End Index = " << ans.end << endl;

    return 0;
}