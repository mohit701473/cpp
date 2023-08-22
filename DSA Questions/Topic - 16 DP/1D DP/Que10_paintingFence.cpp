// GFG -> Painting the Fence
https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article




// Approch - 1  Using Recursion 
// T.C. => T(N) = T(N-1) + T(N-2) + C
// S.C. = O(N) bcz at a time at max N recursive call stacks are created
#define MOD 1000000007
class Solution{
    
    long long add(long long a, long long b){
        return (a % MOD + b % MOD) % MOD ;
    }
    
    long long mul(long long a, long long b){
        return ((a%MOD) * (b%MOD)) % MOD ;
    }
    
    long long solve(int n, int k){
        
        if(n==1)
            return k ;
            
        if(n==2)
            return add(k, mul(k, k-1)) ;
        
        // solve(n-2, k) => this call is for last 2 fence have same colour
        // solve(n-1, k) => this call is for last 2 fence have different colour
        long long ans = add( (mul( solve(n-2, k), k-1) ), mul( solve(n-1, k), k-1 ) ) ;
        
        return ans ;
    }
    
    public:
    long long countWays(int n, int k){
        
        return solve(n, k) ;
    }
};



// Approch - 2  Memoization + Recursion 
// T.C. = O(N) 
// S.C. = O(N + N) bcz at a time at max N recursive call stacks are created and dp array required N size
#define MOD 1000000007
class Solution{
    
    long long add(long long a, long long b){
        return (a % MOD + b % MOD) % MOD ;
    }
    
    long long mul(long long a, long long b){
        return ((a%MOD) * (b%MOD)) % MOD ;
    }

    long long memoization(int n, int k, vector<long long> &dp){
        if(n==1)
            return k ;
            
        if(n==2)
            return add(k, mul(k, k-1)) ;
            
        if(dp[n] != -1)
            return dp[n] ;
            
        long long ans = add( mul( memoization(n-2, k, dp), k-1) , mul( memoization(n-1, k, dp), k-1) ) ;
        
        dp[n] = ans ;
        return dp[n] ;
    }
    
    public:
    long long countWays(int n, int k){
        vector<long long> dp(n+1, -1) ;
        return memoization(n, k, dp) ;
    }
};



// Approch - 3  Tabulation method 
// T.C. = O(N) 
// S.C. = O(N) bcz dp array required N size
#define MOD 1000000007
class Solution{
    
    long long add(long long a, long long b){
        return (a % MOD + b % MOD) % MOD ;
    }
    
    long long mul(long long a, long long b){
        return ((a%MOD) * (b%MOD)) % MOD ;
    }
 
    long long tabulation(int n, int k, vector<long long> &dp){
        
        dp[1] = k ;
        dp[2] = add(k, mul(k, k-1)) ; 
            
        for(int i=3 ; i<=n ; i++){
            dp[i] = add( mul( dp[i-2], k-1 ), mul( dp[i-1], k-1 ) ) ;
        }
        
        return dp[n] ;
    }
    
    public:
    long long countWays(int n, int k){
        vector<long long> dp(n+1, -1) ;
        return tabulation(n, k, dp) ;
    }
};




// Approch - 4 Space Otpimization
// T.C. = O(N) 
// S.C. = O(1) 
#define MOD 1000000007
class Solution{
    
    long long add(long long a, long long b){
        return (a % MOD + b % MOD) % MOD ;
    }
    
    long long mul(long long a, long long b){
        return ((a%MOD) * (b%MOD)) % MOD ;
    }
 
    long long spaceOptimization(int n, int k){
        long long prev1 = k ; // for n = 1 => dp[i-1]
        long long prev2 = add(k, mul(k, k-1)) ;  // for n = 2 => dp[i-2]
        
        for(int i=2 ; i<=n ; i++){
            long long curr = add( mul( prev2, k-1 ), mul( prev1, k-1 ) ) ;
            prev1 = prev2 ;
            prev2 = curr ;
        }
        
        return prev1 ;
    }
    
    public:
    long long countWays(int n, int k){
        
        return spaceOptimization(n, k) ;
    }
};