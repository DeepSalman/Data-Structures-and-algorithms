/*
===============================
QUEUE USING TWO STACKS (NOTES)
===============================

STACKS USED:
s1 = main storage stack
s2 = helper stack

--------------------------------
ENQUEUE (insert):
--------------------------------
- Just push into s1
- Because stack naturally stores in LIFO order

s1.push(x)

--------------------------------
DEQUEUE (remove front element):
--------------------------------
Goal: simulate FIFO using LIFO stacks

Steps:
1. Move all elements from s1 → s2
   (this reverses order)

2. Pop from s2
   (this gives the oldest inserted element = QUEUE FRONT)

3. Move everything back s2 → s1
   (restore original structure)

--------------------------------
WHY IT WORKS:
--------------------------------
- s1 stores elements in reverse order of queue
- s2 reverses again → gives correct FIFO order
- So we simulate queue behavior using stack reversal

--------------------------------
KEY IDEA TO REMEMBER:
--------------------------------
"STACK → REVERSE → STACK = QUEUE FRONT ACCESS"
*/


#include<iostream>
using namespace std;

class Stack {
public:
    int top;
    int arr[100];
    int size;

    Stack() {
        top = -1;
        size = 100;
    }

    void push(int val) {
        if (top == size - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (top == -1) {
            return -1; // underflow
        }
        return arr[top--];
    }

    int isEmpty() {
        return top == -1;
    }
};

class QueueUsingStacks {
public:
    Stack s1, s2;

    void enqueue(int val) {
        s1.push(val);
    }

    int dequeue() {
        if (s1.isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }

        // move s1 -> s2
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }

        // get front element
        int ans = s2.pop();

        // move back s2 -> s1
        while (!s2.isEmpty()) {
            s1.push(s2.pop());
        }

        return ans;
    }

    void printQueue() {
        cout << "Queue (front to rear): ";

        // move to s2 to display in correct order
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }

        while (!s2.isEmpty()) {
            int x = s2.pop();
            cout << x << " ";
            s1.push(x);
        }

        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20

    q.enqueue(40);

    q.printQueue(); // 30 40

    return 0;
}