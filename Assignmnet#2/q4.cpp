#include <iostream>
using namespace std;

struct Patient {
    string name;
    int priority;
};

class PriorityQueue {
private:
    Patient *arr;
    int size;
    int cap;

public:
    PriorityQueue(int s) {
        size = s;
        arr = new Patient[size];
        cap = 0;
    }

    void insert(string n, int p) {
        if (cap == size) {
            cout << "Queue is Full.\n";
            return;
        }

        int i;
        for (i = cap - 1; i >= 0 && arr[i].priority < p; i--) {
            arr[i + 1] = arr[i]; // shift right
        }

        arr[i + 1].name = n;
        arr[i + 1].priority = p;
        cap++;
    }

    void treatPatient() {
        if (cap == 0) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Treating: " << arr[0].name << endl;

        for (int i = 1; i < cap; i++) {
            arr[i - 1] = arr[i];
        }

        cap--;
    }

    void display() {
        cout << "\nPriority Queue (High to Low):\n";
        for (int i = 0; i < cap; i++) {
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