// LetCode -> 1283. Find the Smallest Divisor Given a Threshold
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/




// Approch -> 1: Binary Search
// T.C. = O(Nlog(N))
// S.C. = O(1)
class Solution {

    int getMax(vector<int>& nums){
        int n = nums.size() ;
        int maxi = INT_MIN ;
        for(int i=0 ; i<n ; i++){
            maxi = max(maxi, nums[i]) ;
        }

        return maxi ;
    }

    int getDivisionSum(vector<int>& nums, int mid){
        int sum = 0 ;
        for(auto it: nums) sum += ceil(double(it) / double(mid)) ;
        return sum ;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1, n = nums.size() ;
        int low = 1, high = getMax(nums) ;
        while(low<=high){
            int mid = low +(high-low)/2 ;
            int sum = getDivisionSum(nums, mid) ;
            if(sum <= threshold){
                ans = mid ; 
                high = mid -1 ;
            }else low = mid+1 ;
        }

        return ans ;
    }
};