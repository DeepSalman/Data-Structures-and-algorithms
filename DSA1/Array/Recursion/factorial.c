#include<stdio.h>

int factorial(int n){
    if(n<=1) return 1;
    return n*factorial(n-1);
}

int main(){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Factorial series: ");
    int sum = factorial(n);
    printf("%d ",sum);
    return 0;
}