// LeetCode -> 416. Partition Equal Subset Sum
https://leetcode.com/problems/partition-equal-subset-sum/



// Approch -> 4: Sapce Optimization
// T.C. = O(N * Sum)
// S.C. = O(Sum)
class Solution {

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size() ;
        
        vector<bool> prev(sum+1, false) , curr(sum+1, false) ;
        
        prev[0] = curr[0] = true ;

        if(arr[0] <= sum) prev[arr[0]] = true ;
        
        
        for(int idx = 1 ; idx<n ; idx++){
            
            for(int target = 1 ; target<=sum ; target++){
                
                
                bool notTake = prev[target] ;
        
                bool take = false ;
                if(arr[idx] <= target)
                    take = prev[target-arr[idx]] ;
                
                curr[target] = take | notTake ;
                
            }
            
            prev = curr ;
        }
        
        return prev[sum] ;
    }

public:
    bool canPartition(vector<int>& nums) {

        int sum = 0 ;

        for(auto it: nums){
            sum += it ;
        }

        // sum is odd so we can't Partition Equal Subset Sum
        if(sum & 1) return false ;

        int halfSum = sum / 2 ;

        return isSubsetSum(nums, halfSum) ;
    }
};