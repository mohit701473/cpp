// Leetcode -> 34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/




// Approch -> 1: Binary Search
// T.C. = O(2log(N))
// S.C. = O(1)
class Solution {
    int getStartIdx(vector<int>& nums, int n, int k){
        int idx = -1 ;
        int s = 0 , e = n-1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            
            if(nums[mid] == k){
                idx = mid ;
                e = mid -1 ;
            }else if(nums[mid] > k) e = mid - 1;
            else s = mid + 1;
        }
        
        return idx ;
    }


    int getEndIdx(vector<int>& nums, int n, int k){
        int idx = -1 ;
        int s = 0 , e = n-1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            
            if(nums[mid] == k){
                idx = mid ;
                s = mid + 1 ;
            }else if(nums[mid] > k) e = mid - 1;
            else s = mid + 1;
        }
        
        return idx ;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() ;
        if(n == 0) return {-1,-1} ;
        int startIdx = getStartIdx(nums, n, target) ;
        int endIdx = getEndIdx(nums, n, target) ;

        return {startIdx, endIdx} ;
    }
};