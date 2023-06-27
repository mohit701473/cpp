// LeetCode -> https://leetcode.com/problems/max-consecutive-ones-iii/description/


// Approch -> 1: Brute Force Approch
/*
    Algo -> step -> 1: Find All the subarrays which contains at moat k zeros
            step -> 2: after finding subarrays from step 1 now check the length of the subaarays
*/
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n=nums.size() ;
        int maxOnes = 0 ;

        for(int i=0 ; i<n ; i++){
            int zeroCount = k ; // this zeroCOunt counts the no. of zero in a particuluar suarray
            int j=i ;

            // step -> 1: finding the suarray which contain at most k zeros
            while(j<n && (zeroCount > 0 || nums[j] == 1)){
                if(nums[j] == 0)
                    zeroCount-- ;

                j++ ;
            }

            // step -> 2: updating the ans of maxConsicutive ones in a subarray
            maxOnes = max(maxOnes, j-i) ;
        }

        return maxOnes ;
    }
};



// Approch -> 2: Sliding Window Approch
/*
    Here our approch is to maintain a window such that the window contain at most k zero at a time so after the fliping that k zero it becomes one
    for thsi we use i, j & zeroCount variables

*/
// T.C. = O(N)  we have used another while loop but it doesn't contribute to the complexity
// S.C. = O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int i=0, j=0, zeroCount=0, n=nums.size(), ans=0 ;

        while(j<n){
            if(nums[j] == 0){
                zeroCount++ ;

                // this loop maintain the window such that window have at most k zeros
                while(i<n && zeroCount > k){
                    if(nums[i] == 0)
                        zeroCount-- ;
                    i++ ;
                }
            }

            ans = max(ans, j-i+1) ;
            j++ ;
        }

        return ans ;
    }
};






// Approch -> 3: Prefix Sum Approch
/*
    Intuition -> The sum of the subarray should be between w and w-k where w is the size of subarray and k is the number of zeroes that we can flip.

    Approach
        i=front index of subarray
        j=back index of subarray
        k=number of 0's that can be flipped

        We increase the start point i as we move and if sum is less than the subarraysize(i-j+1) minus zeros to be flipped(k), we increse the back 
        point to make array smaller or remove elements from back. Simultaneously wereduce the sum by that element too.
        After this operation we get a valid window and we compare it with previous ize and take maximum of them.
        Repeat the process till end
*/
// T.C. = O(N)  we have used another while loop but it doesn't contribute to the complexity
// S.C. = O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

       int n=nums.size(),sum=0,j=0,ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(sum<i-j+1-k)
            {
                sum-=nums[j];
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};