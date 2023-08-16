// GFG ->  Maximise the cut segment
https://practice.geeksforgeeks.org/problems/cutted-segments1642/1



// Approch -> 1: Recursive Approch
// T.C. = Exponential
// S.C. = O(N)
class Solution
{
    
    int solveRecursive(int len , vector<int> &xyz){
        if(len == 0) return 0 ;
        if(len < 0) return INT_MIN ;
        
        int ans = INT_MIN ;
        for(int i=0 ; i<3 ; i++){
            int countSegment = solveRecursive(len-xyz[i] , xyz) ;
            
            if(countSegment != INT_MIN)
                ans = max(ans, countSegment+1) ;
        }
        
        return ans ;
    }
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> xyz = {x, y, z} ;
        int result = solveRecursive(n, xyz) ;
        return result != INT_MIN ? result : 0 ;
    }
};



// Approch -> 3: Memoization Method
// T.C. = O(N)
// S.C. = O(N) + O(N)
class Solution
{
     int memoization(int len, vector<int> &xyz, vector<int> &dp){
        if(len == 0) return 0 ;
        if(len < 0) return INT_MIN ;
        
        // step -> 3: if result of subproblem is already computed then return it
        if(dp[len] != -1)
            return dp[len] ;
        
        int ans = INT_MIN ;
        for(int i=0 ; i<3 ; i++){
            int countSegment = memoization(len-xyz[i] , xyz, dp) ;
            
            if(countSegment != INT_MIN)
                ans = max(ans, countSegment+1) ;
        }
        // step -> 2: store teh result of subproblem into dp array
        dp[len] = ans ;
        return dp[len] ;
    }
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> xyz = {x, y, z} ;
        // step -> 1: Create a dp array
        vector<int> dp(n+1, -1) ;
        int result = memoization(n, xyz, dp) ;

        return result != INT_MIN ? result : 0 ;
    }
};



// Approch -> 3: Tabulation Method
// T.C. = O(N)
// S.C. = O(N)
class Solution
{
    int tabulation(int len , vector<int> &xyz){
        // step -> 1: create a dp array
        vector<int> dp(len+1, -1) ;
        
        // step -> 2: base cases analysis
        dp[0] = 0 ;
        int neg = INT_MIN ;
        
        // step -> 3:
        for(int i=1 ; i<=len ; i++){ // i denoting the length of road at any instance
        
            int ans = INT_MIN ;
            for(int j=0 ; j<3 ; j++){
                int countSegment = i-xyz[j] >=0 ? dp[i-xyz[j]] : INT_MIN ; // memoization(len-xyz[i] , xyz, dp) ;
                
                if(countSegment != INT_MIN)
                    ans = max(ans, countSegment+1) ;
            }
            
            // dp[i] => number of maximum segment for i length road i.e. i legnth ki road ki kitne maximum segment 
            // possible hai 
            dp[i] = ans ;
        }
        
        return dp[len] ;
        
    }
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> xyz = {x, y, z} ;
        int result = tabulation(n, xyz) ;
        return result != INT_MIN ? result : 0 ;
    }
};

// can't do space optimization
