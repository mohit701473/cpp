// LeetCode -> https://leetcode.com/problems/missing-number/description/


// Approch -> 1: Xor of 1 to n numbers
// T.C. = O(N)
// S.C. = O(1)
class Solution {

    int getXorOfOneToNNumbers(int n){

        if(n%4 == 1) return 1 ;
        if(n%4 == 2) return n+1 ;
        if(n%4 == 3) return 0 ;
        
        return n ; // n%4 == 0 
    }

public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ;
        int xor1 = getXorOfOneToNNumbers(n) ;
        int xor2 = nums[0] ;
        for(int i=1 ; i<n ; i++)
            xor2 ^= nums[i] ;

        return xor1 ^ xor2 ;

    }
};