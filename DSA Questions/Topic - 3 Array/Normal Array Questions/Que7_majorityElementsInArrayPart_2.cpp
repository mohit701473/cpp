// LeetCode -> 229. Majority Element II
https://leetcode.com/problems/majority-element-ii/



// Approch -> 1: Moore's Voting Algorithm
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int cnt1 = 0, ele1 ;
        int cnt2 = 0 , ele2 ;
        vector<int> ans ;

        // step -> 1: Algo process
        for(int i=0 ; i<n ; i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1 ;
                ele1 = nums[i] ;
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2 = 1 ;
                ele2 = nums[i] ;
            }
            else if(nums[i] == ele1) cnt1++ ;
            else if(nums[i] == ele2) cnt2++ ;
            else {
                cnt1-- ;
                cnt2-- ;
            }
        }

        // step -> 2: Now check that these two element are your ans or not
        cnt1 = 0 ;
        cnt2 = 0 ;
        for(auto it: nums){
            if(it == ele1) cnt1++ ;
            else if(it == ele2) cnt2++ ;
        }

        if(cnt1 > n/3) ans.push_back(ele1) ;
        if(cnt2 > n/3) ans.push_back(ele2) ;

        return ans ;
    }
};