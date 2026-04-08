#include <iostream>
using namespace std;

struct Patient {
    string name;
    int priority;
};

class PriorityQueue {
private:
    Patient *arr;
    int cap;
    int size;

public:
    PriorityQueue(int s) {
        cap = s;
        arr = new Patient[cap];
        size = 0;
    }

    void insert(string n, int p) {
        if (size == cap) {
            cout << "Queue is Full.\n";
            return;
        }

        int i;
        for (i = size - 1; i >= 0 && arr[i].priority < p; i--) {
            arr[i + 1] = arr[i]; // shift right
        }

        arr[i + 1].name = n;
        arr[i + 1].priority = p;
        size++;
    }

    void treatPatient() {
        if (size == 0) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Treating: " << arr[0].name << endl;

        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }

        size--;
    }

    void display() {
        cout << "\nPriority Queue (High to Low):\n";
        for (int i = 0; i < size; i++) {
            cout << arr[i].name << " (" << arr[i].priority << ")\n";
        }
    }
};

int main() {
    PriorityQueue pQ(4);
    pQ.insert("Ali", 2);
    pQ.insert("Saqlain", 7);
    pQ.insert("Fawad", 1);
    pQ.insert("Shadab", 5);
    pQ.display();
    cout << "\nAfter Treating:\n";
    pQ.treatPatient();
    pQ.display();
    return 0;
}