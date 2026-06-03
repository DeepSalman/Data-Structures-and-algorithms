#include<iostream>
using namespace std;

/*
========================================
CIRCULAR QUEUE (MANUAL IMPLEMENTATION)
========================================
*/
class Queue {
public:
    int arr[100];
    int front = -1;
    int rear = -1;
    int size = 100;

    void enqueue(int val) {
        if ((rear + 1) % size == front) {
            cout << "Queue overflow\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
            arr[rear] = val;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = val;
        }
    }

    int dequeue() {
        if (front == -1) {
            return -1;
        }

        int val = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return val;
    }

    bool isEmpty() {
        return (front == -1);
    }
};

/*
========================================
STACK USING TWO QUEUES
========================================
*/
class StackWithQueue {
public:
    Queue q1, q2;

    /*
    PUSH:
    - Move all q1 → q2
    - Insert new element into q1
    - Move back q2 → q1
    */
    void push(int val) {
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        q1.enqueue(val);

        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
    }

    /*
    POP:
    - Just dequeue from q1
    */
    int pop() {
        return q1.dequeue();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

/*
========================================
FUNCTION: DECIMAL → BINARY USING STACK
========================================
*/
void convertToBinary(int n) {
    StackWithQueue s;

    if (n == 0) {
        cout << "Binary: 0\n";
        return;
    }

    while (n > 0) {
        s.push(n % 2);
        n = n / 2;
    }

    cout << "Binary: ";

    while (!s.isEmpty()) {
        cout << s.pop();
    }

    cout << endl;
}

/*
========================================
FUNCTION: SORT USING STACK
========================================
(Simple insertion sort logic using stack)
========================================
*/
void sortUsingStack(int arr[], int n) {
    StackWithQueue s;

    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
    }

    int temp[100];
    int idx = 0;

    // transfer stack → array
    while (!s.isEmpty()) {
        temp[idx++] = s.pop();
    }

    // simple bubble sort
    for (int i = 0; i < idx; i++) {
        for (int j = i + 1; j < idx; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < idx; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

/*
========================================
MAIN FUNCTION
========================================
*/
int main() {
    int n;

    cout << "Enter decimal number: ";
    cin >> n;

    convertToBinary(n);

    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[100];

    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sortUsingStack(arr, size);

    return 0;
}