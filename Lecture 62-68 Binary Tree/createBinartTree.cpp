#include<bits/stdc++.h>
using namespace std ;

class Node {
    public:
    int data ;
    Node* left ;
    Node* right ;

    // constructor
    Node(int d){
        this -> data = d ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};

Node* buildTree(Node* root) {
    
    int data ;
    cout<<"enter data"<<endl;
    cin>> data ;

    if(data == -1){
        return NULL ;
    }

    root = new Node(data) ;

    // left tree
    cout<<"insert data of inserting left of "<<root -> data<<endl; 
    root -> left = buildTree(root -> left) ;

    // right  tree
    cout<<"insert data of inserting right of "<<root -> data<<endl; 
    root -> right = buildTree(root -> right) ;
    
    return root ;
}

void levelOrderTraversal(Node* root){

    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;

        if(temp == NULL){  // mtlb ki purana level complete ho chuka h
            cout<<endl;
            if(!q.empty())
                q.push(NULL) ;
        }

        else{
            cout<<temp -> data <<" ";
            if(temp -> left) // jab root ka left NULL na ho to queue m push kr do
                q.push(temp -> left) ;
            
            if(temp -> right)  // jab queue ka riught NULL na ho to queue m push kr do
                q.push(temp -> right) ;
        }
    }
}


void buildTreeFromLevelOrderTraversal(Node* &root){
    queue<Node*> q ;
    cout<<"enter data for the root Node"<<endl;
    int data ;
    cin>> data ;
    root = new Node(data) ;
    q.push(root) ;

    while(!q.empty()) {
        Node* temp = q.front() ;
        q.pop() ;

        cout<<"enter data for left of "<<temp -> data<<endl;
        int leftData ;
        cin>> leftData ;

        if(leftData != -1){
            temp -> left = new Node(leftData) ;
            q.push(temp -> left) ;
        }

        cout<<"enter data for right of "<<temp -> data<<endl;
        int rightData ;
        cin>> rightData ;

        if(rightData != -1){
            temp -> right = new Node(rightData) ;
            q.push(temp -> right) ;
        }
    }
}


int main() 
{
    Node* root = NULL ; 
    //root = buildTree(root) ;  // 1 3 7 -1 -1 11 -1 -1 5  17 -1 -1 -1  or 
    buildTreeFromLevelOrderTraversal(root) ;
    levelOrderTraversal(root) ;

}