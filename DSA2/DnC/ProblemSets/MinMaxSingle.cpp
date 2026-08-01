//Find both the maximum and the minimum of 
//an array in one divide and conquer pass.
#include <iostream>
using namespace std;

class MinMax {
public:
    int mn;
    int mx;

    MinMax() {
        mn = 0;
        mx = 0;
    }
};

MinMax findMinMax(int arr[], int low, int high) {

    // Base Case
    if (low == high) {
        MinMax ans;
        ans.mn = arr[low];
        ans.mx = arr[low];
        return ans;
    }

    int mid = low + (high - low) / 2;

    MinMax left = findMinMax(arr, low, mid);
    MinMax right = findMinMax(arr, mid + 1, high);

    MinMax ans;
    ans.mn = min(left.mn, right.mn);
    ans.mx = max(left.mx, right.mx);

    return ans;
}

int main() {

    int arr[] = {2, -4, 3, -1, 5, -6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Maximum Element: " << result.mx << endl;
    cout << "Minimum Element: " << result.mn << endl;

    return 0;
}