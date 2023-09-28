// LeetCode -> 213. House Robber II
https://leetcode.com/problems/house-robber-ii/



// Approch -> 1: Recursive Approch
// T.C. = O(2^N)
// S.C. = O(N)
class Solution {

    int solve(int idx, vector<int> &nums, int n){
        if(idx >= n) return 0 ;

        int pick = nums[idx] + solve(idx+2, nums, n) ;

        int notPick = solve(idx+1, nums, n) ;

        return max(pick , notPick) ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1) return nums[0] ;
        
        return max(solve(0, nums, n-1), solve(1, nums, n)) ;
    }
};



// Approch -> 2: Recusion + Memoization
// T.C. = O(N)
// S.C. = O(N) + O(N) {Dp array + recursive call satck}
class Solution {

    int solve(int idx, vector<int> &nums, int n, vector<int> &dp){
        if(idx >= n) return 0 ;

        // step -> 3: return the result of subproblem if it is previously solved
        if(dp[idx] != -1)
            return dp[idx] ;

        int pick = nums[idx] + solve(idx+2, nums, n, dp) ;

        int notPick = solve(idx+1, nums, n, dp) ;

        // step -> 2: store the result of the subproblem
        dp[idx] = max(pick , notPick) ;
        return dp[idx] ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1) return nums[0] ;
        
        // here we are using two dp array bcz their might some cases such that [1,2,3] cause problem with using only 
        // one dp array
        vector<int> dp1(n,-1) ;
        int ans1 = solve(0, nums, n-1, dp1) ;

        vector<int> dp2(n,-1) ;
        int ans2 = solve(1, nums, n, dp2) ;

        return max(ans1, ans2) ;
    }
};




// Approch -> 3: Tabulation Method
// T.C. = O(N)
// S.C. = O(N)
class Solution {
    int tabulationMethod(vector<int> &nums, int stIdx, int n){
        // step -> 1: declear a dp array
        vector<int> dp(n, -1) ;

        if(stIdx == 1) dp[0] = 0 ;

        // step -> 2: analyses the base cases 
        dp[stIdx] = nums[stIdx] ;
        
        // step -> 3: apply for loop and get final ans.
        for(int i=stIdx+1 ; i<n ; i++){
            int pick = nums[i] + (i-2 >= 0 ? dp[i-2] : 0) ;
            int notPick = dp[i-1] ;

            dp[i] = max(pick , notPick) ;
        }

        return dp[n-1] ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1) return nums[0] ;
    
        int ans1 = tabulationMethod(nums, 0, n-1) ;
        int ans2 = tabulationMethod(nums, 1, n) ;

        return max(ans1, ans2) ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(N)
// S.C. = O(1)
class Solution {
    int tabulationMethod(vector<int> &nums, int stIdx, int n){
        
        int oneStepPrevious = nums[stIdx] ; // dp[stIdx] = nums[stIdx] ;
        int twoStepPrevious = 0 ; // dp[i-2] 
        
        for(int i=stIdx+1 ; i<n ; i++){
            int pick = nums[i] + twoStepPrevious ; // nums[i] + (i-2 >= 0 ? dp[i-2] : 0) ;
            int notPick = oneStepPrevious ; // dp[i-1] ;

            twoStepPrevious = oneStepPrevious ;
            oneStepPrevious = max(pick , notPick) ; // dp[i] = max(pick , notPick) ;
        }

        return oneStepPrevious ; // dp[n-1] ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1) return nums[0] ;
    
        int ans1 = tabulationMethod(nums, 0, n-1) ;
        int ans2 = tabulationMethod(nums, 1, n) ;

        return max(ans1, ans2) ;
    }
};

