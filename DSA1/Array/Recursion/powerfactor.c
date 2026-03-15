#include<stdio.h>
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
    printf("Enter base : ");
    scanf("%d", &base);
    printf("Enter exponent : ");
    scanf("%d", &exp);
    
    int result = power(base, exp);
    printf("%d^%d = %d\n", base, exp, result);



    return 0;
}