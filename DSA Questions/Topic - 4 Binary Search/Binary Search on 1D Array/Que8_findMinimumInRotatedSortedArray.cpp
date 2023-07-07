// LeetCode -> 153. Find Minimum in Rotated Sorted Array
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


// Approch -> 1: Binary Search
// T.C. = O(log(N)) 
// S.C. = O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX ;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            // It is guarantee that one of the part either left or right will be sorted
            //if left part is sorted:
            if (nums[low] <= nums[mid]) {
               ans = min(ans, nums[low]) ;
               low = mid+1 ;
            }

            else { //if right part is sorted:
                ans = min(ans, nums[mid]) ;
                high = mid-1 ;
            }
        }
        return ans ;
    }
};