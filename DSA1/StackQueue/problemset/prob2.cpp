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
    char str [20];
    cout<<"Enter a string"<<endl;
    gets(str);
    cout<<"You entered"<<endl;
    puts(str);

    int isOkay = 1;
    for(int i=0; str[i]!='\0' ; i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s1.push(str[i]);
        }else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            char poppedValue = s1.pop();
            if(   (poppedValue=='(' && str[i]==')') ||  (poppedValue=='{' && str[i]=='}')  || (poppedValue=='[' && str[i]==']') ){
                // its okay, we don't need to break the loop
            }else{
                // brackets  are mismatching, we need to break the loop
                isOkay=0;
                break;
            }
        }else{
             // its okay, we don't need to break the loop
        }
    }

    s1.printStack();
    cout<<"s1 top is "<<s1.top<<endl;

    if(s1.top!=-1){ // if the stack is not empty
        isOkay=0;
        cout<<"here"<<endl;
    }

    if(isOkay==1){
        cout<<"The brackets are okay\n";
    }else{
        cout<<"The brackets are NOT okay\n";
    }
    return 0;
}

/*
{6+3-(9/2)+3-[2]}
(2+[6+2]+3
*/
