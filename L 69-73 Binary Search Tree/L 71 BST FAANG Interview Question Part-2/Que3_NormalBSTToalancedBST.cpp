// Normal BST to Balanced BST


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
void inorder(struct Node* root, vector<int> &arr){
        if(root == NULL)
            return ;
            
        inorder(root -> left, arr) ;
        arr.push_back(root -> data) ;
        inorder(root -> right, arr) ;
}

Node* inorderToBST(vector<int> arr, int s, int e){
    if( s>e)
        return NULL ;
        
    // step-2 find mid
    int mid = (s+e) / 2 ;
    
    // step-3 make node for mid
    struct Node* root = new Node(arr[mid]) ;
    root -> left = inorderToBST(arr, s, mid-1) ;
    root -> right = inorderToBST(arr, mid+1, e) ;
    
    return root ;
}

Node* buildBalancedTree(Node* root)
{
	vector<int> arr ;
	
	//step-1 find inorder & store it
	inorder(root, arr) ;
	
	return inorderToBST(arr, 0, arr.size()-1) ;
}


