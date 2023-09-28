// GFG -> Minimum sum partition
https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1




// Approch -> 1: space optimization
// T.C. = O(N * totalSum) + O(totalSum)
// S.C. = O(totalSum)
class Solution{
    
    vector<bool> isSubsetSum(int arr[], int sum, int n){
        
        vector<bool> prev(sum+1, false) , curr(sum+1, false) ;
        
        prev[0] = curr[0] = true ;

        if(arr[0] <= sum) prev[arr[0]] = true ;
        
        
        for(int idx = 1 ; idx<n ; idx++){
            
            for(int target = 1 ; target<=sum ; target++){
                
                
                bool notTake = prev[target] ;
        
                bool take = false ;
                if(arr[idx] <= target)
                    take = prev[target-arr[idx]] ;
                
                curr[target] = take | notTake ;
                
            }

            prev = curr ;
        }
        
        return prev ;
    }

  public:
  
	int minDifference(int arr[], int n)  { 
	    
	    int totalSum = 0 ;
	    
	    for(int i=0 ; i<n ; i++) totalSum += arr[i] ;
	    
	    vector<bool> subsetSum = isSubsetSum(arr, totalSum, n) ;
	    
	    int mini = INT_MAX ;
	    
	    for(int i=0 ; i<subsetSum.size() ; i++){
	        if(subsetSum[i]){
	            int s1 = i ;
	            int s2 = totalSum - i ;
	            
	            mini = min(mini, abs(s2-s1)) ;
	        }
	    }
	    
	    return mini ;
	} 
};