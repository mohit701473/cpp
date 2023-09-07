// LeetCode -> 494. Target Sum
https://leetcode.com/problems/target-sum/description/




// Approch -> 1: Recursion
// T.C. = O(2^n)
// S.C. = O(n)
class Solution {

    int solveRecursive(int idx, int target, vector<int> &nums){
        // base cases 
        if(idx == 0){
            if(target == 0 && nums[0] == 0) return 2 ;
            if(nums[0] == target || nums[0] == -1 * target) return 1 ;
            return 0 ;
        }

        // explore all possibilities 
        int positive = solveRecursive(idx-1, target - nums[idx], nums) ;

        int negative = solveRecursive(idx-1, target + nums[idx], nums) ;

        return positive + negative ;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        return solveRecursive(n-1, target, nums) ;
    }
};






// Approch -> same as que5_partitionsWithGivenDifference
class Solution {

    int solveTab(vector<int>& arr, int k)
    {
        int n = arr.size() ;
        vector<vector<int>> dp(n, vector<int>(k+1, 0)) ;

        if(arr[0] == 0) dp[0][0] = 2 ; // 2 cases -pick and not pick
        else dp[0][0] = 1 ;   // 1 case - not pick

        if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1 ; // 1 case -pick

        for(int idx = 1 ; idx<n ; idx++){

            for(int target = 0 ; target <= k ; target++){

                int notTake = dp[idx-1][target] ;  // solveMem(idx-1, sum, arr, dp) ;

                int take = 0 ;

                if(arr[idx] <= target){
                    take = dp[idx-1][target-arr[idx]] ; // solveMem(idx-1, sum-arr[idx], arr, dp) ;
                }

                dp[idx][target] = take + notTake  ;			
            }
        }


        return dp[n-1][k] ;
    }


    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0 ;

        for(auto it: arr){
            totalSum += it ;
        }

        if(totalSum - d < 0 || (totalSum - d) % 2 != 0) return  0 ;

        int k = (totalSum - d) / 2 ;
        
        return solveTab(arr, k) ;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return countPartitions(nums.size(), target, nums) ;
    }
};


