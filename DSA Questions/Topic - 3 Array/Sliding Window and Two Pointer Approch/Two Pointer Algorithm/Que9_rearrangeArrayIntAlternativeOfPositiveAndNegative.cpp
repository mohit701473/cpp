// LeetCode -> 2149. Rearrange Array Elements by Sign
https://leetcode.com/problems/rearrange-array-elements-by-sign/




// Approch -> 1: Using two pointer approch
// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size() ;
        vector<int> ans ;
        int i = 0, j = 0 ;

       while(i<n && nums[i] < 0) i++ ; 
       ans.push_back(nums[i]) ; 
       i++ ;
       while(i<n && nums[i] < 0) i++ ; 
       while(j<n && nums[j] >= 0) j++ ;

       // i points to the positive integers
       // j points to the negative integers

       while(i<n && j<n){
           int temp = ans.back() ;

           if(temp >= 0){
               ans.push_back(nums[j]) ;
               j++ ;
               while(j<n && nums[j] >= 0) j++ ;
           }
           else{
               ans.push_back(nums[i]) ;
               i++ ;
               while(i<n && nums[i] < 0) i++ ; 
           }
       }

       if(i==n) ans.push_back(nums[j]) ;
       else ans.push_back(nums[i]) ;

        return ans ;
    }
};




// Approch -> 1: Using two pointer approch
// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n,0) ;
        int i = 0 , j = 1 ;
        for(int idx=0 ; idx<n ; idx++){
        
            if(nums[idx] >= 0){
                ans[i] = nums[idx] ;
                i += 2 ;
            }
            else{
                ans[j] = nums[idx] ;
                j += 2 ;
            }
        }

        return ans ;
    }
};



// GFG -> Alternate positive and negative numbers
https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1


// Approch -> 1: Using two pointer approch
// T.C. = O(N)
// S.C. = O(N)
class Solution{
public:

	void rearrange(int nums[], int n) {
	    
        vector<int> ans ;
        int i = 0, j = 0 ;

       while(i<n && nums[i] < 0) i++ ; 
       if(i<n) ans.push_back(nums[i++]) ; 
       while(i<n && nums[i] < 0) i++ ; 
       while(j<n && nums[j] >= 0) j++ ;

       // i points to the positive integers
       // j points to the negative integers

       while(i<n && j<n){
           int temp = ans.back() ;

           if(temp >= 0){
               ans.push_back(nums[j]) ;
               j++ ;
               while(j<n && nums[j] >= 0) j++ ;
           }
           else{
               ans.push_back(nums[i]) ;
               i++ ;
               while(i<n && nums[i] < 0) i++ ; 
           }
       }

      
        while(j<n) {
            if(nums[j] < 0) ans.push_back(nums[j]) ;
            j++ ;
        }
    
        while(i<n){
            if(nums[i] >= 0) ans.push_back(nums[i]) ;
            i++ ;
        }
           
        for(int idx=0 ; idx<n ; idx++){
           nums[idx] = ans[idx] ;
       }

	}
};