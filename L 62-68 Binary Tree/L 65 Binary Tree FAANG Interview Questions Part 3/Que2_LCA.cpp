// Lowest Common Ancestor in a Binary Tree


// Approch 2
// Expected Time Complexity:O(N).
// Expected Auxiliary Space:O(Height of Tree).
Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case
       if(root == NULL)
            return NULL ;
            
        if(root -> data == n1 || root -> data == n2)
            return root ;
            
        Node* leftAns = lca(root -> left, n1, n2) ;
        Node* rightAns = lca(root -> right, n1, n2) ;
        
        if(leftAns != NULL && rightAns != NULL)
            return root ;
            
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns ;
            
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns ;
            
        else return NULL ;
    }