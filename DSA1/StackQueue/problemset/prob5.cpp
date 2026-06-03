/*
=====================================
STACK USING TWO QUEUES - CORE IDEA
=====================================

GOAL:
- Stack = LIFO
- Queue = FIFO

So we rearrange order to simulate LIFO.

-------------------------------------
PUSH STRATEGY:
-------------------------------------
- Insert new element first into q2
- Move all elements from q1 → q2
- Swap q1 and q2

RESULT:
- New element always comes to FRONT
- So it behaves like STACK TOP

KEY IDEA:
"Make newest element always first in queue"

-------------------------------------
POP STRATEGY:
-------------------------------------
- Just remove from q1 front
- Because top of stack is always at front

-------------------------------------
IMPORTANT TRICK:
-------------------------------------
We are NOT changing queue rules.
We are just rearranging order after every push.

-------------------------------------
ONE LINE MEMORY TRICK:
-------------------------------------
"QUEUE REORDERING = STACK SIMULATION"
*/



#include<iostream>
using namespace std;

/*
=====================================
STACK USING TWO QUEUES (NOTES)
=====================================

We use:
q1 = main queue
q2 = helper queue

Goal:
Stack = LIFO (Last In First Out)
Queue = FIFO (First In First Out)

So we simulate LIFO using FIFO rules
*/

class Queue {
public:
    int arr[100];
    int front = -1;
    int rear = -1;
    int size = 100;

    void enqueue(int val) {
        if (rear == size - 1) {
            cout << "Queue overflow\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        arr[++rear] = val;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            return -1;
        }

        int val = arr[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return val;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};

class StackUsingQueues {
public:
    Queue q1, q2;

    /*
    -------------------------------------
    PUSH OPERATION (STACK INSERT)
    -------------------------------------
    - Always push into q2 first
    - Then move all elements of q1 → q2
    - Swap q1 and q2

    WHY?
    - We want NEW element always at FRONT
    - So it behaves like STACK TOP
    */
    void push(int val) {
        q2.enqueue(val);

        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        // swap q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    /*
    -------------------------------------
    POP OPERATION (STACK REMOVE)
    -------------------------------------
    - Simply dequeue from q1
    - Because top of stack is always at front of q1
    */
    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack underflow\n";
            return -1;
        }

        return q1.dequeue();
    }

    int top() {
        if (q1.isEmpty()) return -1;
        return q1.arr[q1.front];
    }

    void printStack() {
        cout << "Stack (top to bottom): ";
        for (int i = q1.front; i <= q1.rear; i++) {
            cout << q1.arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackUsingQueues s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl; // 30
    cout << s.pop() << endl; // 20

    s.push(40);

    s.printStack(); // 40 10

    return 0;
}