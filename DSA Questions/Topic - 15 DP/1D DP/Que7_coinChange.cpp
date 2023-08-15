



// Approch -> 1: Recursion
/*
intuition -> we try all possible ways to make the amout from the given coins and count the no. of coins required in all
             ways & get the minimum no. of coins 
*/
// T.C. = Exponential
// S.C. = O(amount) 
class Solution {

    int miniumNoOfCoinsRequired(int amount , vector<int> &coins){
        if(amount == 0) return 0 ;
        if(amount < 0) return INT_MAX ;

        int ans = INT_MAX ;
        for(int i=0 ; i<coins.size() ; i++){
            int requiredAmount = amount - coins[i] ;
            int coinCount = miniumNoOfCoinsRequired(requiredAmount , coins) ;

            if(coinCount != INT_MAX)
                ans = min(ans , coinCount+1) ;
        }

        return ans ;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int count = miniumNoOfCoinsRequired(amount, coins) ;
        return count != INT_MAX ? count : -1 ;
    }
};





// Approch -> 2: Recusion + Memoization
// T.C. = O(amount * N)    N -> size of coins array
// S.C. = O(amount) + O(amount) {Dp array + recursive call satck}
class Solution {

    int miniumNoOfCoinsRequired(int amount , vector<int> &coins, vector<int> &dp){
        if(amount == 0) return 0 ;
        if(amount < 0) return INT_MAX ;

        // step -> 3: if subproblem is previously computed then directly return the result 
        if(dp[amount] != -1)
            return dp[amount] ;

        int ans = INT_MAX ;
        for(int i=0 ; i<coins.size() ; i++){
            int requiredAmount = amount - coins[i] ;
            int coinCount = miniumNoOfCoinsRequired(requiredAmount , coins, dp) ;

            if(coinCount != INT_MAX)
                ans = min(ans , coinCount+1) ;
        }

        // step -> 2: store subproblem result in dp array
        dp[amount] = ans ;
        return dp[amount] ;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // step -> 1: create a DP array
        vector<int> dp(amount+1, -1) ;
        int count = miniumNoOfCoinsRequired(amount, coins, dp) ;

        return count != INT_MAX ? count : -1 ;
    }
};




// Approch -> 3: Tabulation Method
// T.C. = O(amount * N) N -> size of coins array
// S.C. = O(amount)
class Solution {

    int tabulationMethod(int amount, vector<int> &coins){
        // step -> 1: create a dp array
        vector<int> dp(amount+1, INT_MAX) ;

        // step -> 2: analyses base cases
        dp[0] = 0 ;

        // step -> 3: apply loop and get answer
        for(int target = coins[0] ; target <= amount ; target++){
            int ans = INT_MAX ;

            // dp[target] = minimum no. of coins required make target 

            for(int i=0 ; i<coins.size() && target-coins[i] >= 0 ; i++){
                int requiredAmount = target - coins[i] ;

                if(dp[requiredAmount] != INT_MAX) 
                    ans = min(ans , dp[requiredAmount] + 1) ;
            }

            dp[target] = ans ;
        }

        return dp[amount] ;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end()) ;
        int count = tabulationMethod(amount, coins) ;

        return count != INT_MAX ? count : -1 ;
    }
};