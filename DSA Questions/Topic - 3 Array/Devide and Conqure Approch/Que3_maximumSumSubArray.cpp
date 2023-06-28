// LeetCode -. 53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/description/



// Approch -> 1: Brute Fore Approch Find the all sub arrays and compare teh sum of alls 
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {

public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size(), maxSum = INT_MIN ;

        for(int i=0 ; i<n ; i++){
            int sum = 0 ;
            for(int j=i ; j<n ; j++){
                sum += nums[j] ;
                maxSum = max(maxSum, sum) ;
            }
        }

        return maxSum ;
    }
};




// Approch -> 2: Devide and Conqure Approch
// T.C. = O(Nlog(N))
// S.C. = O(log(N)) bcz recursive call stack
class Solution {

    int getCrossSubArraySum(vector<int>& nums, int l, int mid, int r){
        int leftSum = INT_MIN ;
        int sum = 0 ;

        for(int i=mid ; i>=l ; i--){
            sum += nums[i] ;
            leftSum = max(leftSum , sum) ;
        }

        int rightSum = INT_MIN ;
        sum = 0 ;
        for(int i=mid+1 ; i<=r ; i++){
            sum += nums[i] ;
            rightSum = max(rightSum, sum) ;
        }

        return leftSum + rightSum ;
    }

    int maxSubArrayDC(vector<int>& nums, int l, int r){
        if(l == r)
            return nums[l] ;

        int mid = (l+r) / 2 ;
        int lss = maxSubArrayDC(nums, l, mid) ;
        int rss = maxSubArrayDC(nums, mid+1, r) ;
        int css = getCrossSubArraySum(nums, l, mid, r) ;
        
        int ans = max(lss, rss) ;
        ans = max(ans, css) ;
        return ans ;
    }

public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ; 
        return maxSubArrayDC(nums, 0, n-1) ; 
    }
};




// Approch -> 3: Kadane's Algorith
/*
Kadane's Algo -> In this algo we have two variables currentBestSum(csum) and overAllBestSum(osum)
                 when csum >=0 then cum += nums[i] else csum < 0 then csum = nums[i]
                 csum >=0 that means you can add nums[i] in your train
                 csum < 0 that mean you should start your tair from new element such taht csum = nums[i]
                 and update your osum 
*/
// T.C. = O(N)
// S.C. = o(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum = nums[0], osum = nums[0] ;

        for(int i=1 ; i<nums.size() ; i++){

            if(csum >=0 ){
                csum += nums[i] ;
            }else{
                csum = nums[i] ;
            }

            osum = max(osum, csum) ;
        }

        return osum ;
    }
};




// Approch -> 3: Kadane's Algorith
/*
Kadane's Algo -> This algo is based on three steps
                 step -> 1: sum = sum + nums[i] 
                 step -. 2: update maxi => maxi = max(maxi, sum)
                 step -> 3: if sum < 0 then reset our sum such that sum = 0
*/
// T.C. = O(N)
// S.C. = o(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0, maxi = nums[0] ;

        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i] ;

            maxi = max(maxi, sum) ;

            if(sum < 0)
                sum = 0;
        }

        return maxi ;
    }
};


