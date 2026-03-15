#include<stdio.h>

int factorial(int n){
    if(n<=1) return 1;
    return n*factorial(n-1);
}

int power(int base, int exp){
    if(exp < 0){
        // negative exponent for int result not supported here
        return 0;
    }
    if(exp == 0) return 1;
    return base * power(base, exp - 1);
}

int main(){
    int base, exp;
    printf("Enter base and exponent (space separated): ");
    if(scanf("%d %d", &base, &exp) != 2){
        printf("Invalid input\n");
        return 1;
    }
    int result = power(base, exp);
    printf("%d^%d = %d\n", base, exp, result);

    // optional: factorial example retained
    int n;
    printf("Enter a number to compute factorial: ");
    if(scanf("%d", &n) == 1){
        printf("%d! = %d\n", n, factorial(n));
    }

    return 0;
}