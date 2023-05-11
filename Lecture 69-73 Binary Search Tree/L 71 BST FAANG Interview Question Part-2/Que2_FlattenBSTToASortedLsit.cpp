// Flatten BST to sorted list codestudio practice

// T.C. = O(N)
// S.C. = O(N)
void inorder(TreeNode<int>* root, vector<TreeNode<int>*> &arr){
        if(root == NULL)
            return ;
            
        inorder(root -> left, arr) ;
        arr.push_back(root) ;
        inorder(root -> right, arr) ;
    }

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode<int>*> arr ;
    inorder(root, arr) ;

    TreeNode<int>* temp = arr[0] ;
    int n = arr.size() ;
    int i = 0 ;

    while(i < n-1){
        temp -> left = NULL ;
        i++ ;
        temp -> right = arr[i] ;
        
        temp = arr[i] ;
    }

    arr[i] -> left = NULL ;
    arr[i] -> right = NULL ;
    
    return arr[0] ;
}