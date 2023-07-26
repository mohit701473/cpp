// LeetCode -> 260. Single Number III
https://leetcode.com/problems/single-number-iii/description/


// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans ;
        int x_or = 0 ;
        for(int i=0 ; i<n ; i++)
            x_or ^= nums[i] ;

        int count = 0 ;
        while(x_or){
            if(x_or & 1)
                break ;
            count++ ;
            x_or >>= 1 ;
        }

        int xor1=0 , xor2=0 ;

        for(int i=0 ; i<n ; i++){
            if(nums[i] & (1<<count))
                xor1 ^= nums[i] ;
            else xor2 ^= nums[i] ;
        }

        ans.push_back(xor1) ;
        ans.push_back(xor2) ;
        
        return ans ;
    }
};