#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    char id;
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {

    Item items[] = {
        {'A', 10, 60, 0},
        {'B', 20, 100, 0},
        {'C', 30, 120, 0}
    };

    int n = 3;
    int capacity = 50;

    // Calculate value/weight ratio
    for (int i = 0; i < n; i++) {
        items[i].ratio =
            (double)items[i].value / items[i].weight;
    }

    // Sort by highest ratio
    sort(items, items + n, compare);

    double totalValue = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {

            // Take whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;

            cout << "Take whole " << items[i].id << endl;
        }
        else {

            // Take fraction of item
            double fraction =
                (double)capacity / items[i].weight;

            totalValue += items[i].value * fraction;

            cout << "Take " << fraction
                 << " of " << items[i].id << endl;

            capacity = 0;
        }
    }

    cout << "Maximum value = " << totalValue << endl;

    return 0;
}