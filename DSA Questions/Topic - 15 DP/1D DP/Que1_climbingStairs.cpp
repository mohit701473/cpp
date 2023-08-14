// LeetCode -> 70. Climbing Stairs (same as n-th fibonacci no.)
https://leetcode.com/problems/climbing-stairs/description/



// Approch 1: Recursive Approch(bottum-Up Recursive Tree)
/*
Recursive Approch -> In this solution recursive tree is Bottum to Up 
*/
// T.C. = O(2^n)
// S.C. = O(N)
class Solution {
    void contWays(int k, int n, int &ways){
        if(k == n){
            ways++ ;
            return ;
        }
        if(k > n) return ;

        contWays(k+1, n, ways) ;
        contWays(k+2, n, ways) ;
    }

public:
    int climbStairs(int n) {
        int ways = 0 ;
        contWays(0, n, ways) ;
        return ways ;
    }
};


// Approch 1: Recursive Approch(Top-Down Recursive Tree)
/*
Recursive Approch -> In this solution recursive tree is Top to Down
*/
// T.C. = O(2^n)
// S.C. = O(N)
class Solution {
    int countWays(int n){
        if(n==0) return 1 ;
        if(n<0) return 0 ;

        return countWays(n-1) + countWays(n-2) ;
    }

public:
    int climbStairs(int n) {
        return countWays(n) ;
    }
};




// Approch -> 2: Recusion + Memoization
// T.C. = O(N)
// S.C. = O(N) + O(N) {Dp array + recursive call satck}
class Solution {
    int countWays(int n, vector<int> &dp){
        // Base Cases
        if(n==0) return 1 ;
        if(n<0) return 0 ;

        // step -> 3: If thr result of the subproblem is previously computed then return it 
        if(dp[n] != -1) return dp[n] ;
        
        // step -> 2: Store the result of the subproblem
        dp[n] = countWays(n-1, dp) + countWays(n-2, dp) ;
        return dp[n] ;
    }

public:
    int climbStairs(int n) {
        // Step -> 1:  Declear a DP array
        vector<int> dp(n+1, -1) ;
        return countWays(n, dp) ;
    }
};



// Approch -> 3: Tabulation Method
// T.C. = O(N)
// S.C. = O(N) 
class Solution {
public:
    int climbStairs(int n) {
        // Step -> 1: Declear a DP array
        vector<int> dp(n+1, -1) ;

        // step -> 2: analyses the base case of recursive solution
        dp[0] = 1 , dp[1] = 1 ;

        // step -> 3: apply loop and solve
        for(int i=2 ; i<=n ; i++)
            dp[i] = dp[i-1] + dp[i-2] ;

        return dp[n] ;
    }
};



// Approch -> 4: Space Optimization
// T.C. = O(N)
// S.C. = O(1) 
class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1 ;

        for(int i=2 ; i<=n ; i++){
            int curr = prev1 + prev2 ;
            prev2 = prev1 ;
            prev1 = curr ;
        }

        return prev1 ;
    }
};