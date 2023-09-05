// LeetCode -> 518. Coin Change II
https://leetcode.com/problems/coin-change-ii/





// Approch -> 1: Recursion
// T.C. = Exponential
// S.C. >> O(N)
class Solution {

    int solveRecursive(int idx, int target, vector<int> &coins){
        // Base cases
        if(idx == 0)
            return (target % coins[0] == 0) ;

        // explore all possibilities 
        int notTake = solveRecursive(idx-1, target, coins) ;

        int take = 0 ;
        if(coins[idx] <= target)
            take = solveRecursive(idx, target-coins[idx], coins) ;

        return take + notTake ;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        return solveRecursive(n-1, amount, coins) ;
    }
};





// Approch -> 2: Memoization
// T.C. = O(N * amount) 
// S.C. = O(N * amoutn) + O(amount)
class Solution {

    int solveMem(int idx, int target, vector<int> &coins, vector<vector<int>> &dp){
        // Base cases
        if(idx == 0)
            return (target % coins[0] == 0) ;

        if(dp[idx][target] != -1)
            return dp[idx][target] ;

        // explore all possibilities 
        int notTake = solveMem(idx-1, target, coins, dp) ;

        int take = 0 ;
        if(coins[idx] <= target)
            take = solveMem(idx, target-coins[idx], coins, dp) ;

        dp[idx][target] = take + notTake ;
        return dp[idx][target] ;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;

        vector<vector<int>> dp(n, vector<int>(amount+1, -1)) ;
        return solveMem(n-1, amount, coins, dp) ;
    }
};




// Approch -> 2: Tabulation
// T.C. = O(N * amount) 
// S.C. = O(N * amoutn)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;

        vector<vector<int>> dp(n, vector<int>(amount+1, 0)) ;

        // base cases
        for(int target = 0 ; target <= amount ; target++){
            dp[0][target] = target % coins[0] == 0 ? 1 : 0 ;
        }
        

        // nested loops
        for(int idx = 1 ; idx<n ; idx++){
            
            for(int target = 0 ; target <= amount ; target++){

                int notTake = dp[idx-1][target] ; // solveMem(idx-1, target, coins, dp) ;

                int take = 0 ;
                if(coins[idx] <= target)
                    take = dp[idx][target-coins[idx]] ; // solveMem(idx, target-coins[idx], coins, dp) ;

                dp[idx][target] = take + notTake ;
            }
        }


        return dp[n-1][amount] ; // solveMem(n-1, amount, coins, dp) ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(N * amount)
// S.C. = O(2 * amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;

        vector<int> prev(amount+1, 0), curr(amount+1, 0) ;

        // base cases
        for(int target = 0 ; target <= amount ; target++){
            prev[target] = target % coins[0] == 0 ? 1 : 0 ;
        }
        

        // nested loops
        for(int idx = 1 ; idx<n ; idx++){
            
            for(int target = 0 ; target <= amount ; target++){

                int notTake = prev[target] ; // solveMem(idx-1, target, coins, dp) ;

                int take = 0 ;
                if(coins[idx] <= target)
                    take = curr[target-coins[idx]] ; // solveMem(idx, target-coins[idx], coins, dp) ;

                curr[target] = take + notTake ;
            }

            prev = curr ;
        }


        return prev[amount] ; // solveMem(n-1, amount, coins, dp) ;
    }
};