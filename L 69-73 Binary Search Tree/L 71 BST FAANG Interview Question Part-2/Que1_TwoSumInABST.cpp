// Find a pair with given target in BST


// Approch 2
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
void inorder(struct Node* root, vector<int> &node){
        if(root == NULL)
            return ;
            
        inorder(root -> left, node) ;
        node.push_back(root -> data) ;
        inorder(root -> right, node) ;
    }
    
    int isPairPresent(struct Node *root, int target)
    {
        vector<int> node ;
        inorder(root, node) ;
         
        // apply two pointer approch
        int i=0 ;
        int j = node.size() - 1 ;
        int sum = 0 ;
        while(i < j) {
            sum = node[i] + node[j] ;
            if(sum == target) 
                return 1 ;
                
            else{
                if(sum > target)
                    j-- ;
                
                else
                    i++ ;
            }
        }
        
        return 0 ;
    }