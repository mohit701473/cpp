// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.

// Approch 1
// T.C. = O(n^2)  bcz in diametre call function we also call height function
class Solution {
  public:
  
    int height(struct Node* node){ 
         if(node == NULL)
            return 0 ;

        int leftHeight = height(node -> left) ;
        int rightHeight = height(node -> right) ;

        int ans = max(leftHeight, rightHeight) + 1 ;

        return ans ;
    }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL)
            return 0 ;
            
        int op1 = diameter(root -> left) ;
        int op2 = diameter(root -> right) ;
        int op3 = height(root -> left) + height(root -> right) + 1 ;
        
        int ans = max(op1 , max(op2, op3)) ;
        
        return ans ;
    }
};