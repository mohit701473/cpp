// GFG -> Disarrangement of balls
https://practice.geeksforgeeks.org/problems/dearrangement-of-balls0918/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article



//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  Using Recursion 
// T.C. => T(N) = (N-1) * (T(N-1) + T(N-2))
// S.C. = O(N) bcz at a time at max N recursive call stacks are created
#define MOD 1000000007

class Solution{
public:
    long int disarrange(int N){
        
        if(N == 1)
        return 0 ;

        if(N == 2)
            return 1 ;
    
        long long int ans = (((N-1) % MOD)*(disarrange(N-1) % MOD + disarrange(N-2) % MOD)) % MOD ;
        
        return ans ;
    }
};



// Approch - 2  Memoization + Recursion 
// T.C. = O(N) 
// S.C. = O(N + N) bcz at a time at max N recursive call stacks are created and dp array required N size

#define MOD 1000000007

class Solution{
    
    long int memoization(int N, vector<long int> &dp){
        if(N == 1)
        return 0 ;

        if(N == 2)
            return 1 ;
            
        if(dp[N] != -1)
            return dp[N] ;
            
        long int ans = (((N-1) % MOD)*(memoization(N-1, dp) % MOD + memoization(N-2, dp) % MOD)) % MOD ;
        
        dp[N] = ans ;
        return dp[N] ;
    }
    
    
public:
    long int disarrange(int N){
        
        vector<long int> dp(N+1, -1) ;
        return memoization(N, dp);
    }
};




// Approch - 3  Tabulation method 
// T.C. = O(N) 
// S.C. = O(N) bcz dp array required N size
#define MOD 1000000007

class Solution{
   
public:
    long int disarrange(int N){
        
        vector<long int> dp(N+1, -1) ;
        
        // Base csae analysis
        dp[1] = 0 ;
        dp[2] = 1 ;
        
        for(int i=3 ; i<=N ; i++)
            dp[i] = ((i-1) % MOD * ( dp[i-1] % MOD + dp[i-2] % MOD)) % MOD ;
        
        return dp[N];
    }
};



// Approch - 4 Space Otpimization
// T.C. = O(N) 
// S.C. = O(1) 
#define MOD 1000000007

class Solution{
   
public:
    long int disarrange(int N){
        
        if(N == 1)
            return 0 ;
        
        long int prev1 = 1 ;  // n-1 
        long int prev2 = 0 ;  // n-2
        
        for(int i=3 ; i<=N ; i++){
            long int curr = (((i-1) % MOD) * ( prev1 % MOD + prev2 % MOD) % MOD) % MOD ;
            prev2 = prev1 ;
            prev1 = curr ;
        }
        
        return prev1 ;
    }
};