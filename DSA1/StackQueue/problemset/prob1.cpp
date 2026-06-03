#include<iostream>
#include<string.h>

using namespace std;
class Stack{
public:
    int top = -1;
    char arr[20];
    int size =20;

    void push(char val){
        if(top==size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }

        top++;
        arr[top]=val;
    }

    char pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return '\0';
        }
        top--;
        return arr[top+1];
    }

    void printStack(){
        cout<<"*****************"<<endl;
        for(int i=0;i<=top;i++){
            cout<< arr[i]<<" ";
        }
        cout<<"\n*****************"<<endl;
    }

};

int main(){
    Stack s1;
//    s1.push('A');
//    s1.push('E');
//    s1.push('I');
//    s1.printStack();
//    s1.pop();
//    s1.pop();
//    s1.printStack();
//    s1.pop();
//    s1.pop();

    char str [20];
    cout<<"Enter a string"<<endl;
    gets(str);
    cout<<"You entered"<<endl;
    puts(str);

    for(int i=0; str[i]!='\0' ;i++){
        s1.push( str[i] );
    }

    s1.printStack();

    for(int i=0; str[i]!='\0' ;i++){
        str[i] = s1.pop();
    }

    cout<<"After reversing we get"<<endl;
    puts(str);
    return 0;
}
