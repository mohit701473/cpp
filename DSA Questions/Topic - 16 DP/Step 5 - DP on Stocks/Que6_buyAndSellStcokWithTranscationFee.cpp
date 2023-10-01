// Leetcode -> 714. Best Time to Buy and Sell Stock with Transaction Fee
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/


// same as the previous questions


// Approch -> 1: recursion
// T.C. = O(2^N)
// S.C. = O(N)
class Solution {

    int solve(int idx, int buy, int fee, vector<int> &prices){

        // base cases
        if(idx >= prices.size())
            return 0 ;


        // explore all possibilities
        int profit ;
        if(buy){    
            profit = max( ( -prices[idx] + solve(idx+1, 0, fee, prices) ), solve(idx+1, 1, fee, prices) ) ;
        }   
        else{
            profit = max( ( prices[idx] - fee + solve(idx+1, 1, fee, prices) ) , solve(idx+1, 0, fee, prices) ) ;
        }

        return profit ;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        
        return solve(0, 1, fee, prices) ;
    }
};




// Approch -> 2: Memoization + recursion 
// T.C. = O(N * 2)
// S.C. = O(N * 2) + O(N)
class Solution {

    int solve(int idx, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp){

        // base cases
        if(idx >= prices.size())
            return 0 ;

        if(dp[idx][buy] != -1)
            return dp[idx][buy] ;


        // explore all possibilities
        int profit ;
        if(buy){    
            profit = max( ( -prices[idx] + solve(idx+1, 0, fee, prices, dp) ), solve(idx+1, 1, fee, prices, dp) ) ;
        }   
        else{
            profit = max( ( prices[idx] - fee + solve(idx+1, 1, fee, prices, dp) ) , solve(idx+1, 0, fee, prices, dp) ) ;
        }

        return dp[idx][buy] = profit ;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size()  ;

        vector<vector<int>> dp(n, vector<int>(2, -1)) ;
        
        return solve(0, 1, fee, prices, dp) ;
    }
};





// Approch -> 3: Tabulation
// T.C. = O(N * 2)
// S.C. = O(N * 2)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size()  ;

        vector<vector<int>> dp(n+1, vector<int>(2, 0)) ; 

        // base cases alaready comes in decleration od dp

        for(int idx = n-1 ; idx >= 0 ; idx--){

            for(int buy = 0 ; buy <= 1 ; buy++){
                
                // copy the recurance
                // explore all possibilities
                int profit ;
                if(buy){    
                    profit = max( ( -prices[idx] + dp[idx+1][0] ), dp[idx+1][1] ) ;
                }   
                else{
                    profit = max( ( prices[idx] - fee + dp[idx+1][1] ) , dp[idx+1][0] ) ;
                }

                dp[idx][buy] = profit ;

            }
        }
        
        return dp[0][1] ;
    }
};