// Tree from Postorder and Inorder

int findPosition(int in[], int element, int i, int end){
        for(i ; i<= end ; i++){
            if(in[i] == element)
                return i ;
        }
        return -1 ;
    }
    
    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n){
        // base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL ;
        }
        
        int element = post[index--] ;
        Node* root = new Node(element) ;
        int position = findPosition(in, element, inorderStart, inorderEnd) ;
        
        // recursive call 
        root -> right = solve(in, post, index, position+1, inorderEnd, n) ;
        root -> left = solve(in, post, index, inorderStart, position-1, n) ;
        
        return root ;
    }


Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1 ;
    int inorderStart = 0 ;
    int inorderEnd = n-1 ;
        
    Node* ans = solve(in, post, postOrderIndex, inorderStart, inorderEnd, n) ;
        
    return ans ;
}