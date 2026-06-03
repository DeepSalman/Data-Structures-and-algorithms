#include<iostream>
using namespace std;

class Queue{
public:
    int front=-1;
    int rear=-1;
    int size=100;
    int arr[100];

    void enqueue(int val){
        if(front==-1 && rear==-1){// if the queue is empty
            front=0;
            rear=0;
            arr[0] = val;
        }else if( (rear+1)%size   == front  ){ // if the queue is currently full
            cout<<"Queue overflow\n";
        }else{
            rear = (rear+1)%size;
            arr[rear]=val;
        }
    }

    int dequeue(){
        if(front==-1 && rear==-1){ // if the queue is empty
            cout<<"Queue underflow"<<endl;
            return -1;
        }else if(front==rear){
            int temp = arr[front];
            front = -1;
            rear = -1;
            return temp;
        }else{
            int temp = arr[front];
            front = (front+1) % size;
            return temp;
        }
    }

    void printQueue(){
        cout<<"***********************\n";
        for(int i=0;i<size;i++){
            cout<< arr[i]<< " ";
        }
        cout<<endl;
        cout<<"front = "<<front<<endl;
        cout<<"rear = "<<rear;
        cout<<"\n***********************\n";
    }

};


int main(){
    Queue q1;

    q1.enqueue(1);

    cout<<"How many binary numbers do you want to generate?"<<endl;
    int n;
    cin>>n;

    cout<<"The generated binary numbers are"<<endl;
    for(int i=1;i<=n;i++){
        int val = q1.dequeue();
        cout<<val<<" ";
        int n1 = val*10;
        int n2= val*10+1;
        q1.enqueue(n1);
        q1.enqueue(n2);
    }

    return 0;
}

