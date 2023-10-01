// LeetCode -> 123. Best Time to Buy and Sell Stock III
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/




// Approch -> 1: recursion
// T.C. = Exponential
// S.C. = O(N)
class Solution {

    int solve(int idx, int buy , int cap, vector<int> &prices){

        // base cases
        if(cap == 0 || idx == prices.size()) return 0 ;

        // explore all possibilities 
        int profit ;
        if(buy){
            profit = max( (-prices[idx] + solve(idx+1 , 0, cap, prices)) , solve(idx+1, 1, cap, prices) ) ;
        }
        else{
            profit = max( (prices[idx] + solve(idx+1, 1, cap-1, prices)) , solve(idx+1, 0, cap, prices) ) ;
        }

        return profit ;
    }

public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        return solve(0, 1, 2, prices) ;
    }
};





// Approch -> 2: Memoization + recursion 
// T.C. = O(N * 2 * 3)
// S.C. = O(N * 2 * 3) + O(N)
class Solution {

    int solve(int idx, int buy , int cap, vector<int> &prices,vector<vector<vector<int>>> &dp){

        // base cases
        if(cap == 0 || idx == prices.size()) return 0 ;

        if(dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap] ;

        // explore all possibilities 
        int profit ;
        if(buy){
            profit = max( (-prices[idx] + solve(idx+1 , 0, cap, prices, dp)) , solve(idx+1, 1, cap, prices, dp) ) ;
        }
        else{
            profit = max( (prices[idx] + solve(idx+1, 1, cap-1, prices, dp)) , solve(idx+1, 0, cap, prices, dp) ) ;
        }

        return dp[idx][buy][cap] = profit ;
    }

public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))) ; 

        return solve(0, 1, 2, prices, dp) ;
    }
};





// Approch -> 3: Tabulation
// T.C. = O(N * 2 * 3)
// S.C. = O(N * 2 * 3)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0))) ; 

        // base cases
        // (i) cap = 0 i.e. idx & buy can be any thing
        for(int idx = 0 ; idx <= n ; idx++){
            for(int buy = 0 ; buy <= 1 ; buy++){
                dp[idx][buy][0] = 0 ; 
            }
        } 

        // (ii) idx = n i.e. cap & buy can be any thing
        for(int buy = 0 ; buy <= 1 ; buy++){
            for(int cap = 0 ; cap <= 2 ; cap++){
                dp[n][buy][cap] = 0 ;
            }
        }


        // changing parametres in opposite in loop
        for(int idx = n-1 ; idx >= 0 ; idx--){

            for(int buy = 0 ; buy <= 1 ; buy++){

                for(int cap = 1 ; cap <= 2 ; cap++){

                    int profit ;
                    if(buy){
                        profit = max( (-prices[idx] + dp[idx+1][0][cap]) , dp[idx+1][1][cap] ) ;
                    }
                    else{
                        profit = max( (prices[idx] + dp[idx+1][1][cap-1]) , dp[idx+1][0][cap] ) ;
                    }

                    dp[idx][buy][cap] = profit ;
                }
            }
        }

        return dp[0][1][2] ;
    }
};





// Approch -> 4: Space Optimization
// T.C. = O(N * 2 * 3)
// S.C. = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<vector<int>> after (2, vector<int>(3, 0)) ; 
        vector<vector<int>> curr (2, vector<int>(3, 0)) ; 

        // don't need to write base cases bcz initially all initilized as 0 


        // changing parametres in opposite in loop
        for(int idx = n-1 ; idx >= 0 ; idx--){

            for(int buy = 0 ; buy <= 1 ; buy++){

                for(int cap = 1 ; cap <= 2 ; cap++){

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

        return after[1][2] ;
    }
};





