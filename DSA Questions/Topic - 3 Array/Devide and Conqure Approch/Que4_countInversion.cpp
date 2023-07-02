// GFG -> Count Inversion
https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1



// Approch -> 2: Using Devide and Conquer + Merge Sort
// T.C. = O(2Nlog(N))
// S.C. = O(N)
class Solution{
    void merge(long long arr[], long long low, long long mid, long long high) {
        vector<long long> temp; // temporary array
        long long left = low;      // starting index of left half of arr
        long long right = mid + 1;   // starting index of right half of arr
    
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


    void countInversions(long long arr[], long long low, long long mid, long long high, long long &count){
        long long left = low;     
        long long right = mid + 1;
        
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]){
                left++;
            }
            else {
                count += (mid - left + 1); //Modification 2
                right++;
            }
        }
    }
    
    
    
    void mergeSort(long long arr[], long long low, long long high, long long &count) {
        if (low >= high) return;
        long long mid = (low + high) / 2 ;
        mergeSort(arr, low, mid, count);  // left half
        mergeSort(arr, mid + 1, high, count); // right half
        countInversions(arr, low, mid, high, count) ; // count reverse Pairs
        merge(arr, low, mid, high);  // merging sorted halves
    }
        
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long count = 0 ;
        mergeSort(arr, 0, N-1, count) ;
        return count ;
    }

};