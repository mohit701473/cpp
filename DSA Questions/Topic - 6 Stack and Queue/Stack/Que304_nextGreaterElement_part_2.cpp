// LeetCode
https://leetcode.com/problems/next-greater-element-ii/editorial/




// Approch - 1 using stack
// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(N)
class Solution {

    void passOne(vector<int> &nums, stack<int> &s, vector<int> &ans){
        int n = nums.size() ;
        for(int i=n-1 ; i >=0 ; i--) {

            if(s.size()>1 && s.top() > nums[i]){
                ans[i] = s.top() ;
                s.push(nums[i]) ;
            }
            else{
                while(s.size() != 1 && s.top() <= nums[i]) {
                    s.pop() ;
                }
                
                if(s.size() != 1){
                    ans[i] = s.top() ;
                }
                s.push(nums[i]) ;
            }
        }
    }


    void passSecond(vector<int> &nums, stack<int> &s, vector<int> &ans){
        int n = nums.size() ;
        for(int i=n-1 ; i >=0 ; i--) {
            if(ans[i] == INT_MIN){
                if(s.size()>1 && s.top() > nums[i]){
                    ans[i] = s.top() ;
                    s.push(nums[i]) ;
                }
                else{
                    while(s.size() != 1 && s.top() <= nums[i]) {
                        s.pop() ;
                    }

                    ans[i] = s.top() ;
                    s.push(nums[i]) ;
                }
            }
        }
    }

public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n, INT_MIN) ;
        stack<int> s ;
        s.push(-1) ;

        passOne(nums, s, ans) ;
        passSecond(nums, s, ans) ;

        return ans ;
    }
};



// Approch - 2 using two for loops
// Expected Time Complexity : O(N^2)
// Expected Auxiliary Space : O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n, -1) ;

        for(int i=0 ; i<nums.size() ; i++){
            bool flag = true ;
            for(int j=i+1 ; j<nums.size() ; j++){
                if(nums[j] > nums[i]){
                    ans[i] = nums[j] ;
                    flag = false ;
                    break ;
                }
            }

            if(flag){
                for(int j=0 ; j<i ; j++){
                    if(nums[j] > nums[i]){
                        ans[i] = nums[j] ;
                        break ;
                    }
                }
            }
        }

        return ans ;
    }
};

