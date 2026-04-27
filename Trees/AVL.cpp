#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val){
        data = val;
        left = right = NULL;
        height = 1;
    }

};

int getHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}

int getBalance(Node* root){
    if(root==NULL){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

void InOrder(Node* root){
    if(root==NULL)
    return;
    InOrder(root->left);
    cout<< root->data << " ";
    InOrder(root->right);
}

Node* RightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node* LeftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;

    return y;
}

Node* insertNode(Node* root,int key){
    if(root==NULL){
        return new Node(key);
    }

    if(key < root->data){
        root->left = insertNode(root->left,key);
    }
    else if(key > root->data){
        root->right = insertNode(root->right,key);
    }
    else{
        return root;
    }

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));

    int balance = getHeight(root->left) - getHeight(root->right);

    if(balance >1 && key < root->left->data){
        return RightRotate(root);
    }
     if(balance < 1 && key > root->right->data){
        return LeftRotate(root);
    }
     if(balance > 1 && key > root->left->data){
        root = LeftRotate(root->left);
        return RightRotate(root);
    }
     if(balance < -1 && key < root->right->data ){
        root = RightRotate(root->right);
        return LeftRotate(root);
    }
    
        return root;
    
}

int main(){
    Node* root = NULL;
    root = insertNode(root,30);
    root = insertNode(root,20);
    root = insertNode(root,10);
    root = insertNode(root,25);
    root = insertNode(root,28);
    cout << "InOrder Traversal of AVL Tree: ";
    InOrder(root);
    cout << endl;

    return 0;

}