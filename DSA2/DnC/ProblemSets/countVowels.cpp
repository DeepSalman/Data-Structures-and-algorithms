#include <iostream>
#include <cctype>
using namespace std;

class Count {
public:
    int vowels;
    int consonants;

    Count() {
        vowels = 0;
        consonants = 0;
    }
};

Count countVC(string &str, int low, int high) {

    // Base Case
    if (low == high) {
        Count ans;

        char ch = tolower(str[low]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            ans.vowels++;
        else
            ans.consonants++;

        return ans;
    }

    int mid = low + (high - low) / 2;

    Count left = countVC(str, low, mid);
    Count right = countVC(str, mid + 1, high);

    Count ans;
    ans.vowels = left.vowels + right.vowels;
    ans.consonants = left.consonants + right.consonants;

    return ans;
}

int main() {

    string str = "HelloWorld";

    Count result = countVC(str, 0, str.length() - 1);

    cout << "Vowels: " << result.vowels << endl;
    cout << "Consonants: " << result.consonants << endl;

    return 0;
}