#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
   int data;
   Node* left;
   Node* right;

   Node(int val){
    data = val;
    left = NULL;
    right = NULL;
   }
};

static int index = -1;
Node* binaryTree(vector<int> preOrder){
    index++;
    if(preOrder[index]==-1){
        return NULL;
    }
    Node* root = new Node(preOrder[index]);
    root->left = binaryTree(preOrder);
    root->right = binaryTree(preOrder);
    return root;
}
void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* l = q.front();
        q.pop();
        if(l==NULL){
            if(!q.empty()){
                q.push(NULL);
                cout<<endl;
                continue;
            }
            break;

        }
        cout << l->data << " ";
        if(l->left!=NULL){
            q.push(l->left);
        }
        if(l->right!=NULL){
            q.push(l->right);
        }
    }
    cout << endl;

}


int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = binaryTree(preorder);
    cout << "Pre Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "In Order Traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Post Order Traversal: ";
    postOrder(root);
    cout << endl << "Level Order Traversal:\n";
    LevelOrderTraversal(root);

    return 0;
}