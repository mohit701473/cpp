// Is Binary Tree Heap

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
class Solution {
    
    int countNode(struct Node* tree){
        if(tree == NULL)
            return 0 ;
            
        int ans = 1 + countNode(tree -> left) + countNode(tree -> right) ;
        return ans ;
    }
    
    bool isCBT(struct Node* tree, int i, int nodeCount){
        if(tree == NULL)
            return true ;
            
        if(i >= nodeCount)
            return false ;
            
        else{
            bool left = isCBT(tree -> left, 2*i+1, nodeCount) ;
            bool right = isCBT(tree -> right, 2*i+2, nodeCount) ;
            return left && right ;
        }
        
    }
    
    // At this function we reached only when tree CBT 
    // if tree is CBT then we have only three type of Node in tree
    // 1st is leaf Node
    // 2nd is only left child Node 
    // 3rd is both child Node
    bool isMaxOrder(struct Node* root){
        // leaf Node
        if(root -> left == NULL && root -> right == NULL)
            return true ;
            
        else{
            // only left child Node 
            if(root -> right == NULL){
                return (root -> data > root -> left -> data) ;
            }
            
            // both child Node
            else{
                // now root ke left & right m bhi chek kro ki ky vo bhi max heap property ko follow krte h ya nhi
                bool left = isMaxOrder(root -> left) ; // here we are checking for is left of the root follow Max heap propert or not 
                bool right = isMaxOrder(root -> right) ; // here we are checking for is right of the root follow Max heap prope
                
                if(left && right && ((root -> data > root -> left -> data) && (root -> data > root -> right -> data)))
                    return true ;
                    
                return false ;
            }
        }
    }
    
  public:
    
    bool isHeap(struct Node* tree) {
        if(tree == NULL)
            return true ;
            
        int i = 0 ;
        int nodeCount = countNode(tree) ;
        if(isCBT(tree, i, nodeCount) && isMaxOrder(tree))
            return true ;
            
        return false ;
    }
};

