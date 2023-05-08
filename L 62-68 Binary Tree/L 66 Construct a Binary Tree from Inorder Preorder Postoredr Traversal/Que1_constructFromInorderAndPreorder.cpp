// Construct Tree from Inorder & Preorder

// Approch 1 without map
// T.C. = O(N^2) bcz O(N) taken by solve function and inside this function we every time call findPosition which also take O(N)
// S.C. =  
class Solution{
    public:
    
    int findPosition(int in[], int element, int i, int end){
        for(i ; i<= end ; i++){
            if(in[i] == element)
                return i ;
        }
        return -1 ;
    }
    
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n){
        // base case
        if(index >= n || inorderStart > inorderEnd){
            return NULL ;
        }
        
        int element = pre[index++] ;
        Node* root = new Node(element) ;
        int position = findPosition(in, element, inorderStart, inorderEnd) ;
        
        // recursive call 
        root -> left = solve(in, pre, index, inorderStart, position-1, n) ;
        root -> right = solve(in, pre, index, position+1, inorderEnd, n) ;
        
        return root ;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex = 0 ;
        int inorderStart = 0 ;
        int inorderEnd = n-1 ;
        
        Node* ans = solve(in, pre, preorderIndex, inorderStart, inorderEnd, n) ;
        
        return ans ;
    }
};





// Approch 2  using map
// T.C. = O(Nlog(N)) bcz create a map take time O(Nlog(N)) and solve function take O(N) time 
// S.C. = 
class Solution {
public:

    void createMap(vector<int> inorder, map<int, int>& nodeToIndex){
        int size = inorder.size() ;
        for(int i=0 ; i<size ; i++){
            nodeToIndex[inorder[i]] = i ;
        }
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int &index, int inOrderStart, int inOrderEnd, int n,  map<int, int> &nodeToIndex){
        // base case
        if(index >= n || inOrderStart > inOrderEnd)
            return NULL ;

        int element = preorder[index++] ;
        TreeNode* root = new TreeNode(element) ;
        int position = nodeToIndex[element] ;

        // recursive call
        root -> left = solve(inorder, preorder, index, inOrderStart, position-1, n, nodeToIndex) ;

        root -> right = solve(inorder, preorder, index, position+1, inOrderEnd, n, nodeToIndex) ;

        return root ;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() ;
        int preOrderIndex = 0 ;
        map<int, int> nodeToIndex ; // This map will store the inorder of tree with their indexe
        createMap(inorder, nodeToIndex) ;
        TreeNode* ans =  solve(inorder, preorder, preOrderIndex, 0, n-1, n, nodeToIndex) ;

        return ans ;
    }
};