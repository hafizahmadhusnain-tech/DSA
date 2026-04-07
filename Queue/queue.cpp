#include <iostream>
using namespace std;

// Dynamic Queue using Linked List
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{

    Node* f;
    Node* r;

    public:
    Queue(){
        f = NULL;
        r = NULL;
    }

    bool isEmpty(){
        return f == NULL;
    }
    
    void Enqueue(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            f = newNode;
            r = newNode;
            return;
        }
        r->next = newNode;
        r = newNode;
    }


void Dequeue(){
    if(isEmpty()){
        return;
    }
    Node* temp = f;
    f = f->next;
    if (f == NULL){
        r = NULL;
    }
    delete temp;
    }

void display(){
    if(f==NULL){
        return;
    }
    Node* temp = f;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
};

int main(){
    Queue q;
    q.Enqueue(5);
    q.Enqueue(4);
    q.Enqueue(3);
    q.Enqueue(2);
    q.Enqueue(1);
    q.Dequeue();
    q.display();

}
