#include<iostream>
using namespace std;

class Queue {
    int size;
    int *arr;
    int front;
    int rear;

public:
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(int val) {
        if(isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        arr[rear] = val;
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    void peek() {
        if(isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << arr[front] << endl;
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();   // 10 20 30

    q.dequeue();
    q.display();   // 20 30

    q.peek(); 
    return 0;     // prints 20
}
