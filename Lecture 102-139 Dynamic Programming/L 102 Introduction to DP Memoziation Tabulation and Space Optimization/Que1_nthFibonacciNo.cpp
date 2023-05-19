

// Approch - 1 recursive approch
// T.C. = O(2^n)
// S.C. = O(2^n) recursive stack 
class Solution {
  public:

    long long int fib(long long int n) {
        
        if( n== 1 || n== 0)
            return n ;


        return (fib(n-1)%1000000007 + fib(n-2)%1000000007) % 1000000007 ;
        
    }
  
    long long int nthFibonacci(long long int n){
       return fib(n) ;
    }
};



// Approch - 2 Top-Down(Memoziation)
// T.C. = O(n)
// S.C. = O(n)
class Solution {
  public:

    long long int fib(long long int n, vector<long long int> &dp) {
        
        if( n== 1 || n== 0)
            return n ;
            
        // step -> 3 if value of subproblem is already found then return it 
        if(dp[n] != -1)
            return dp[n] ;
            
        // step -> 2 store the value of subproblems into dp Array 
        dp[n] = (fib(n-1, dp)%1000000007 + fib(n-2, dp)%1000000007) % 1000000007 ;
        
        return dp[n] ;
    }
  
    long long int nthFibonacci(long long int n){
       
       // step -> 1 create a dp array of size n+1 
       vector<long long int> dp(n+1, -1) ;
       
       return fib(n, dp) ;
    }
};



// Approch - 3 Bottom-Up(Tabulation Method)
// T.C. = O(n)
// S.C. = O(n)
class Solution {
  public:
    long long int nthFibonacci(long long int n){

        // step -> 1 Create a dp array
        vector<long long int> dp(n+1, -1) ;
        
        // step -> 2 check base case 
        dp[0] = 0 ;
        dp[1] = 1 ;
        

        // step -> 3 
        int i=2 ;
        while(i <= n){
            dp[i] = (dp[i-1] % 1000000007 + dp[i-2] % 1000000007) % 1000000007 ;
            i++ ;
        }
        
        return dp[n] ;
    }
};


// Approch - 4 Space Optimization
// T.C. = O(n)
// S.C. = O(1)
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        
        long long int prev1 = 0 ;
        long long int prev2 = 1 ;
        long long int curr = 0 ;
        
        if(n==1 || n==0)
            return n ;
        
        long long int i = 2 ;
        
        while(i<=n){ 
            curr = (prev1 % 1000000007 + prev2 % 1000000007) % 1000000007 ;
            prev1 = prev2 % 1000000007 ;
            prev2 = curr % 1000000007 ;
            i++ ;
        }
        
        return curr ;
    }
};

