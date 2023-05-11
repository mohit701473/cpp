


// Approch 1
class Solution{
  public:
  
    void solve(Node* root, int k, int &count, vector<int> path){
        if(root == NULL)
            return ;
            
        path.push_back(root -> data) ;
        
        // left call
        solve(root -> left, k, count, path) ;
        
        // right call
        solve(root -> right, k, count, path) ;
        
        int i = path.size() - 1;
        int sum = 0 ;
        for(i ; i>=0 ; i--){
            sum += path[i] ;
            if(sum == k){
                count = ((count % 1000000007) + 1) % 1000000007 ;
            }
        }
        
        path.pop_back() ;
    }
  
    int sumK(Node *root,int k)
    {
        vector<int> path ;
        int count = 0 ;
        
        solve(root, k, count, path) ;
        
        return count ;
    }
};