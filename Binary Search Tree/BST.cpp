#include<iostream>
#include<queue>
using namespace std ;

class Node{

    public:
    int data ;
    Node* left ;
    Node* right ;

    Node(int d){
        this -> data = d ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};




void levelOrderTraversal(Node* root){
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;

        if(temp == NULL){
            //Purana level complete traverse
            cout<<endl ;
            if(!q.empty()) {
                //queue still has some child
                q.push(NULL) ;
            }
        }

        else {
            cout<<temp -> data <<" ";
            if(temp -> left) {
                q.push(temp->left) ;
            }

            if(temp -> right) {
                q.push(temp -> right) ;
            }
        }
    }
}


void inorder(Node* root , int arr[] ){
    //base case
    if(root == NULL){
        return ;
    }

    inorder(root -> left) ;
    cout<<root -> data <<" " ;
    inorder(root -> right) ;
}


void preorder(Node* root) {
    //base csea
    if(root == NULL){
        return ;
    }

    cout<<root -> data <<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}

void postorder(Node* root) {
    //base case
    if(root == NULL){
        return ;
    }

    postorder(root->left) ;
    postorder(root->right) ;
    cout<<root -> data <<" " ;
}



Node* insertIntoBST(Node* root , int d){

    //Base case
    if(root == NULL){
        root = new Node(d) ;
        return root ;
    }

    if(d > root -> data ){
        //insert to the right part of the root
        root -> right = insertIntoBST(root->right , d) ;
    }
    else{
        //insert to the left part of the root
        root -> left = insertIntoBST(root->left , d) ;
    }

    return root ;
}


void takeInput(Node* &root){

    int data ;
    cin >> data ;

    while(data != -1){
        root = insertIntoBST(root,data) ;
        cin >> data ;
    }
}


/* for searching the node in BST by the recursion has the time complexity 
in worst case is O(n) & space complexcity is O(n) so we use the itrative solution 
in the function findKeyInBST */
bool searchKeyInBST(Node* root , int key){

    if(root == NULL){
        return false ;
    }
 
    if(key == root -> data){
        return true ;
    }

    else if(key < root -> data) {
        searchKeyInBST(root -> left , key) ;
    }

    else {
        searchKeyInBST(root -> right , key ) ;
    }
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

Node* maxValue(Node* root) {
    Node* temp = root ;

    while(temp -> right != NULL){
        temp = temp -> right ;
    }

    return temp ;
}


Node* deleteFromsBST(Node* root , int val){

    //Base case 
    if((root == NULL)) {
        return root ;
    }

    if(root->data == val) {
        //0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root ;
            return NULL ;
        }

        //1 child
        
        //left child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left ;
            delete root ;
            return temp ;
        }

        //right child
        if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right ;
            delete root ;
            return temp ;
        }

        //2 child
        if(root -> left != NULL && root -> right != NULL){
            int mini = minValue(root -> right) -> data ;
            root -> data = mini ;
            root -> right = deleteFromsBST(root -> right , mini) ;
            return root ;
        }
    }

    else if(val < root -> data){
        //left part me jao
        root -> left = deleteFromsBST(root -> left , val) ;
        return root ;
    }

    else {
        //right part me jao
        root -> right = deleteFromsBST(root -> right , val) ;
        return root ;
    }
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root == NULL) {
        return root ;
    }
    
    
    if(X == root -> data) {
        // 0 child 
        if(root -> left == NULL && root -> right == NULL) {
            //delete root ;
            return NULL ;
        }
        
        //1 child 
        if(root -> left == NULL && root -> right != NULL) {
            Node* temp = root -> right ;
            delete root ;
            return temp ;
        }
        
        if(root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left ;
            delete root ;
            return temp ;
        }
        
        //2 child ;
        if(root -> left != NULL && root -> right != NULL) {
            Node* temp = root -> right ;
            while(temp -> left != NULL) {
                temp = temp -> left ;
            }
            root -> data = temp -> data ;
            root -> right = deleteNode(root -> right , temp -> data) ;
            return root ;
        }
    }
    
    else if(X > root -> data){
        root -> right = deleteNode(root -> right , X) ;
        return root ;
    }
    else{
        root -> left = deleteNode(root -> left , X) ;
        return root ;
    }
}


Node* findNodeInBST(Node* root , int key) {

    Node* temp = root ;

    while(temp != NULL){
        if(key == temp -> data){
            return temp ;
        }

        else if(key < temp -> data){
            temp = temp -> left ;
        }

        else {
            temp = temp -> right ;
        }
    }

    return NULL ;
}



 // returns the inorder successor of the Node x in BST (rooted at 'root')
 // T.C = O(height of the tree) 
 // S.C = O(1) 
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        
        Node* successor = NULL ;
        
        while(root != NULL) {
            if(x -> data >= root -> data) {
                root = root -> right ;
            }
            
            else {
                successor = root ;
                root = root -> left ;
            }
        }
        
        return successor ;
    }


int main()
{
    Node* root = NULL ;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root) ;

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root) ;

    int arr[1000] ;
    cout<<endl<<"Inorder Traversal"<<endl;
    inorder(root) ;

    // cout<<endl<<"preorder Traversal"<<endl;
    // preorder(root) ;

    // cout<<endl<<"postorder Traversal"<<endl;
    // postorder(root) ;

    int key ; 
    cout<<"enter the key"<<endl;
    cin>>key ;
    // // bool ans = findKeyInBST(root , key) ;
    // // cout<<ans<<endl;
    deleteFromsBST(root , key) ;

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root) ;

}