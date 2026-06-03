/*
=========================================
CIRCULAR QUEUE + BINARY NUMBER GENERATION
=========================================

QUEUE STRUCTURE:
- Array based circular queue
- front → points to first element
- rear  → points to last element
- size  → fixed capacity

-----------------------------------------
ENQUEUE (INSERT OPERATION)
-----------------------------------------
CASE 1: Queue is empty
- front = 0, rear = 0
- insert first element

CASE 2: Queue is full
Condition:
(rear + 1) % size == front
- This means next position of rear hits front → overflow

CASE 3: Normal insertion
- rear = (rear + 1) % size
- insert element at rear

-----------------------------------------
DEQUEUE (REMOVE OPERATION)
-----------------------------------------
CASE 1: Queue is empty
- front == -1 && rear == -1
- underflow

CASE 2: Only one element
- store arr[front]
- reset front = rear = -1
- return element

CASE 3: Normal deletion
- store arr[front]
- front = (front + 1) % size
- return stored value

-----------------------------------------
PRINT FUNCTION
-----------------------------------------
- prints entire array (not logical queue view)
- also prints front and rear positions

-----------------------------------------
IMPORTANT PATTERN:
-----------------------------------------
"Circular movement using MOD operator"
=> (index + 1) % size

-----------------------------------------
BINARY NUMBER GENERATION IDEA:
-----------------------------------------
START:
- enqueue 1

PROCESS:
- dequeue a number (say x)
- generate:
    x * 10   → left child (append 0)
    x * 10+1 → right child (append 1)
- enqueue both back

-----------------------------------------
WHY THIS WORKS:
-----------------------------------------
- Queue ensures BFS order
- Each number expands into next binary level
- Produces binary numbers in sequence order:
  1, 10, 11, 100, 101, ...

-----------------------------------------
KEY MEMORY LINE:
-----------------------------------------
"QUEUE = LEVEL ORDER GENERATOR"
*/



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

