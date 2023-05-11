// Construct BST from Preorder Traversal


// T.C. = O(3N) = O(N) 
// S.C. = O(height of tree)  recursive call stack
TreeNode<int>* solve(vector<int> &preOrder, int mini, int maxi, int &i){
    // base case - 1
    if(i >= preOrder.size())
        return NULL ;

    // Base case - 2 if i is out of the range (mini, maxi)
    if(preOrder[i] < mini || preOrder[i] > maxi)
        return NULL ;

    // Now we are inside the range 

    // step -> 1 Create a Node 
    TreeNode<int>* root = new TreeNode<int>(preOrder[i++]) ;

    root -> left = solve(preOrder, mini, root -> data, i) ;
    root -> right = solve(preOrder, root -> data, maxi, i) ;

    return root ;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int mini = INT_MIN ;
    int maxi = INT_MAX ;
    int i = 0 ;
    
    return solve(preOrder, mini, maxi, i) ;
}

