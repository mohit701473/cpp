// Boundary Traversal of binary tree


// Expected Time Complexity: O(N). 
// Expected Auxiliary Space: O(Height of the Tree).
class Solution {
public:

    void leftTraversal(Node* root, vector<int> &ans){
        
        // Base case
        if((root == NULL) || (root -> left == NULL && root -> right == NULL))
            return ;
            
        ans.push_back(root -> data) ;
        
        if(root -> left != NULL)
            leftTraversal(root -> left, ans) ;
            
        else{ 
            if(root -> right != NULL)
                leftTraversal(root -> right, ans) ;
        }
    }
    
    void leafTraversal(Node* root, vector<int> &ans){
        // base case
        if(root == NULL)
            return ;
            
        // if leaf node the store it
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(root -> data) ;
            return ;
        }
        
        leafTraversal(root -> left, ans) ;
        leafTraversal(root -> right, ans) ;
        
    }


    void rightTraversal(Node* root, vector<int> &ans){
        
        // Base case
        if((root == NULL) || (root -> left == NULL && root -> right == NULL))
            return ;
            
        
        if(root -> right != NULL)  // right exist krta h to right m jao nhi to left m jao
            rightTraversal(root -> right, ans) ;
            
        else
            rightTraversal(root -> left, ans) ;
            
        // waps aagye to ans ko store kr lo
        ans.push_back(root -> data) ; 
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans ;
        if(root == NULL)
            return ans ;
            
        ans.push_back(root -> data) ;
        
        // store left part of the root 
        leftTraversal(root -> left, ans) ;
        
        // Traverse leaf node and leaf node present two types
        
        // (1)  Leaf node may present in left sub tree of the root node
        leafTraversal(root -> left, ans) ;
        
        // (2) Leaf node may present in right sub tree of the root node
        leafTraversal(root -> right, ans) ;
        
        // right traverse
        rightTraversal(root -> right , ans) ;
        
        return ans ;
    }
};

