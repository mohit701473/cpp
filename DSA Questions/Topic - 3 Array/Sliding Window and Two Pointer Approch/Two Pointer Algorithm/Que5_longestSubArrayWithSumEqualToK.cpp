// GFG -> https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


// This approch only work for positive inegers
// Approch -> 3: Two Pointer Approch 
// T.C. = O(N)
// S.C. = O(N)
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    {
        int i=0, j=0, sum=0, maxLen=0 ;
        
        while(j<N){
            sum += A[j] ;
            
            if(sum == K){
                maxLen = max(maxLen, j-i+1) ;
            }
            
            while(sum > K && i<N){
                sum -= A[i] ;
                i++ ;
            }
            
            j++ ;
        }
        
        return maxLen ;
    } 

};