// GFG -> https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1



// Approch -> 1: Brute Force Approch 
/*
Approch -> find all the subarray & check the sum of all subaray with K & update the maxlen
*/
// T.C. = O(N^2)
// S.C. = O(1)
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int maxLen = 0 ;
        
        for(int i=0 ; i<N ; i++){
            int sum = 0 ; // this sum will store teh sum of teh sub array elements

            // By this loop we are getting the sub array with starting indx is i and ending index is j
            for(int j=i ; j<N ; j++){
                sum += A[j] ;
                
                if(sum == K){
                    maxLen = max(maxLen, j-i+1) ;
                }
            }
        }
        
        return maxLen ;
    } 

};



// Approch -> 2: Using Hash Map + Prefix Sum 
// This is the optimised code for all positive & negative integers
/*
Approch -> Here we are using an unordered_map called preSumMap and this will store the sum of the previous sub arrays
           ex -> input = -13 0 6 15 16 2 15 -12 17 -16 0 -3 19 -3 2 -9 -6 , N=17 , K=15
           when i = 3 i.e. at 3rd index sum = -13+0+6+15 => 8
           rem = sum - K => 8 -15 => -7 and preSumMap have a pair(-7, 2) here 2 is the index no. i.e. from 0 to 2nd index sum of all elements is -7
           so at 3rd index there exist a sub array which last element is A[3] and sum = K so we update the length
*/
// T.C. = O(N)  but in the worst case when lots of collision occured then unordered map takes O(N) so in that case T.C. = O(N^2)
// S.C. =O(N)
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    {
        unordered_map<int, int> preSumMap ;
        int sum = 0 ;
        int maxLen = 0 ;
        
        for(int i=0 ; i<N ; i++){
            sum += A[i] ;
            
            if(sum == K){
                maxLen = max(maxLen, i+1) ;
            }
            
            int rem = sum - K ;
            if(preSumMap.find(rem) != preSumMap.end()){
                int len = i - preSumMap[rem] ;
                maxLen = max(maxLen, len) ;
            }
            
            // This is bcz we want longest sum sub arrays wo we don't want to affect our length when array contains input like 0
            if(preSumMap.find(sum) == preSumMap.end())
                preSumMap[sum] = i ;
        }
        
        return maxLen ;
    } 
};





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