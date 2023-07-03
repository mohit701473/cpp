// GFG -> Merge Without Extra Space
https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1


// Approch -> 1:
// Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
// Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.

// Space Complexity: O(1) as we are not using any extra space.
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            //Declare 2 pointers:
            int left = n - 1;
            int right = 0;
        
            //Swap the elements until arr1[left] is
            // smaller than arr2[right]:
            while (left >= 0 && right < m) {
                if (arr1[left] > arr2[right]) {
                    swap(arr1[left], arr2[right]);
                    left--, right++;
                }
                else {
                    break;
                }
            }
        
            // Sort arr1[] and arr2[] individually:
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        } 
};




// Approch -> 2: gap Method
// Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
// Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of 
// the outer loop will be O(log(n+m)). Now, for each value of the gap, the inner loop can at most run for (n+m) times. 
// So, the time complexity of the inner loop will be O(n+m). So, the overall time complexity will be O((n+m)*log(n+m)).

// Space Complexity: O(1) as we are not using any extra space.
class Solution{
    
    void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
        if (arr1[ind1] > arr2[ind2]) {
            swap(arr1[ind1], arr2[ind2]);
        }
    }

    
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // len of the imaginary single array:
            int len = n + m;
        
            // Initial gap:
            int gap = (len / 2) + (len % 2);
        
            while (gap > 0) {
                // Place 2 pointers:
                int left = 0;
                int right = left + gap;
                while (right < len) {
                    // case 1: left in arr1[] and right in arr2[]:
                    if (left < n && right >= n) {
                        swapIfGreater(arr1, arr2, left, right - n);
                    }
                    // case 2: both pointers in arr2[]:
                    else if (left >= n) {
                        swapIfGreater(arr2, arr2, left - n, right - n);
                    }
                    // case 3: both pointers in arr1[]:
                    else {
                        swapIfGreater(arr1, arr1, left, right);
                    }
                    left++, right++;
                }
                // break if iteration gap=1 is completed:
                if (gap == 1) break;
        
                // Otherwise, calculate new gap:
                gap = (gap / 2) + (gap % 2);
            }

        } 
};