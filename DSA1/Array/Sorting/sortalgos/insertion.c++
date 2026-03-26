#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int current = arr[i];  // take the current element
        int j = i - 1;

        // Move all elements greater than 'current' one step ahead
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place the current element in the correct position
        arr[j + 1] = current;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
