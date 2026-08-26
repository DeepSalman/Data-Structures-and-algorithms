





#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter sticks: ";
    cin >> a;

    cout << "Enter diamonds: ";
    cin >> b;

    int totalTools = (a + b) / 3;

    int answer = min({a, b, totalTools});

    cout << "Maximum number of tools: " << answer << endl;

    return 0;
}

