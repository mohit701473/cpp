

// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(Height of the BST).


// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root == NULL) {
        return root ;
    }
    
    
    if(X == root -> data) {
        // 0 child 
        if(root -> left == NULL && root -> right == NULL) {
            delete root ;
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