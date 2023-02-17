// LeetCode  Que: 162. Find Peak Element

// T.C. = O(log(n))

class Solution {
public:

    int getPeakElement(vector<int> nums, int l, int h) {

        if(l > h) 
            return -1 ;

        int mid = (l+h) / 2 ;
        int ans ;
        int size = nums.size() ;

        if(mid == 0) {
            // check only right to the mid
            if(nums[mid] > nums[mid+1]) 
                return mid ;

            return mid+1 ;
        }

        if(mid == size-1) {
            // check only left to mid
            if(nums[mid] > nums[mid-1])
                return mid ;

            return mid-1 ;
        }

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] ) {  
            ans = mid ;
            return ans ;
        }

        else {

            if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) {
                ans = getPeakElement(nums, mid+1, h) ;
            }

            else {
                ans = getPeakElement(nums, l, mid-1) ;

            }
        }

        return ans ;
    }

    int findPeakElement(vector<int>& nums) {

        int l = 0 ;
        int h = nums.size() ;

        if(h==1) {
            return 0 ;
        }

        int ans = getPeakElement(nums, l, h) ;

        return ans ;
    }
};

