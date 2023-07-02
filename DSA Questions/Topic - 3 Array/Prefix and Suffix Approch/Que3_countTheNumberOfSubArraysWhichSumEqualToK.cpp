// LeetCode -> 560. Subarray Sum Equals K
https://leetcode.com/problems/subarray-sum-equals-k/description/



// Approch -> 1: Brute Force Approch 
/*
Approch -> find all the subarray & check the sum of all subaray with K 
*/
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int ans = 0 ;
        
        for(int i=0 ; i<nums.size() ; i++){
            int sum = 0 ;
            for(int j=i ; j<nums.size() ; j++){
                sum += nums[j] ;
                
                if(sum == k){
                    ans++ ;
                }
            }
        }
        
        return ans ;
    }
};




// Approch -> 2: Using Hash Map + Prefix Sum 
// This is the optimised code for all positive & negative integers
/*
Approch -> Here we are using an unordered_map called prefixSumMap and this will store the sum of the previous sub arrays
           ex -> input = -13 0 6 15 16 2 15 -12 17 -16 0 -3 19 -3 2 -9 -6 , N=17 , K=15
*/
// T.C. = O(N)  but in the worst case when lots of collision occured then unordered map takes O(N) so in that case T.C. = O(N^2)
// S.C. = O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int ans = 0, n = nums.size(), sum = 0 ;
        unordered_map<int, int> prefixSumMap ;
        prefixSumMap[0]++ ; // thsi is bcz when sum = k then remainingSum = sum - k => 0

        for(int i=0 ; i<n ; i++){
            sum += nums[i] ;

            int remainingSum = sum - k ;
            if( prefixSumMap.find(remainingSum) != prefixSumMap.end() ){
                ans += prefixSumMap[remainingSum] ;
            }

            prefixSumMap[sum]++ ;
        }

        return ans ;
    }
};