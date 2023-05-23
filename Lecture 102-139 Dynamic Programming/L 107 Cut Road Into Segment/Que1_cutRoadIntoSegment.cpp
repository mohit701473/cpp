


// Approch - 1 Using Recursion
// T.C. => T(n) = T(n-x) + T(n-y) + T(n-z) + 1 =>  exponential
// S.C. = exponential recursive stack space
class Solution
{
    public:
    
    int solveRecursive(int n, int arr[]){
        
        if(n==0)
            return 0 ;
            
        if(n<0)
            return INT_MIN ;
            
        int maxi = INT_MIN ;
        
        for(int i=0 ; i<2 ; i++){
            int ans = solveRecursive(n-arr[i], arr) ;
            
            if(ans != INT_MIN)
                maxi = max(maxi, 1+ans) ;
        }
        
        return maxi ;
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int arr[3] = {x, y, z} ;
        
        return solveRecursive(n, arr) ;
    }
};



// Approch - 1 Memoization
// T.C. = O(N)
// S.C. = O(N) + O(N) {recursion stack + dp array}
class Solution
{
    public:
    
    int solveMem(int n, int arr[], vector<int> &dp){
        
        if(n==0)
            return 0 ;
            
        if(n<0)
            return INT_MIN ;
            
        if(dp[n] != INT_MIN)
            return dp[n] ;
            
        int maxi = INT_MIN ;
        
        for(int i=0 ; i<3 ; i++){
            
            int ans = solveMem(n-arr[i], arr, dp) ;
            
            if(ans != INT_MIN)
                maxi = max(maxi, 1+ans) ;
        }
        
        dp[n] = maxi ;
        return dp[n] ;
    }


    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int arr[3] = {x, y, z} ;
        vector<int> dp(n+1, INT_MIN) ;
        
        int ans = solveMem(n, arr, dp) ;

		if(ans == INT_MIN)
			return 0 ;

        return ans ;
    }
};




/ Approch - 3 Tabulation method
// Expected Time Complexity : O(N)
// Expected Auxiliary Space: O(N)
class Solution
{
    public:
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int arr[3] = {x, y, z} ;
        vector<int> dp(n+1, INT_MIN) ;
        
        // Base case analysis
        dp[0] = 0 ;
        
        int i=1 ;
        
        while(i<=n){
            for(int j=0 ; j<3 ; j++){
                if(i-arr[j] >=0 && dp[i-arr[j]] != INT_MIN)
                    dp[i] = max(dp[i], 1+dp[i-arr[j]]) ;
            }
            i++ ;
        }
        
        if(dp[n] == INT_MIN)
            return  0 ;
        
        return dp[n] ;
    }
};