#include<iostream>
#include<stdio.h>
using namespace std;

class Stack{
public:
    int top = -1;
    int size = 5;
    int arr[5];

    void push(int val){
        if(top==size-1){
            printf("Stack overflow\n");
            return;
        }

        top++;
        arr[top]=val;
    }

    int pop(){
        if(top==-1){
            printf("Stack underflow\n");
            return -1;
        }

        top--;
        return arr[top+1];
    }

    void printStack(){
        printf("\n*****************\n");
        for(int i=0;i<=top;i++){
            printf("%d ",arr[i]);
        }
        printf("\n*****************\n");
    }


};

int main(){
//    cout<< "Hello world\n";
//
//    cout<<"Enter the value of n\n";
//    int n;
//    cin>>n;
//
////    cout<<"Enter the value of m\n";
////    cout<<"Enter the value of m"<<"\n";
//    cout<<"Enter the value of m"<<endl;
//    int m;
//    cin>>m;
//
//    cout<<"sum of "<<n <<" and "<< m <<" is " <<n+m <<"\n";

    Stack s1;
    Stack s2;

    s1.push(100);
    s1.push(200);
    s1.push(300);
    s1.printStack();

    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.push(40);
    s2.pop();
    s2.printStack();
    return 0;
}

