#include<iostream>
#include<queue>

using namespace std ;

class Node {

    public:
    int data ;
    Node* left ;
    Node* right ;

    Node (int d) {
        this -> data = d ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};

void levelOrderTraversal(Node* root) {

    if(root == NULL) {
        cout<<"empty BST"<<endl;
    }
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()) {
        Node* temp = q.front() ;
        q.pop() ;

        if(temp == NULL) {
            cout<<endl ;
            if(!q.empty()) {
                q.push(NULL) ;
            }    
        }

        else {
            cout<<temp -> data <<" " ;

            if(temp -> left) {
                q.push(temp -> left) ;
            }

            if(temp -> right) {
                q.push(temp -> right) ;
            }
        }
    }
}


Node* insertIntoBst(Node* &root , int d) {
    Node* temp = new Node(d) ;
    if(root == NULL) {
        root = temp ;
        return root ;
    }

    if(d > root -> data) {
        root -> right = insertIntoBst(root -> right , d) ;
    }

    else {
        root -> left = insertIntoBst(root -> left , d) ;
    }

    return root ;
}


void inorder(Node* root) {
    if(root == NULL) {
        //cout<<"BST is empty"<<endl;
        return ;
    }

    inorder(root -> left) ;
    cout<<root -> data<<" " ;
    inorder(root -> right) ;

    return ;
}

void preorder(Node* root) {
    if(root == NULL) {
        //cout<<"BST is empty"<<endl;
        return ;
    }

    
    cout<<root -> data<<" " ;
    preorder(root -> left) ;
    preorder(root -> right) ;

    return ;
}


void postorder(Node* root) {
    if(root == NULL) {
        //cout<<"BST is empty"<<endl;
        return ;
    }

    
    postorder(root -> left) ;
    postorder(root -> right) ;
    cout<<root -> data<<" " ;

    return ;
}


bool findKeyInBST(Node* root , int key) {

    Node* temp = root ;

    while(temp != NULL){
        if(key == temp -> data){
            return true ;
        }

        else if(key < temp -> data){
            temp = temp -> left ;
        }

        else {
            temp = temp -> right ;
        }
    }

    return false ;
}

Node* minValue(Node* root) {
    Node* temp = root ;

    while(temp -> left != NULL){
        temp = temp -> left ;
    }

    return temp ;
} 

Node* deleteFromBST(Node* root , int val) {
    if(root == NULL) {
        return root ;
    }


    if(root -> data == val) {
        // 0 child 
        if(root -> left == NULL && root -> right == NULL) {
            cout<<"delete"<<endl;
           //root = NULL ;
            return NULL ;
        }

        // 1 child
        if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right ;
            delete root ;
            return temp ;
        }
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left ;
            delete root ;
            return temp ;
        }

        // 2 child 
        if(root -> left != NULL && root -> right != NULL) {
            Node* temp = minValue(root -> right) ;
            int mini = temp -> data ;
            root -> data = mini ;
            deleteFromBST(root -> right , mini) ;
            return root ;
        }
    }

    else if(val > root -> data) {
        root -> right = deleteFromBST(root -> right , val) ;
        return root ;
    }

    else {
        root -> left = deleteFromBST(root -> left , val) ;
        return root ;
    }
}


int main() 
{
    Node* root = NULL ;

    int n ;
    cout << " enter the no. of the nodes"<<endl;
    cin>>n ;
    for(int i=1 ; i<=n ; i++){
        int data ;
        cout<<"enter the data"<<endl;
        cin>>data ;
        root = insertIntoBst(root , data) ;
    }

    cout<<"inorder"<<endl;
    inorder(root) ;
    cout<<endl;

    cout<<"preorder"<<endl;
    preorder(root) ;
    cout<<endl;

    cout<<"postorder"<<endl;
    postorder(root) ;
    cout<<endl;

    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root) ;
    cout<<endl;

    int key ;
    cout<<"enter the key " ;
    cin>>key ;
    // if(searchKey(root , key)) {
    //     cout<<"key found" ;
    // }

    // else{
    //     cout<<"key not found" ;
    // }

    root = deleteFromBST(root , key) ;
    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root) ;
    cout<<endl;
}