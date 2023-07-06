// LeetCode -> 152. Maximum Product Subarray
https://leetcode.com/problems/maximum-product-subarray/


// GFG -> Maximum Product Subarray
https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/0


// Approch -> 1: Brute Force Approch
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int ans = INT_MIN ;

        for(int i=0 ; i<nums.size() ; i++){
            int product = 1 ;
            for(int j=i ; j<nums.size() ; j++){
                product *= nums[j] ;

                ans = max(ans, product) ;
            }
        }

        return ans ;
    }
};


// Approch -> 2: Prefix & Suffix Product
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        int prefix = 1, suffix = 1, ans = INT_MIN ;
        
        for(int i=0 ; i<n ; i++){
            if(prefix == 0) prefix = 1 ;
            if(suffix == 0) suffix = 1 ;

            prefix *= nums[i] ;
            suffix *= nums[n-i-1] ;

            ans = max(ans, max(prefix, suffix)) ;
        }

        return ans ;
    }
};