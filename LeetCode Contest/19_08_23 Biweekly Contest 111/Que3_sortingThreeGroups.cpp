// LeetCode -> 2826. Sorting Three Groups
https://leetcode.com/problems/sorting-three-groups/



// Approch -> 1: Brute Force Approch
/*
Intuition
We can atmost divide an array into 3 parts and atleast into 1 part so, lets interate through all the possible 
partitions and store the minimum of all.

Now lets say we consider:
0 -> i as partition with all 1s
i -> j as partition with all 2s
j-> nums.size() as partition with all 3s

Consider all possible values of i and j and store the minimum of operations
*/
// T.C. = O(N^3)
// S.C. = O(1)
class Solution {

    int minOps(int i, int j, vector<int>& nums) {
        int count = 0;
        for(int x=0;x<i;x++) {
            if(nums[x] != 1) count++;
        // if the value at x is not 1, an operation is needed!
        }
        for(int x=i;x<j;x++) {
            if(nums[x] != 2) count++;
        // if the value at x is not 2, an operation is needed!
        }
        for(int x=j;x<nums.size();x++) {
            if(nums[x] != 3) count++;
        // if the value at x is not 3, an operation is needed!
        }
        return count;
    }


public:
    int minimumOperations(vector<int>& nums) {
        int out = INT_MAX;
        int n = nums.size();
        for(int i=0;i<=n;i++) {
            for(int j=i;j<=n;j++) {
                out = min(out, minOps(i, j, nums));
            }
        }
        return out;
    }
};





// Approch -> 2: Recursion
// T.C. = O(N^3)
// S.C. = O(N)
class Solution {

    int solveRecursive(int idx, int prevGrp, vector<int> &nums){
        // step -> 1: write all Base Cases
        if(idx >= nums.size()){
            return 0 ; 
        }

        // step -> 2: Explore all the condition or paths
        int mini = INT_MAX ;
        int currGrp = nums[idx] ;
        for(int newGrp = prevGrp ; newGrp <= 3 ; newGrp++){
            int requireOp = solveRecursive(idx+1 , newGrp , nums) ;

            if(newGrp != currGrp){
                requireOp = requireOp + 1 ; // mtlb ki current index ke group ko change krne ke liye bhi ek operation ki requirement hai
            }

            mini = min(mini, requireOp) ;
        }

        return mini ;
    }

public:
    int minimumOperations(vector<int>& nums) {
        return solveRecursive(0, 1, nums) ;
    }
};



// Approch -> 2: Memoization + Recursion
// T.C. = O(3N)
// S.C. = O(3N)
class Solution {

    int solveMem(int idx, int prevGrp, vector<int> &nums, vector<vector<int>> &dp){
        // write all Base Cases
        if(idx >= nums.size()){
            return 0 ; 
        }

        // step -> 3: return result of subproblem
        if(dp[idx][prevGrp] != -1){
            return dp[idx][prevGrp] ;
        }

        // Explore all the condition or paths
        int mini = INT_MAX ;
        int currGrp = nums[idx]-1 ;
        for(int newGrp = prevGrp ; newGrp < 3 ; newGrp++){
            int requireOp = solveMem(idx+1 , newGrp , nums, dp) ;

            if(newGrp != currGrp){
                requireOp = requireOp + 1 ; // mtlb ki current index ke group ko change krne ke liye bhi ek operation ki requirement hai
            }

            mini = min(mini, requireOp) ;
        }

        // step -> 2: store result of subproblem
        dp[idx][prevGrp] = mini ;
        return dp[idx][prevGrp] ;
    }

public:
    int minimumOperations(vector<int>& nums) {
        // step -> 1: declear a dp data structure
        vector<vector<int>> dp(nums.size() , vector<int>(3,-1)) ;

        return solveMem(0, 0, nums, dp) ;
    }
};