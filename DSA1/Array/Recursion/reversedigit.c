#include<stdio.h>

int totalsum(int n){
    if(n<=0) return 0;
    printf("%d",n%10);
    return totalsum(n/10);
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    totalsum(n);
    return 0;
}