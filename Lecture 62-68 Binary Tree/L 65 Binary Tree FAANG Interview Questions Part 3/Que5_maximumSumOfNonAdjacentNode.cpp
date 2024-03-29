// Maximum sum of Non-adjacent nodes

// Approch 1
// T.C. = O(N) 
// S.C. = O(height)  recursive call stack
pair<int, int> solve(Node* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0,0) ;
            return p ;
        }
        
        // left call
        pair<int, int> left = solve(root -> left) ;
        pair<int, int> right = solve(root -> right) ;
        
        pair<int, int> ans ;
        ans.first = root -> data + left.second + right.second ;
        ans.second = max(left.first, left.second) + max(right.first, right.second) ;
        
        return ans ;
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root) ;
        
        return max(ans.first, ans.second) ;
    }