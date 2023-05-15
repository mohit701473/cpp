


// Expected Time Complexity: O(4^(N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.
class Solution{
    public:
    
    bool isSafe(int newx, int newy, vector<vector<bool> > &vis, vector<vector<int>> &arr, int n){
        
        if((newx >= 0 && newx < n) &&  (newy >=0 && newy < n) &&  (vis[newx][newy] != 1) && (arr[newx][newy] == 1))
            return true ;
            
        return false ;
    }
    
    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool> > &vis, string path){
        
        // base case
        if(x == n-1 && y == n-1){
            ans.push_back(path) ;
            return ;
        }
        
        // 4 Movement h 
        // D L R U
        
        // Down 
        if(isSafe(x+1 , y, vis, arr, n)){
            vis[x][y] = 1 ;
            solve(x+1, y, arr, n, ans, vis, path + 'D') ;
            vis[x][y] = 0 ;
        }
        
        // Left 
        if(isSafe(x , y-1, vis, arr, n)){
            vis[x][y] = 1 ;
            solve(x, y-1, arr, n, ans, vis, path + 'L') ;
            vis[x][y] = 0 ;
        }
        
        // Right 
        if(isSafe(x , y+1, vis, arr, n)){
            vis[x][y] = 1 ;
            solve(x, y+1, arr, n, ans, vis, path + 'R') ;
            vis[x][y] = 0 ;
        }
        
        // Up 
        if(isSafe(x-1 , y, vis, arr, n)){
            vis[x][y] = 1 ;
            solve(x-1, y, arr, n, ans, vis, path + 'U') ;
            vis[x][y] = 0 ;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {

        vector<string> ans ;
        
        if(m[0][0] == 0)
            return ans ;
        
        vector<vector<bool> > visited (n, vector<bool> (n,0)) ;
        string path = "" ;
        
        solve(0, 0, m, n, ans, visited, path) ;
        
        return ans ;
    }
};