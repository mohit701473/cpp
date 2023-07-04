// GFG -> Number of occurrence
https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1



// Approch -> 1: Binary Search
// T.C. = O(2log(N))
// S.C. = O(1)
class Solution{
    
    int getStartIdx(int nums[], int n, int k){
        int idx = -1 ;
        int s = 0 , e = n-1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            
            if(nums[mid] == k){
                idx = mid ;
                e = mid -1 ;
            }else if(nums[mid] > k) e = mid - 1;
            else s = mid + 1;
        }
        
        return idx ;
    }


    int getEndIdx(int nums[], int n, int k){
        int idx = -1 ;
        int s = 0 , e = n-1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            
            if(nums[mid] == k){
                idx = mid ;
                s = mid + 1 ;
            }else if(nums[mid] > k) e = mid - 1;
            else s = mid + 1;
        }
        
        return idx ;
    }

    
public:	
	
	int count(int arr[], int n, int x) {
	    int startIdx = getStartIdx(arr, n, x) ;
        int endIdx = getEndIdx(arr, n, x) ;
        
        if(startIdx == -1) return 0 ;
        
        int freq = endIdx - startIdx + 1;
        
        return freq ;
	}
};