// k-th smallest element in BST

// Approch 1
// Expected Time Complexity: O(N).   worst case if skewed tree
// Expected Auxiliary Space: O(N).   worst case if skewed tree
class Solution {
  public:
    void findKthSmallestElement(Node* root, int &ans , int &k){
        if(root == NULL)
            return ;
            
            
        findKthSmallestElement(root -> left, ans, k) ;
        
        k = k-1 ;
        if(k == 0)
            ans = root -> data ;
            
        findKthSmallestElement(root -> right, ans , k) ;
    }
    int KthSmallestElement(Node *root, int K) {
        int ans = -1 ;
        findKthSmallestElement(root, ans, K) ;
        
        return ans ;
    }
};