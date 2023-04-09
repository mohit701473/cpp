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

void recursive_inorder(Node* root){ // left root right
    if(root == NULL)
        return ;

    recursive_inorder(root -> left) ;
    cout<<root -> data<<" ";
    recursive_inorder(root -> right) ;
}

void itrative_inorder(Node* root){
    if(root == NULL){
        cout<<"height of tree is zeor"<<endl;
        return ;
    }

    stack< Node* > s ;
    s.push(root) ;
    bool flage = false ; 

    while(!s.empty()){

        if(root == NULL){

            root = s.top() ;
            s.pop() ;
            cout<<root -> data <<" " ;
            root = root -> right ;

            if(root != NULL){
                s.push(root) ;
               flage = false ;
            }
        }

        else{
            if(flage){
                s.push(root) ;
            }
            root = root -> left ;
            flage = true ;

        }
    }
}



void recursive_preorder(Node* root){ // root left right
    if(root == NULL)
        return ;

    cout<<root -> data<<" ";
    recursive_preorder(root -> left) ;
    recursive_preorder(root -> right) ;
}

void itrative_preorder(Node* root){
   if(root == NULL){
        cout<<"height of tree is zeor"<<endl;
        return ;
    } 

    

}

void recursive_postorder(Node* root){ // left right root
    if(root == NULL)
        return ;

    recursive_postorder(root -> left) ;
    recursive_postorder(root -> right) ;
    cout<<root -> data<<" ";
}




int main() 
{
    Node* root = NULL ; 
    root = buildTree(root) ;  // 1 3 7 -1 -1 11 -1 -1 5  17 -1 -1 -1  or 
    levelOrderTraversal(root) ;

    cout<<"recursive_inorder traversal"<<endl;
    recursive_inorder(root) ;
    cout <<endl;

    // cout<<"recursive_preorder traversal"<<endl;
    // recursive_preorder(root) ;
    // cout <<endl;

    // cout<<"recursive_postorder traversal"<<endl;
    // recursive_postorder(root) ;
    // cout <<endl;

    cout<<"itrative_inorder traversal"<<endl;
    itrative_inorder(root) ;
    cout<<endl;


}