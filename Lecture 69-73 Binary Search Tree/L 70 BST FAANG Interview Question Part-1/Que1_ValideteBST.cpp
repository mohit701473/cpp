
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the BST).
class Solution
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    bool validBST(Node* root, int min, int max){
        if(root == NULL)
            return true ;
            
        if(root->data > min && root -> data < max){ // This condition check only for root data 
            // Now chek for subtree 
            bool left = validBST(root -> left, min, root -> data) ;
            bool right = validBST(root -> right, root -> data, max) ;
            return left && right ;
        }
        
        else return false ;
    }
    bool isBST(Node* root) 
    {
        return validBST(root, INT_MIN, INT_MAX) ;
    }
};