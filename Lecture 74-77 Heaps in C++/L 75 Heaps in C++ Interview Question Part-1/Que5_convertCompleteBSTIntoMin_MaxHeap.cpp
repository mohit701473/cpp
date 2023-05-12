// Complete BST to Min and Max Heap

// Complete BST to MAX heap
// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(n)
class Solution{
    
    void inorder(Node* root, vector<int> &in){
        if(root == NULL)
            return ;
            
        inorder(root -> left, in) ;
        in.push_back(root -> data) ;
        inorder(root -> right, in) ;
    }
    
    Node* postorder(Node* root, vector<int> &in, int &index){
        if(root == NULL)
            return NULL ;
            
        root -> left = postorder(root -> left, in, index) ;
        root -> right = postorder(root -> right, in, index) ;
        root -> data = in[index++] ;
        return root ;
    }
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> in ;
        inorder(root, in) ;
        
        int index = 0 ;
        root = postorder(root, in, index) ;
        
    }    
};