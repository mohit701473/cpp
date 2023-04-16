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


// Approch 2
// T.C. = O(n)
// S.C. = O(height) bcz 
class Solution {
  public:
  
    pair<int, int> diameterFast(Node* root){
        // base case 
        if(root == NULL){
            pair<int, int> p = make_pair(0,0) ;
            return p ;
        }
        
        pair<int, int> left = diameterFast(root -> left) ;
        pair<int, int> right = diameterFast(root -> right) ;
        
        int op1 = left.first ;
        int op2 = right.first ;
        int op3 = left.second + right.second + 1;
        
        pair<int, int> ans ;
        ans.first = max(op1, max(op2, op3)) ; // this is bcz first store maximum diameter
        ans.second = max(left.second, right.second) + 1 ;
        
        return ans ;
        
    }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       
       return diameterFast(root).first ;
    }
};



// Leet Code
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

class Solution {
public:

   pair<int, int> diameterFast(TreeNode* root){
        // base case 
        if(root == NULL){
            pair<int, int> p = make_pair(0,0) ;
            return p ;
        }
        
        pair<int, int> left = diameterFast(root -> left) ;
        pair<int, int> right = diameterFast(root -> right) ;
        
        int op1 = left.first ;
        int op2 = right.first ;
        int op3 = left.second + right.second  ;  // int op3 = left.second + right.second + 1; not valid
        
        pair<int, int> ans ;
        ans.first = max(op1, max(op2, op3)) ; // this is bcz first store maximum diameter
        ans.second = max(left.second, right.second) + 1 ;
        
        return ans ;
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameterFast(root).first ;
    }
};
