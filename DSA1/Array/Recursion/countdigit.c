#include <stdio.h>

int countDigitsRec(int n) {
    if (n < 0) n = -n;          // handle negative numbers
    if (n < 10) return 1;
    return 1 + countDigitsRec(n / 10);
}


int main(void) {
    int num;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    int count = countDigitsRec(num);
    printf("Number of digits in %d is %d\n", num, count);
    return 0;
}
