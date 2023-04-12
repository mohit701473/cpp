


// Approch 1
// T.C. = O(n^2)

class Solution{
    public:
    
    int height(struct Node* node){ 
         if(node == NULL)
            return 0 ;

        int leftHeight = height(node -> left) ;
        int rightHeight = height(node -> right) ;

        int ans = max(leftHeight, rightHeight) + 1 ;

        return ans ;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // base case
        if(root == NULL)
            return true ;
            
        bool left = isBalanced(root -> left) ;
        bool right = isBalanced(root -> right) ;
        
        bool diff = abs(height(root -> left) - height(root -> right)) <= 1 ;
        
        if(left && right && diff)
            return true ;
            
        else return false ;
    }
};



// Approch 2
// T.C. = O(n)
//S.C. = 
class Solution{
    public:
    
    pair<bool, int> isBalancedFast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true,0) ;
            return p ;
        }
        
        pair<bool, int> left = isBalancedFast(root -> left) ;
        pair<bool, int> right = isBalancedFast(root -> right) ;
        
        bool leftAns = left.first ;
        bool rightAns = right.first ;
        bool diff = abs(left.second - right.second) <= 1 ;
        
        pair<bool, int> ans ;
        ans.second = max(left.second, right.second) + 1 ;
        
        if(leftAns && rightAns && diff){
            ans.first = true ;
        }
            
        else{
            ans.second = false ;
        }
        
        return ans ;
    }
   
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first ;
    }
};



// Approch 3 Itrative method
class Solution {
public:

    int height(TreeNode* node){ 
         if(node == NULL)
            return 0 ;

        int leftHeight = height(node -> left) ;
        int rightHeight = height(node -> right) ;

        int ans = max(leftHeight, rightHeight) + 1 ;

        return ans ;
    }

    bool isBalanced(TreeNode* root) {
        // Base case
         if(root == NULL)
            return true ;
        
        queue<TreeNode*> q ;
        q.push(root) ;

        while(!q.empty()){
            TreeNode* temp = q.front() ;
            q.pop() ;

            bool diff = abs(height(temp -> left) - height(temp -> right)) <=1 ;
            if(!diff) 
                return diff ;

            if(temp -> left != NULL)
                q.push(temp -> left) ;

            if(temp -> right != NULL) 
                q.push(temp -> right) ;
        }

        return true ;
    }
}