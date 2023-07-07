// LeetCode -> 81. Search in Rotated Sorted Array II
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/



// Approch -> 1: Binary Search
// T.C. = O(log(N)) in the avg. cases but in the work case T.C. ~ O(n/2)
// S.C. = O(1)
class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            //if mid points the target
            if (nums[mid] == k) return true;

            // if nums[low] == nums[mid] == nums[high] ex = [1,0,1,1,1] k = 0 
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++, high-- ;
                continue;
            }

            // It is guarantee that one of the part either left or right will be sorted
            //if left part is sorted:
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= k && k <= nums[mid]) {
                    //element exists:
                    high = mid - 1;
                }
                else {
                    //element does not exist:
                    low = mid + 1;
                }
            }

            else { //if right part is sorted:
                if (nums[mid] <= k && k <= nums[high]) {
                    //element exists:
                    low = mid + 1;
                }
                else {
                    //element does not exist:
                    high = mid - 1;
                }
            }
        }
        return false ;
    }
};