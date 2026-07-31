#include <iostream>
#include <cctype>
using namespace std;

struct Count {
    int vowels;
    int consonants;
};

Count countVC(string &str, int low, int high) {
    if (low == high) {
        Count result = {0, 0};

        if (isalpha(str[low])) {
            char ch = tolower(str[low]);

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                result.vowels = 1;
            else
                result.consonants = 1;
        }

        return result;
    }

    int mid = low + (high - low) / 2;

    Count left = countVC(str, low, mid);
    Count right = countVC(str, mid + 1, high);

    Count result;
    result.vowels = left.vowels + right.vowels;
    result.consonants = left.consonants + right.consonants;

    return result;
}

int main() {
    string str = "HelloWorld";

    Count ans = countVC(str, 0, str.length() - 1);

    cout << "Vowels: " << ans.vowels << endl;
    cout << "Consonants: " << ans.consonants << endl;

    return 0;
}