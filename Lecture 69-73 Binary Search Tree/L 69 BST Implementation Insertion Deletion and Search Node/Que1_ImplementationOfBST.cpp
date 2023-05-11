#include<iostream>
#include<queue>
using namespace std ;

class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;
    
    // Constructor creation
    Node(int d){
        this -> data = d ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};


Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data) ;
        return root ;
    }

    if(data > root -> data){
        // Insert into right of the root 
        root -> right = insertIntoBST(root -> right, data) ;
    }

    else{
        // Insert into left of the root 
        root -> left = insertIntoBST(root -> left, data) ;
    }

    return root ;
}

void takeInput(Node* &root){
    int data ;
    cin>> data ;

    while(data != -1){
        root = insertIntoBST(root, data) ;
        cin>> data ;
    }
}

void levelOrderTraversal(Node* root){

    if(root == NULL){
        cout<<"NULL" ;
        return ;
    }

    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;

        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL) ;
        }

        else{
            cout<<temp -> data << " ";
            if(temp -> left)
                q.push(temp -> left) ;

            if(temp -> right) 
                q.push(temp -> right) ;
        }
    }
}

void inorder(Node* root){
    if(root == NULL)
        return ;

    inorder(root -> left) ;
    cout<<root -> data<< " " ;
    inorder(root -> right) ;
}

void preorder(Node* root){
    if(root == NULL)
        return ;

    cout<<root -> data<< " " ;
    preorder(root -> left) ;
    preorder(root -> right) ;
}


void postorder(Node* root){
    if(root == NULL)
        return ;

    postorder(root -> left) ;
    postorder(root -> right) ;
    cout<<root -> data<< " " ;
}


int main(){
    Node* root = NULL ;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root) ;

    cout<<"Print Level order traversal of BST"<<endl;
    levelOrderTraversal(root) ;

    cout<<"Print Inorder traversal of BST"<<endl;
    inorder(root) ;
    cout<<endl;

    cout<<"Print Preorder traversal of BST"<<endl;
    preorder(root) ;
    cout<<endl;

    cout<<"Print Postorder traversal of BST"<<endl;
    postorder(root) ;
    cout<<endl;
}

