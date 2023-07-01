// GFG -> Largest subarray with 0 sum
https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1



// Approch -> 1: Brute Force Approch 
// T.C. = O(N^2) 
// S.C. = O(1)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {  
        
        int maxLen = 0 ;
        
        for(int i=0 ; i<n ; i++){
            int sum = 0 ;
            for(int j=i ; j<n ; j++){
                sum += A[j] ;
                
                if(sum == 0){
                    maxLen = max(maxLen, j-i+1) ;
                }
            }
        }
        
        return maxLen ;
    }
};



// Approch -> 2: Prefix Sum + Hash Map
// T.C. = O(N)
// S.C. = O(N)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int maxLen = 0 ;
        unordered_map<int, int> prefixSumMap ;
        int sum = 0 ;
        
        for(int i=0 ; i<n ; i++){
            sum += A[i] ;
            
            if(sum == 0){
                maxLen = max(maxLen, i+1) ;
            }
            
            int rem = sum - 0 ;
            if(prefixSumMap.find(rem) != prefixSumMap.end()){
                int len = i - prefixSumMap[rem] ;
                maxLen = max(maxLen, len) ;
            }
            
            if(prefixSumMap.find(rem) == prefixSumMap.end()){
                prefixSumMap[sum] = i ;
            }
        }
        
        return maxLen ;
    }
};