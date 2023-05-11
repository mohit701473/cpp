

// Apprroch 1
// T.C. = O(N)
// S.C. = O(height)
void solve(Node* root, int k, int node, vector<int> &path, bool &flag){
    if(root == NULL)
        return ;
    
    if(flag){
        path.push_back(root -> data) ;
    }
    
    // left call
    solve(root -> left, k, node, path, flag) ;
    
    // right call
    solve(root -> right, k, node, path, flag) ;
    
    if(root -> data == node){
        flag = false ;
    }
    
    if(flag)
        path.pop_back() ;
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> path ;
    bool flag = true ;
    
    solve(root, k, node, path, flag) ;
    
    int size = path.size() ;
    if(k >= size)
        return -1 ;
    int ans = path[size -k -1] ;
    
    return ans ;
    
}



// Approch 2
// T.C. = O(N) 
// S.C. = O(1)  but recursion use auxilary space so S.C. = O(height)

Node* solve(Node* root, int &k, int node){
    if(root == NULL)
        return NULL ;
    
    if(root -> data == node){
        return root ;
    }
    
    // left call
    Node* leftAns = solve(root -> left, k, node) ;
    
    // right call
    Node* rightAns = solve(root -> right, k, node) ;
    
    
    if(leftAns != NULL && rightAns == NULL){
        k-- ;
        if(k<=0){
            k = INT_MAX ; // by this we lock our ans bcz k ki value itni badi kr di h ki vo kabi ab 0 nhi ho skta
            return root ;
        }
        return leftAns ;
    }
    
    if(leftAns == NULL && rightAns != NULL){
        k-- ;
        if(k <=0){
            k = INT_MAX ; // by this we lock our ans bcz k ki value itni badi kr di h ki vo kabi ab 0 nhi ho skta
            return root ;
        }
        return rightAns ;
    }
    
    return NULL ;
    
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node) ;
    
    if(ans == NULL || ans -> data == node) // if k > no. of ancestor the ans- -> data = nose 
        return -1 ;
    
    return ans -> data ;
    
} 