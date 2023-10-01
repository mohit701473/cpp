// LeetCode -> 188. Best Time to Buy and Sell Stock IV
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/




// Approch -> 1: recursion
// T.C. = Exponential
// S.C. = O(N)
class Solution {

    int solve(int idx, int buy, int k, vector<int> &prices){

        // Base cases
        if(k == 0) return 0 ;
        if(idx >= prices.size()) return 0 ;

        // explorev all possibilities
        int profit ;
        if(buy){
            profit = max( (-prices[idx] + solve(idx+1, 0 , k, prices) ) , solve(idx+1, 1, k, prices) ) ;
        }
        else{
            profit = max((prices[idx] + solve(idx+1, 1, k-1, prices)), solve(idx+1, 0, k, prices)) ;
        }

        return profit ;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        
        return solve(0, 1, k, prices) ;
    }
};





// Approch -> 2: Memoization + recursion 
// T.C. = O(N * 2 * K)
// S.C. = O(N * 2 * K) + O(N)
class Solution {

    int solve(int idx, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){

        // Base cases
        if(k == 0) return 0 ;
        if(idx >= prices.size()) return 0 ;

        if(dp[idx][buy][k] != -1)
            return dp[idx][buy][k] ;

        // explorev all possibilities
        int profit ;
        if(buy){
            profit = max( (-prices[idx] + solve(idx+1, 0 , k, prices, dp) ) , solve(idx+1, 1, k, prices, dp) ) ;
        }
        else{
            profit = max((prices[idx] + solve(idx+1, 1, k-1, prices, dp)), solve(idx+1, 0, k, prices, dp)) ;
        }

        return dp[idx][buy][k] = profit ;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1))) ;
        
        return solve(0, 1, k, prices, dp) ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(N * 2 * K)
// S.C. = O(1)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size() ;

        vector<vector<int>> after (2, vector<int>(k+1, 0)) ; 
        vector<vector<int>> curr (2, vector<int>(k+1, 0)) ; 

        // don't need to write base cases bcz initially all initilized as 0 


        // changing parametres in opposite in loop
        for(int idx = n-1 ; idx >= 0 ; idx--){

            for(int buy = 0 ; buy <= 1 ; buy++){

                for(int cap = 1 ; cap <= k ; cap++){

                    int profit ;
                    if(buy){
                        profit = max( (-prices[idx] + after[0][cap]) , after[1][cap] ) ;
                    }
                    else{
                        profit = max( (prices[idx] + after[1][cap-1]) , after[0][cap] ) ;
                    }

                    curr[buy][cap] = profit ;
                }
            }
            after = curr ;
        }

        return after[1][k] ;





        // int n = prices.size() ;

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0))) ;

        // // base case don't need to be write

        // for(int idx = n-1 ; idx >=0 ; idx--){

        //     for(int buy = 0 ; buy <= 1 ; buy++){

        //         for(int cap = 1 ; cap <= k ; cap++){
                    
        //             // explorev all possibilities
        //             int profit ;
        //             if(buy){
        //                 profit = max( (-prices[idx] + dp[idx+1][0][cap]) , dp[idx+1][1][cap]) ;
        //             }
        //             else{
        //                 profit = max( (prices[idx] + dp[idx+1][1][k-1]), dp[idx+1][0][cap]) ;
        //             }

        //             dp[idx][buy][cap] = profit ;
        //         }
        //     }
        // }

        
        // return dp[0][1][k] ;
    }
};