


// Approch -> 1 recursive approch
// T.C. => T(n) = T(n-1) + T(n-2) + C => exponential
// S.C. => Exponential
class Solution{
public:	
	
    int solveRec(int *arr, int n , int i){
	    
        if(i < 0)
            return -1 ;
    	        
        if(i == 0)
            return arr[0] ;
            
        int incl = solveRec(arr, n, i-2) + arr[i] ;
        
        int excl = solveRec(arr, n, i-1) + 0 ;
        
        return max(incl, excl) ;
    	    
	}
	
	int findMaxSum(int *arr, int n) {
	    
	    return solveRec(arr, n, n-1) ; // right to left index moving
	}
};


// Approch -> 2 Top-Down Approch(recursion + memoization)
// T.C. => O(n)
// S.C. => O(n)
class Solution{
public:	
	
    int solveRec(int *arr, int n , int i, vector<int> &dp){
	    
        if(i < 0)
            return 0 ;
    	        
        if(i == 0)
            return arr[0] ;
        
        
        if(dp[i] != -1)
            return dp[i] ;
        
        int incl = solveRec(arr, n, i-2, dp) + arr[i] ;
        
        int excl = solveRec(arr, n, i-1, dp) + 0 ;
        
        dp[i] = max(incl, excl) ;
        return dp[i] ;
    	    
	}
	
	int findMaxSum(int *arr, int n) {
	    
	    vector<int> dp(n, -1) ;
	    return solveRec(arr, n, n-1, dp) ; // right to left
	}
};



// Approch -> 2 Bottom-Up Approch(Tabulation Method)
// T.C. => O(n)
// S.C. => O(n)
class Solution{
public:	
	
	int findMaxSum(int *arr, int n) {
	    
	    vector<int> dp(n, -1) ;
	    
	    dp[0] = arr[0] ;
	    
	    for(int i=1 ; i<n ; i++){
	        int incl = dp[i-2] + arr[i] ;
	        int excl = dp[i-1] + 0 ;
	        
	        dp[i] = max(incl, excl) ;
	    }
	    
	    return dp[n-1] ;
	}
};



// Approch -> 2 Space Optimization
// T.C. => O(n)
// S.C. => O(1)
class Solution{
public:	
	
	int findMaxSum(int *arr, int n) {
	    
	    int prev2 = 0 ;
	    int prev1 = arr[0] ;
	    
	    for(int i=1 ; i<n ; i++){
	        int incl = prev2 + arr[i] ;
	        int excl = prev1 + 0 ;
	        
	        int ans = max(incl, excl) ;
	        prev2 = prev1 ;
	        prev1 = ans ;
	    }
	    
	    return prev1 ;
	}
};