#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int coins[] = {1, 5, 10, 25};

    int n = 4;
    int amount = 41;
    int coinCount = 0;

    // Sort coins from largest to smallest
    sort(coins, coins + n, greater<int>());

    cout << "Coins selected: ";

    for(int i = 0; i < n; i++)
    {
        while(amount >= coins[i])
        {
            cout << coins[i] << " ";

            amount = amount - coins[i];

            coinCount++;
        }
    }

    cout << endl;
    cout << "Total coins: " << coinCount << endl;

    return 0;
}