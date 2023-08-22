// Codinh Ninja -> Count derangements
https://www.codingninjas.com/studio/problems/count-derangements_873861?leftPanelTab=0


// Approch -> 1: recursive Approch
/*
suppose yor have n size array
starting index value = 0 
0 ko kitne palces pr rakh skte hai => n-1 
our ans => (n-1) * [solution of subproblems]

here two type of subprobles can be seen 
type one -> jub 0 ko i-th index se swap kr de to => solveRecursive(n-2) => n-2 bcz after swaping 0 & i-th index their 
            only n-2 elements are left
type 2nd -> jub 0 ko i-th index m dal de baki ko kese bhi set kr do but follow the constrains => solveRecursive(n-1)
            n-1 bcz after inserting 0 to i-th index their only n-1 elements are left
*/
// T.C. = Exponential
// S.C. = O(N)
#define MOD 1000000007 

long long int solveRecursive(int n){
    if(n==1 || n==2) return n-1 ;
    
    long long int ans = (( (n-1) % MOD ) *( ( (solveRecursive(n-1) % MOD) + (solveRecursive(n-2) % MOD) ) % MOD)) % MOD ;
    
    return ans % MOD ;
}

long long int countDerangements(int n) {
    return solveRecursive(n) ;
}



// Approch -> 2: Memoization
// T.C. = O(N)
// S.C. = O(N)
#define MOD 1000000007 
#include<vector> 
long long int solveMem(int n, vector<long long int> &dp){
    if(n==1 || n==2) return n-1 ;
    
    // step -> 3:
    if(dp[n] != -1)
        return dp[n] ;
    
    long long int ans = (( (n-1) % MOD ) *( ( (solveRecursive(n-1, dp) % MOD) + (solveRecursive(n-2, dp) % MOD) ) % MOD)) % MOD ;
    
    // step -> 2:
    dp[n] = ans % MOD ;
    return dp[n] ;
}

long long int countDerangements(int n) {
    // step -> 1: 
    vector<long long int> dp(n+1, -1) ;
    return solveMem(n, dp) ;
}



// Approch -> 2: Tabulation
// T.C. = O(N)
// S.C. = O(N)
#define MOD 1000000007 
#include<vector> 
long long int solveTab(int n){
    vector<long long int> dp(n+1, -1) ;

    dp[1] = 0 , dp[2] = 1 ;

    for(int i=3 ; i<=n ; i++){
        dp[i] = (( (i-1) % MOD ) * ( (dp[i-1] % MOD) + (dp[i-2] % MOD) ) % MOD) % MOD ;
    }

    return dp[n] ;
}

long long int countDerangements(int n) {
    // vector<long long int> dp(n+1, -1) ;
    return solveTab(n) ;
    
}



// Approch -> 4: Space Optimization
// T.C. = O(N)
// S.C. = O(1)
#define MOD 1000000007 
#include<vector> 

long long int spaceOtimization(int n){
    if(n==1 || n==2) 
        return n-1 ;
    //vector<long long int> dp(n+1, -1) ;

    // dp[1] = 0 , dp[2] = 1 ;
    long long int prev1 = 1 ; // dp[2] = 1 => dp[i-1]
    long long int prev2 = 0 ; // dp[1] = 0 => dp[i-2]

    for(int i=3 ; i<=n ; i++){
        long long int curr = (( (i-1) % MOD ) * ( (prev1 % MOD) + (prev2 % MOD) ) % MOD) % MOD ;
        
        prev2 = prev1 ;
        prev1 = curr ;
    }

    return prev1 ;
}

long long int countDerangements(int n) {
    // vector<long long int> dp(n+1, -1) ;
    return spaceOtimization(n) ;
    
}

