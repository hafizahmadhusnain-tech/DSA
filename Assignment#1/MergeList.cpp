#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node* next;
    Node(int id){
        this->id = id;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }

    void addNode(int id){
        Node* newNode = new Node(id);
        if(head==NULL){
            head = newNode;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next !=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    static LinkedList mergeLists(LinkedList &list1, LinkedList &list2){
        LinkedList mll;
        if(list1.head== NULL && list2.head==NULL){
            cout << "Both Lists are Empty!";
            return mll;
        }
        else if (list1.head==NULL){
            mll.head = list2.head;
            return mll;
        }
        else if (list2.head==NULL){
            mll.head = list1.head;
            return mll;
        }
        else {
            Node* temp1 = list1.head;
            Node* temp2 = list2.head;
            
            while(temp1!=NULL && temp2!=NULL){

                if(temp1->id < temp2->id){
                    mll.addNode(temp1->id);
                    temp1 = temp1->next;
                }
                else {
                    mll.addNode(temp2->id);
                    temp2 = temp2->next;
                }
            }

            while (temp1!=NULL){
                mll.addNode(temp1->id);
                temp1 = temp1->next;
            }
            while (temp2!=NULL){
                mll.addNode(temp2->id);
                temp2 = temp2->next;
            }  
        }
        return mll;
        
    }  
    
    void displayList(){
        if(head==NULL){
            cout << "List is Empty!"<< endl;
            return;
        }else{
        Node* temp = head;
        
        while(temp!=NULL){
            
                cout << temp->id << " -->";
                temp = temp->next;
        }
        cout << " NULL";
            
        }
    }   
       
};


int main(){
    LinkedList list1;
    list1.addNode(1);
    list1.addNode(3);
    list1.addNode(5);
    list1.addNode(50);
    list1.addNode(60);
    LinkedList list2;
    list2.addNode(2);
    list2.addNode(4);
    list2.addNode(6);
    list2.addNode(7);
    list2.addNode(9);
    
    LinkedList mll =LinkedList::mergeLists(list1,list2); 
    cout << "List 1: ";
    list1.displayList();
    cout << "\nList 2: ";
    list2.displayList();
    cout << "\nMerged List: ";
    mll.displayList();
    
    return 0;
}