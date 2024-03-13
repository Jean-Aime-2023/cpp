#include <iostream>
#define SIZE 1000

class Queue {
    int front, rear;
public:
    int arr[SIZE];

    Queue() { front = -1; rear = -1; }
    bool enqueue(int x);
    int dequeue();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
};

bool Queue::enqueue(int x) {
    if (isFull()) {
        std::cout << "Queue Overflow";
        return false;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    arr[rear] = x;
    return true;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue Underflow";
        return -1;
    }
    int item = arr[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return item;
}

int Queue::getFront() {
    if (isEmpty()) return -1;
    return arr[front];
}

int Queue::getRear() {
    if (isEmpty()) return -1;
    return arr[rear];
}

bool Queue::isEmpty() {
    return (front == -1);
}

bool Queue::isFull() {
    return ((rear + 1) % SIZE == front);
}

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Front element is " << q.getFront() << std::endl;
    std::cout << "Dequeued element from queue is " << q.dequeue() << std::endl;
    return 0;
}
