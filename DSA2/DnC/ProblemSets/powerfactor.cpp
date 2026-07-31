#include <iostream>
using namespace std;

long long power(long long x, long long n) {
    if (n == 0)
        return 1;

    long long half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int main() {
    long long x = 2;
    long long n = 10;

    cout << x << "^" << n << " = " << power(x, n);

    return 0;
}