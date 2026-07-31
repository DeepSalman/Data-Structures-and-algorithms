#include <iostream>
using namespace std;

struct MinMax {
    int mn;
    int mx;
};

MinMax findMinMax(int arr[], int low, int high) {
    if (low == high)
        return {arr[low], arr[low]};

    int mid = low + (high - low) / 2;

    MinMax left = findMinMax(arr, low, mid);
    MinMax right = findMinMax(arr, mid + 1, high);

    MinMax result;
    result.mn = min(left.mn, right.mn);
    result.mx = max(left.mx, right.mx);

    return result;
}

int main() {
    int arr[] = {2, -4, 3, -1, 5, -6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax ans = findMinMax(arr, 0, n - 1);

    cout << "Maximum Element: " << ans.mx << endl;
    cout << "Minimum Element: " << ans.mn << endl;

    return 0;
}