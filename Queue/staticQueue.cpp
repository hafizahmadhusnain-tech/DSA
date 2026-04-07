#include <iostream>
using namespace std;
#define s 5
class Queue {
private:
int arr[s];
int f,r;
public:
Queue(){
    f = -1;
    r = -1;
}
bool isFull(){
    return r == s-1;
}
bool isEmpty(){
    return f == -1;
}
void Enqueue(int val){
    if(isFull()){
        cout << "Queue is Full" << endl;
        return;
    }
    if(isEmpty()) f = 0;
    arr[++r] = val;
}

void Dequeue(){
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    if(f == r) f = r = -1;
    else f++;
    
}
int peek(){
    if(isEmpty()){
        cout << "Queue is Empty" << endl;
        return -1;
    }
    return arr[f];
}
};

int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    cout << q.peek() << endl;
    q.Dequeue();
    cout << q.peek() << endl;
    return 0;
}