#include<stdio.h>
#include<string.h>

void reverseString(char str[], int i, int j){
    if(i >= j) return;
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    reverseString(str, i+1, j-1);
}

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);
    int length = strlen(str);
    reverseString(str, 0, length-1);
    printf("Reversed string: %s\n", str);
    return 0;
}