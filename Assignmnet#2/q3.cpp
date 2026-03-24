#include <iostream>
using namespace std;
class CircularQueue{
    private:
    string *arr;
    int f,r,size;
    public:
    CircularQueue(int s){
        arr = new string[s];
        f = r = -1;
        size = s;
    }
    bool isFull(){
        return f == (r+1) % size;
    }
    bool isEmpty(){
        return f == -1;
    }
    void Enqueue(string val){
        if(isFull()){
            cout << "Queue is Full!\n"; return;
        }
        if(isEmpty()){
            f = r = 0;
        }
        else{
            r = (r+1) % size;
        }
        arr[r] = val;
        cout << "Inserted!\n";
    }
    void Dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty!\n";return;
        }
        if(f==r){
            f = r = -1;
        }
        else{
            f = (f+1)%size;
        }
        cout << "Deleted from Queue\n";
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is Empty!\n"; return;
        }
        int i = f;
        while(true){
            cout << arr[i] << " ";
            if(i==r)break;
            i = (i+1)%size;
        }
    }
};
int main(){
    CircularQueue cQ(3);
    cQ.Enqueue("P1");
    cQ.Enqueue("P2");
    cQ.Enqueue("P3");
    cQ.Dequeue();
    cQ.Enqueue("P4");
    cQ.display();

    return 0;
}