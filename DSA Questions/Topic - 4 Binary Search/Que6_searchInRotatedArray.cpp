// LeetCode -> 33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/description/



// Approch -> 1: Binary Search
// T.C. = O(log(N))
// S.C. = O(1)
class Solution {
public:
    int search(vector<int>& nums, int k) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            //if mid points the target
            if (nums[mid] == k) return mid;

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
        return -1;
    }
};