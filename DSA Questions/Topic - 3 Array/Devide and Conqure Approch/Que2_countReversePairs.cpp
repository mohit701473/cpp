// LeetCode -> 493. Reverse Pairs
https://leetcode.com/problems/reverse-pairs/




// Approch -> 1: Brute Force Approch
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int n = nums.size() ;
        int countReversePair = 0 ;

        for(int i=0 ; i<n ; i++){
            ll num = nums[i] ;
            num *= 2 ;
            for(int j=0 ; j<i ; j++){
                if(nums[j] > num)
                    countReversePair++ ;
            }
        }

        return countReversePair ;
    }
};




// Approch -> 2: Using Devide and Conquer + Merge Sort
// T.C. = O(2Nlog(N))
// S.C. = O(N)
class Solution {
private:

    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }


    void countReversePairs(vector<int> &arr, int low, int mid, int high, int &count){
        int right = mid + 1;

        for(int left = low ; left<=mid ; left++){
            while(right <= high){
                long long num = arr[right] ; // this is for avoid the integer over flow
                num *= 2 ;
                if(arr[left] > num) right++ ;
                else break ;
            }

            count += (right - (mid+1)) ; 
        }
    }


    void mergeSort(vector<int> &arr, int low, int high, int &count) {
        if (low >= high) return;
        int mid = (low + high) / 2 ;
        mergeSort(arr, low, mid, count);  // left half
        mergeSort(arr, mid + 1, high, count); // right half
        countReversePairs(arr, low, mid, high, count) ; // count reverse Pairs
        merge(arr, low, mid, high);  // merging sorted halves
    }


public:
    int reversePairs(vector<int>& nums) {
        int count = 0 ;
        mergeSort(nums, 0, nums.size()-1, count) ;
        return count ;
    }
};



