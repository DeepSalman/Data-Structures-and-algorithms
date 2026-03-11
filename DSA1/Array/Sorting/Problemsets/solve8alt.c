#include <stdio.h>

struct Element {
    int value;
    int freq;
};

int main() {
    int n;
    printf("Enter the size of your desired array: \n");
    scanf("%d",&n);

    int a[n];
    printf("Enter the array Elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    struct Element elements[1000];
    int size = 0;

    // build struct array with unique elements and their frequency
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (elements[j].value == a[i]) {
                elements[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            elements[size].value = a[i];
            elements[size].freq = 1;
            size++;
        }
    }

    // bubble sort by freq descending, tie-break by value ascending
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int swapNeeded = 0;
            if (elements[j].freq < elements[j+1].freq)
                swapNeeded = 1;
            else if (elements[j].freq == elements[j+1].freq && elements[j].value > elements[j+1].value)
                swapNeeded = 1;

            if (swapNeeded) {
                struct Element temp = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = temp;
            }
        }
    }

    // print each value freq times
    for (int i = 0; i < size; i++)
        for (int j = 0; j < elements[i].freq; j++)
            printf("%d ", elements[i].value);

    return 0;
}
