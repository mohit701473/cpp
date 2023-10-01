// LeetCode -> 309. Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/





// Approch -> 1: recursion
// T.C. = O(2^N)
// S.C. = O(N)
class Solution {

    int solve(int idx, int buy, vector<int> prices){
        
        // bases cases
        if(idx >= prices.size())
            return 0 ;

        // Explore all possibilities 
        int profit ;
        if(buy){
            profit = max( ( -prices[idx] + solve(idx+1, 0, prices) ) , solve(idx+1, 1, prices)) ;
        }
        else{
            profit = max( ( prices[idx] + solve(idx+2, 1, prices) ) , solve(idx+1, 0, prices)) ;
        }

        return profit ;
    }

public:
    int maxProfit(vector<int>& prices) {

        return solve(0, 1, prices) ;
    }
};





// Approch -> 2: Memoization + recursion 
// T.C. = O(N * 2)
// S.C. = O(N * 2) + O(N)
class Solution {

    int solve(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp){
        
        // bases cases
        if(idx >= prices.size())
            return 0 ;

        if(dp[idx][buy] != -1)
            return dp[idx][buy] ;

        // Explore all possibilities 
        int profit ;
        if(buy){
            profit = max( ( -prices[idx] + solve(idx+1, 0, prices, dp) ) , solve(idx+1, 1, prices, dp)) ;
        }
        else{
            profit = max( ( prices[idx] + solve(idx+2, 1, prices, dp) ) , solve(idx+1, 0, prices, dp)) ;
        }

        return dp[idx][buy] = profit ;
    }

public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<vector<int>> dp(n, vector<int>(2, -1)) ;

        return solve(0, 1, prices, dp) ;
    }
};




// Approch -> 3: Tabulation
// T.C. = O(N * 2)
// S.C. = O(N * 2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<vector<int>> dp(n+2, vector<int>(2, 0)) ;

        // base case
        dp[n][0] = dp[n][1] = 0 ;

        for(int idx = n-1 ; idx >=0 ; idx--){                
                // copy paste recurance from recursion approch
                // Explore all possibilities 
            
            dp[idx][1] = max( (-prices[idx] + dp[idx+1][0]) , dp[idx+1][1]) ;
            
            dp[idx][0] = max( ( prices[idx] +  dp[idx+2][1] )  , dp[idx+1][0]) ;
        }

        return dp[0][1] ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(N * 2)
// S.C. = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<int> front1(2, 0) ; // idx+1
        vector<int> front2(2, 0) ;// idx+2
        vector<int> curr(2, 0) ;

        // base cas

        for(int idx = n-1 ; idx >=0 ; idx--){                
                
            curr[1] = max( (-prices[idx] +front1[0]) , front1[1]) ;
            
            curr[0] = max( ( prices[idx] +  front2[1] )  , front1[0]) ;

            front2 = front1 ;
            front1 = curr ;
        }

        return front1[1] ;
    }
};