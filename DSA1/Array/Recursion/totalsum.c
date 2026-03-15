#include<stdio.h>

int totalsum(int n){
    if(n<=0) return 0;
    return n%10 + totalsum(n/10);
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Reverse sum: %d",totalsum(n));
    return 0;
}