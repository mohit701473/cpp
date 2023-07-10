// LeetCode -> 1539. Kth Missing Positive Number
https://leetcode.com/problems/kth-missing-positive-number/description/


// Approch -> 1: Brute Force Approch
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int misssing = k ;
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] > misssing) return misssing ;
            misssing++ ;
        }
        return misssing ;
    }
};



// Approch -> 2: Binary Search
// T.C. = O(log(N))
// S.C. = O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0,  high = arr.size() -1 ;
        while(low<=high){
            int mid = (low+high)/2 ;
            int missing = arr[mid] - (mid+1) ;
            if(missing < k) low = mid+1 ;
            else high = mid-1 ;
        }
        // at the end of the while loop low point to the index till which missing no. is greater then k and 
        // high point to the index till which missing is less then k that maen high < k < low 
        // so our formula = arr[high] + more 
        // more = k - missing && missing = arr[high] - (high+1) => more = k - arr[high]  + high +1
        // forumula = arr[high] + k - arr[high] + high + 1 => high + k + 1
        // high = low-1 at the end of while loop
        // formula = low+k

        return high+1+k ; // return low+k ;
    }
};