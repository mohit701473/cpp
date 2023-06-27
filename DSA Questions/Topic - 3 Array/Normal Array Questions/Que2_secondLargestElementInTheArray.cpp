
https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
class Solution{
    
    int largest(int arr[], int n)
    {
        int maxi = INT_MIN ;
        
        for(int i=0 ; i<n ; i++)
            maxi = max(maxi, arr[i]) ;
            
        return maxi ;
    }
    
public:	
	
	int print2largest(int arr[], int n) {
	    
	    int firstLargest = largest(arr, n) ;
	    int secondLargest = -1 ;
	    
	    for(int i=0 ; i<n ; i++){
	        if(arr[i] != firstLargest && arr[i] > secondLargest)
	            secondLargest = arr[i] ;
	    }
	    
	    return secondLargest ;
	}
};