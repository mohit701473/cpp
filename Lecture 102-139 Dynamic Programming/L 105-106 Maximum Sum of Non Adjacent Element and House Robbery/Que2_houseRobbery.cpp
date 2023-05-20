

// Approch -> 1 recursive approch
// T.C. => T(n) = T(n-1) + T(n-2) + C => exponential
// S.C. => Exponential
class Solution
{
    public:
    
    int solveRecursive(int arr[], int &n, int i){
        
        if(i >= n)
            return 0 ;
            
        int incl = arr[i] + solveRecursive(arr, n, i+2) ;
        int excl = solveRecursive(arr, n , i+1) + 0 ;
        
        return max(incl, excl) ;
    }
    
    int FindMaxSum(int arr[], int n)
    {
        return solveRecursive(arr, n , 0) ;
    }
};




// Approch -> 2 Top-Down Approch(recursion + memoization)
// T.C. => O(n)
// S.C. => O(n)
class Solution
{
    public:
    
    int solveMemoization(int arr[], int &n, int i, vector<int> &dp){
        
        if(i >= n)
            return 0 ;
            
        if(dp[i] != -1)
            return dp[i] ;
        
        int incl = arr[i] + solveMemoization(arr, n, i+2, dp) ;
        int excl = solveMemoization(arr, n , i+1, dp) + 0 ;
        
        dp[i] = max(incl, excl) ;
        return dp[i] ;
        
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n, -1) ;
        
        return solveMemoization(arr, n, 0, dp) ;
        
        
    }
};