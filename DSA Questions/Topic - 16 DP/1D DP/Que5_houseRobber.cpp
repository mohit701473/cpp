// LeetCode -> 198. House Robber (same as Que4_maximum sum of non adjacent element in array)
https://leetcode.com/problems/house-robber/description/



// Approch -> 1: Recursive Approch
// T.C. = O(2^N)
// S.C. = O(N)
class Solution {
    int solve(int idx, vector<int> &nums){
        // Base Cases
        if(idx == 0) return nums[0] ; // idx=0 mean idx = 1 have not picked
        if(idx < 0) return 0 ; // idx < 0 means idx = 1 have picked

        int pick = nums[idx] + solve(idx-2, nums) ; // pick mean idx index house is robbed so we can't pick idx-1 
                                                    // houce bcz idx-1 is adjacent of idx

        int notPick = 0 + solve(idx-1, nums) ;

        return max(pick, notPick) ;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        return solve(n-1, nums) ;
    }
};



// Approch -> 2: Recusion + Memoization
// T.C. = O(N)
// S.C. = O(N) + O(N) {Dp array + recursive call satck}
class Solution {
    int solve(int idx, vector<int> &nums, vector<int> &dp){
        // Base Cases
        if(idx == 0) return nums[0] ; // idx=0 mean idx = 1 have not picked
        if(idx < 0) return 0 ; // idx < 0 means idx = 1 have picked
        
        // step -> 3: return the result of subproblem if it is previously solved
        if(dp[idx] != -1)
            return dp[idx] ;

        // pick mean idx index house is robbed so we can't pick idx-1 houce bcz idx-1 is adjacent of idx
        int pick = nums[idx] + solve(idx-2, nums, dp) ; 

        int notPick = 0 + solve(idx-1, nums, dp) ;

        // step -> 2: store the result into dp array
        dp[idx] = max(pick, notPick) ;
        return dp[idx] ;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;

        // step -> 1: Declear a dp array
        vector<int> dp(n, -1) ;
        return solve(n-1, nums, dp) ;
    }
};



// Approch -> 3: Tabulation Method
// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        // step -> 1: Declear a dp array
        vector<int> dp(n, -1) ;

        // step -> 2: analyse the base cases
        dp[0] = nums[0] ;

        // step -> 3: apply for to get final answer
        for(int idx=1 ; idx<n ; idx++){
            int pick = nums[idx] + (idx-2 >= 0 ? dp[idx-2] : 0) ; // nums[idx] + solve(idx-2, nums, dp) 

            int notPick = dp[idx-1] ; //  solve(idx-1, nums, dp) ;

            dp[idx] = max(pick, notPick) ;
        }
        return dp[n-1] ;
    }
};


// Approch -> 4: Space Optimization
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;

        int oneStepPrevious = nums[0] ; // dp[0] = nums[0] ;
        int twoStepPrevious = 0 ; // idx < 0 ;

        for(int idx=1 ; idx<n ; idx++){
            int pick = nums[idx] + twoStepPrevious ; // nums[idx] + (idx-2 >= 0 ? dp[idx-2] : 0) ; 
            int notPick = oneStepPrevious ; // dp[idx-1] ;

            twoStepPrevious = oneStepPrevious ;
           oneStepPrevious = max(pick, notPick) ;
        }
        return oneStepPrevious ;
    }
};



