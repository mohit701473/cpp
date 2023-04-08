#include<iostream>
#include<queue>
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

void inorder(Node* root){ // left root right
    if(root == NULL)
        return ;

    inorder(root -> left) ;
    cout<<root -> data<<" ";
    inorder(root -> right) ;
}

void preorder(Node* root){ // root left right
    if(root == NULL)
        return ;

    cout<<root -> data<<" ";
    preorder(root -> left) ;
    preorder(root -> right) ;
}


void postorder(Node* root){ // left right root
    if(root == NULL)
        return ;

    postorder(root -> left) ;
    postorder(root -> right) ;
    cout<<root -> data<<" ";
}



void print(Node* root){
    queue<Node*> q ;
    q.push(root) ;
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;

    }
}

int main() 
{
    Node* root = NULL ; 
    root = buildTree(root) ;  // 1 3 7 -1 -1 11 -1 -1 5  17 -1 -1 -1
    levelOrderTraversal(root) ;

    cout<<"inorder traversal"<<endl;
    inorder(root) ;
    cout <<endl;

    cout<<"preorder traversal"<<endl;
    preorder(root) ;
    cout <<endl;

    cout<<"postorder traversal"<<endl;
    postorder(root) ;
    cout <<endl;


}