// 2542. Maximum Subsequence Score
https://leetcode.com/problems/maximum-subsequence-score/

/*
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from 
nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

Example 1:

Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation: 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.
Example 2:

Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation: 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
*/



//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1 Using recursion

class Solution {
public:
    long long getScore(vector<int> &vec1, vector<int> &vec2){
        int min = INT_MAX ;
        int sum = 0 ;
        for(int i=0 ; i<vec1.size() ; i++){
            sum += vec1[i] ;

            if(min > vec2[i])
                min = vec2[i] ;
        }

        return sum * min ;
    }

    void solve(vector<int> &nums1, vector<int> &nums2, int i, vector<int> &vec1, vector<int> &vec2, long long &maxi, int k){

        if(i >= nums1.size()){

            if(vec1.size() == k){
                long long ans = getScore(vec1, vec2) ;
                maxi = max(ans, maxi) ;
                return ;
            }
            return ;
        }

        if(vec1.size() == k){
            long long ans = getScore(vec1, vec2) ;
            maxi = max(ans, maxi) ;
            return ;
        }

        // include
        vec1.push_back(nums1[i]) ;
        vec2.push_back(nums2[i]) ;
        solve(nums1, nums2, i+1, vec1, vec2, maxi, k) ;

        // exclude
        vec1.pop_back() ;
        vec2.pop_back() ;
        solve(nums1, nums2, i+1, vec1, vec2, maxi, k) ;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<int> vec1 ;
        vector<int> vec2 ;
        long long maxi = INT_MIN ;

        solve(nums1, nums2, 0, vec1, vec2, maxi, k) ;

        return maxi ;
    }
};




// Approch - 2 Itrative Approch but it fails in some cases so this is not a correct code but intuitionis correct
// T.C, = O(N^2) 
// S.C. = O(1)
class Solution {
public:

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        long long maxi = INT_MIN ;
        
        for(int i=0 ; i<nums2.size() ; i++){

            int mini = nums2[i] ;
            long long sum = nums1[i] ;
            int count = 1 ;

            for(int j=0 ; j<nums2.size() ; j++){

                if(j != i && nums2[j] >= mini){
                    sum += nums1[j] ;
                    count++ ;
                }

                if(count == k){
                    if(sum * mini > maxi)
                        maxi = sum * mini ;
                    break ;
                }
            }
        }

        return maxi ;
    }
};




// Approch - 3 Using Sorting, Priority Queue(Min Heap)
// T.C. = O(Nlog(N))
// S.C. = O(k)
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int,int>> vec;
        //make pair
        for(int i=0;i<nums1.size();i++)
            vec.push_back({nums2[i],nums1[i]});
        //sort on base of nums2 in descending order
        sort(vec.rbegin(),vec.rend());
        
        long long ans = 0;
        long long curr_sum = 0;
        
        //make k-1 element min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k-1;i++){
            curr_sum += vec[i].second;
            pq.push(vec[i].second);
        }
            
        
        // loop in sorted array from k to array size, taking current element as min and 
        // try to maximize sum of 1st array elements
        for(int i=k-1;i<nums1.size();i++){
            //include ith element to subsequence
            curr_sum+=vec[i].second;
            pq.push(vec[i].second);
            ans = max(ans,curr_sum * vec[i].first);
            //remove min element from priority queue
            curr_sum-=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};

