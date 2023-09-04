// leetCode -> 322. Coin Change
https://leetcode.com/problems/coin-change/description/




// Approch -> 1: Memoization + recursion
// T.C. = O(amount * N)
// S.C. = O(amount) + O(N)
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
        sort(coins.begin(), coins.end()) ;

        vector<int> dp(amount+1, INT_MAX) ;

        int count = tabulationMethod(amount, coins, dp) ;

        return count != INT_MAX ? count : -1 ;
    }
};




// Approch -> 2: Tabulation
// T.C. = O(amount * N)
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




// Striver Apprioch


// memoization
// Time Complexity: O(N*T)
// Reason: There are N*T states therefore at max ‘N*T’ new problems will be solved.
// Space Complexity: O(N*T) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).
int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

    if(ind == 0){
        if(T%arr[0] == 0) return T/arr[0];
        else return 1e9;
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    int notTaken = 0 + minimumElementsUtil(arr,ind-1,T,dp);
    
    int taken = 1e9;
    if(arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = min(notTaken,taken);
}


int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));
    int ans =  minimumElementsUtil(arr, n-1, T, dp);
    if(ans >= 1e9) return -1;
    return ans;
}



// tabulation aproch 
// Time Complexity: O(N*T)
// Reason: There are two nested loops
// Space Complexity: O(N*T)
// Reason: We are using an external array of size ‘N*T’. Stack Space is eliminated.
int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}
