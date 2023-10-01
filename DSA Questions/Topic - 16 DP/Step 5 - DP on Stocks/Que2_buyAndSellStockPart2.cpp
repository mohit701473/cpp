// LeetCode -> 122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/



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
            profit = max( ( prices[idx] + solve(idx+1, 1, prices) ) , solve(idx+1, 0, prices)) ;
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
            profit = max( ( prices[idx] + solve(idx+1, 1, prices, dp) ) , solve(idx+1, 0, prices, dp)) ;
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

        vector<vector<int>> dp(n+1, vector<int>(2, -1)) ;

        // base case
        dp[n][0] = dp[n][1] = 0 ;

        for(int idx = n-1 ; idx >=0 ; idx--){

            for(int buy = 0 ; buy <= 1 ; buy++){
                
                // copy paste recurance from recursion approch
                // Explore all possibilities 
                int profit ;
                if(buy){
                    profit = max( (-prices[idx] + dp[idx+1][0]) , dp[idx+1][1]) ;
                }
                else{
                    profit = max( ( prices[idx] + dp[idx+1][1] ) , dp[idx+1][0]) ;
                }

                dp[idx][buy] = profit ;
            }
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

        vector<int> ahead(2, 0) , curr(2, 0) ;

        // base case

        for(int idx = n-1 ; idx >=0 ; idx--){

            for(int buy = 0 ; buy <= 1 ; buy++){
                
                // copy paste recurance from recursion approch
                // Explore all possibilities 
                int profit ;
                if(buy){
                    profit = max( (-prices[idx] + ahead[0]) , ahead[1]) ;
                }
                else{
                    profit = max( ( prices[idx] + ahead[1] ) , ahead[0]) ;
                }

                curr[buy] = profit ;
            }
            
            ahead = curr ;
        }

        return ahead[1] ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        int aheadNotBuy = 0 , aheadBuy = 0 ;
        int currNotBuy = 0 , currBuy = 0 ; 

        // base case

        for(int idx = n-1 ; idx >=0 ; idx--){

            currBuy = max( (-prices[idx] + aheadNotBuy) , aheadBuy) ;
        
            currNotBuy = max( ( prices[idx] + aheadBuy ) , aheadNotBuy) ;

            aheadNotBuy = currNotBuy ;

            aheadBuy = currBuy ;
        }

        return aheadBuy ;
    }
};