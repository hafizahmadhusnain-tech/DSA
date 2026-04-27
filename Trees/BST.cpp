#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data  = val;
        left = right = NULL;
    }
};

Node* insert(Node* &root,int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(root->data > val)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right,val);
    return root;
}

bool search(Node* root,int key){
    if( root == NULL)
    return false;
    if (root->data == key)
    return true;
    if(root->data>key)
    return search(root->left,key);
    else
    return search(root->right,key);
}

Node* minVal(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root,int key){
    if(root==NULL) return NULL;

    if(key < root->data){
        root->left = deleteNode(root->left,key);
    }
    else if (key> root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minVal(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
return root;
}

void InOrder(Node* root){
    if(root==NULL)
    return;
    InOrder(root->left);
    cout<< root->data << " ";
    InOrder(root->right);
}


int main(){
    Node* root = NULL;
    int arr[] = {50,30,70,20,40,60,80};

    for(int x : arr)
        root = insert(root,x);
    cout << "Tree after insertion: ";    
    InOrder(root);
    cout << endl;
    root = deleteNode(root,30);

    if(search(root,60))
        cout<<"Value Found\n";
    else
        cout<<"Value Not Found\n";
    cout << "Tree after deletion: ";    
    InOrder(root);
    cout << endl;
    return 0;
}