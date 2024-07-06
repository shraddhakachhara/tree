#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* BuildTree(Node* root){
    int data;
    cout<<"enter the node:"<<endl;
    cin>>data;
    root=new Node(data);
    
    if(data==-1){
        return NULL;
    }
    cout<<"enter the left node of "<<data<<endl;
    root->left=BuildTree(root->left);
    cout<<"enter the right node of "<<data<<endl;
    root->right=BuildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp=q.front();
        // cout<<temp->data;
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }   
    
}

int main(){
    Node* root=NULL;
    root=BuildTree(root);
    
    levelOrderTraversal(root);
}
