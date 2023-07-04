// LeetCode -> 35. Search Insert Position
https://leetcode.com/problems/search-insert-position/



// Approch -> 1: Binary Search
// T.C. = O(log(N))
// S.C. = O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N = nums.size() ;
        if(target == nums[N-1]) return N-1 ;
        if(target > nums[N-1]) return N ;
        if(target <= nums[0]) return 0 ;
        
        int idx = -1 ;
        int s = 0 , e = N-1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            
            if(nums[mid] >= target){
                idx = mid ;
                e = mid -1 ;
            }else s = mid + 1 ;
        }
        
        return idx ;
    }
};