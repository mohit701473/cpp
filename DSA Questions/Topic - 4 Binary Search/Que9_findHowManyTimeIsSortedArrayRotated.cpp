// GFG -> Rotation
https://practice.geeksforgeeks.org/problems/rotation4723/1


// Approch -> 1: Binary Search
// T.C. = O(log(N)) 
// S.C. = O(1)
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int ans = INT_MAX ;
	    int minIdx = 0 ;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            // It is guarantee that one of the part either left or right will be sorted
            //if left part is sorted:
            if (nums[low] <= nums[mid]) {
                if(ans > nums[low]){
                    ans = nums[low] ;
                    minIdx = low ;
                }
                low = mid+1 ;
            }

            else { //if right part is sorted:
                if(ans > nums[mid]){
                    ans = nums[mid] ;
                    minIdx = mid ;
                }
                high = mid-1 ;
            }
        }
        return minIdx ;
	}

};