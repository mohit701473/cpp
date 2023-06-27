// LeetCode -> https://leetcode.com/problems/rotate-array/description/



// APPROACH 1 : Brute Force
/*
    step -> 1: create an another array
    step -> 2: inserts the last k element of nums array into new aray
    step -> 3: insert the first n-k element of nums array into new array
    step -> 4: copy the elements of new array into nums array
*/
// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ;

        if(k==0 || k%n == 0)
            return ;

        k = k%n ;

        // step -> 1: create an another array
        vector<int> rotated ;

        // step -> 2: inserts the last k element of nums array into new aray
        for(int i=n-k ; i<n ; i++)
            rotated.push_back(nums[i]) ;

        // step -> 3: insert the first n-k element of nums array into new array
        for(int i=0 ; i<n-k ; i++)
            rotated.push_back(nums[i]) ;

        // step -> 4: copy the elements of new array into nums array
        for(int i=0 ; i<n ; i++)
            nums[i] = rotated[i] ;
    }
};



// APPROACH 2 : Rotate k times
/*
    Rotate all the elements by 1 position k times.
*/
// Time Complexity : O(N*K)
// Space Complexity : O(1)
class Solution {
public:
	void rotateByOne(vector<int> &nums){
		int n = nums.size(), temp = nums[n-1];
		for(int i=n-1; i>0; i--){
			nums[i] = nums[i-1];
			nums[0] = temp;
		}
	}
    void rotate(vector<int>& nums, int k) {
        for(int i=0; i<k; i++) rotateByOne(nums);
    }
};



// APPROACH 3 : Reversal of array(Two Pointer Approch)
/*
    step -> 1: Reverse the whole array.
    step -> 2: Then reverse the first k elements.
    step -> 3: Finally reverse the remaining elements.
*/
// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ;

        if(k==0 || k%n == 0)
            return ;

        k = k%nums.size();
        // step -> 1: Reverse the whole array.
        reverse(nums.begin(), nums.end());

        // step -> 2: Then reverse the first k elements.
        reverse(nums.begin(), nums.begin()+k);

        // step -> 3: Finally reverse the remaining elements.
        reverse(nums.begin()+k, nums.end());
    }
};