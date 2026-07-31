#include <iostream>
using namespace std;

void reverseString(string &str, int low, int high) {
    if (low >= high)
        return;

    swap(str[low], str[high]);

    reverseString(str, low + 1, high - 1);
}

int main() {
    string str = "HelloWorld";

    reverseString(str, 0, str.length() - 1);

    cout << "Reversed String: " << str;

    return 0;
}