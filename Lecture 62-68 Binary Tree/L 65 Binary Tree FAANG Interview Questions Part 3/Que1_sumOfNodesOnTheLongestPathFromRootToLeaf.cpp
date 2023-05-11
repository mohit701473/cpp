// Sum of nodes on the longest path from root to leaf node


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
void solve(Node* root, pair<int,int> temp, pair<int, int> &ans){
        
        if(root == NULL)
            return ;
        
        if(root -> left == NULL && root -> right == NULL){
            temp.first += root -> data ; // sum
            temp.second += 1 ;
            
            if(ans.second < temp.second){
                // update ans 
                ans.first = temp.first ;
                ans.second = temp.second ;
            }
            
            if(ans.second == temp.second){
                if(ans.first < temp.first){
                    ans.first = temp.first ;
                    ans.second = temp.second ;
                }
            }
            return ;
        }
        
        temp.first += root -> data ; // sum
        temp.second += 1 ; 
        
        solve(root -> left, temp, ans) ;
        solve(root -> right, temp, ans) ;
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int, int> ans = {0,0} ; // ans.first will give the sum of the path and ans.second will give the length of the path
        
        if(root == NULL)
            return ans.first ;
            
        pair<int,int> temp = {0,0} ;
            
        solve(root, temp, ans) ;
        
        return ans.first ;
    }