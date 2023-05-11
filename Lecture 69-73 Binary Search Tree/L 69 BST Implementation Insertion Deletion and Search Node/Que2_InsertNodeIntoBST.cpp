#include<iostream>
#include<queue>
using namespace std ;


class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    // Create constructor
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
        root -> right = buildBST(root -> right, data) ;
    }

    else{
        // Insert into left of the root
        root -> left = buildBST(root -> left, data) ;
    }

    return root ;
}

void takeInput(Node* &root){
    int data ;
    cin >> data ;

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


int main() {
    Node* root = NULL ;
    cout<<"enter data to create BST"<<endl;
    takeInput(root) ;

    cout<<"Print Level Order Traversal of BST"<<endl;
    levelOrderTraversal(root) ;

    int node ;
    cout<<"enter data of new Node"<<endl;
    cin >> node ;
    insertIntoBST(root, node) ;

    cout<<"Print Level Order Traversal of BST"<<endl;
    levelOrderTraversal(root) ;

}