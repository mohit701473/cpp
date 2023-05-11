// Sum Tree
// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.


// T.C. = O(n)  each node is traversed only once
// S.C. = O(height)
class Solution
{
    public:
    
    pair<bool, int> isSumTreeFast(Node* root){
        // Base Case
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0) ;
            return p ;
        }
        
        // check leaf node or not
        if(root -> left == NULL && root -> right == NULL){
            pair<bool, int> p = make_pair(true, root -> data) ;
            return p ;
        }
        
        pair<bool, int> left = isSumTreeFast(root -> left) ;  // traverse left part of the any node and store the value of the ans 
        pair<bool, int> right = isSumTreeFast(root -> right) ;  // traverse right part of the any node and store the value of the ans 
        
        bool leftAns = left.first ;  // is left of the root a sum tree or not
        bool rightAns = right.first ;  // is right of the root a sum tree or not 
        bool checkRootData = root -> data == left.second + right.second ;  // check the data of the root with the left sub tree data and right sub tree data
        
        pair<bool, int> ans ;  // at any node ans.first store that is a sum tree or not and ans.second store the 2 * curr node data if the node is sum tree 
        
        if(leftAns && rightAns && checkRootData){
            ans.first = true ;
            ans.second = 2 * root-> data ;
        }
        
        else{
            ans.first = false ;
        }
        
        return ans ;
    }
    
    
    
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first ;
    }
};