#include <iostream>
using namespace std;

// // Activity 1
// class Stack{
//     int next;
//     char* arr;
//     int size;

//     public:
//      Stack(int n){
//         size = n;
//         arr = new char[size];
//         next = -1;
//     }
//     void push(char val){
//         if(next==size-1){
//         cout << "Stack overflowed!\n";
//         return;
//     }
//         else{
//             arr[++next] = val;
//         }
//     }
//     char pop(){
//         if(next==-1){
//             cout << "stack underflow!\n";
//             return '\0';
//         }
//         else{
//             return arr[next--];
//         }
//     }

// };

// int main(){
//     Stack stack(5);
//     stack.push('A');
//     stack.push('B');
//     stack.push('C');
//     stack.push('D');
//     stack.push('E');
//     stack.push('F');

//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;

//     return 0;
// }

// // Activity 2

// struct Node
// {
//     int data;
//     Node* next;
//     Node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// class Stack{
//     Node* top;
//     public:
//     Stack(){
//         top = NULL;
//     }

//     void push(int val){
//         Node* newNode = new Node(val);
//         newNode->next = top;
//         top = newNode;         
//     }

//     int pop(){
//         if (top==NULL){
//             cout << "Stack underflowed!\n";
//             return -1;
//         }
//         else{
//             Node* temp = top;
//             top = top->next;
//             int r = temp->data;
//             delete temp;
//             return r;
//         }
//     }


// };

// int main(){
//     Stack* stack = new Stack();
//     stack->push(30);
//     stack->push(20);
//     stack->push(10);

//     cout << stack->pop() << endl;
//     cout << stack->pop() << endl;
//     cout << stack->pop() << endl;
//     cout << stack->pop() << endl;

//     return 0;
// }

// Activity 3
struct Node
{
    char data;
    Node* next;
    Node(char val){
        data = val;
        next = NULL;
    }
};

class Stack{
    int size;
    char* arr;
    int top;
    public:
    Stack(){
        size=100;
        top=-1;
        arr = new char(size);
    }

    bool isFull(){
        return top==size-1;
 
    }
    bool isEmpty(){
        return top==-1;
    }

    void push(char x){
        if (isFull()){
            cout << "Stack is Full!\n";
            return;
        }
        arr[++top] = x;
    }

    char pop(){
        if (isEmpty()){
            cout << "Stack is underflow\n";
            return '\0';
        }
        return arr[top--];

    }

};

int main(){
    Stack* stack = new Stack();
    stack->push('E');
    stack->push('D');
    stack->push('C');
    stack->push('B');
    stack->push('A');

    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;

    cout << stack->isEmpty() <<endl;
    cout << stack->isFull() << endl; 

    return 0;
}