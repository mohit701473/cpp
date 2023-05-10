

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root, vector<int> &arr){
        if(root == NULL)
            return ;
            
        inorder(root -> left, arr) ;
        arr.push_back(root -> data) ;
        inorder(root -> right, arr) ;
    }
    
    vector<int>  merge(vector<int> a, vector<int> b) {
        
        vector<int> ans ;
        
        int i=0 , j=0 ;
        
        while(i<a.size() && j<b.size()){
            if(a[i] < b[j]){
                ans.push_back(a[i]) ;
                i++ ;
            }
            
            else{
                ans.push_back(b[j]) ;
                j++ ;
            }
        }
        
        while(i<a.size()){
            ans.push_back(a[i]) ;
            i++ ;
        }
        
        while(j<b.size()){
            ans.push_back(b[j]) ;
            j++ ;
        }
        
        return ans ;
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
    
    Node* merge(Node *root1, Node *root2)
    {
        // step -> 1 store the inorder of both BST
        vector<int> in1 ;
        vector<int> in2 ;
           
        inorder(root1, in1) ;
        inorder(root2, in2) ;
        
        // step -> 2 merger the inoredr of both BST
        vector<int> mergeArray = merge(in1, in2) ;

        // step -> 3 make BST from inorder
        Node* root = inorderToBST(mergeArray, 0, mergeArray.size()-1) ;

        return root ;


       
    }
};

