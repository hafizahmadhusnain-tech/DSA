#include <iostream>
using namespace std;
class Deque {
    int *arr;
    int front, rear;
    int size;

public:
    Deque(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque Full!\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }

        arr[front] = x;
        cout << "Inserted at Front: " << x << endl;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque Full!\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
        cout << "Inserted at Rear: " << x << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Empty!\n";
            return;
        }

        cout << "Deleted from Front: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Empty!\n";
            return;
        }

        cout << "Deleted from Rear: " << arr[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);

    dq.insertFront(1);   
    dq.insertRear(2);    
    dq.insertFront(3);   
    dq.deleteRear();     
    dq.insertRear(4);    

    dq.display();

    return 0;
}