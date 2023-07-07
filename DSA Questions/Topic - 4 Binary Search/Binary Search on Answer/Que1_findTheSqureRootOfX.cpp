// GFG -> Square root of a number
https://practice.geeksforgeeks.org/problems/square-root/0



// Approch -> 1: Brute Force Approch 
// T.C. = O(N)
// S.C. = O(1)
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int ans ;
        int i = 1;
        while(i<=x){
            if(i*i <= x) ans = i ;
            else break ;
            i++ ;
        }
        
        return ans ;
    }
};





// Approch -> 1: Binary Search
// T.C. = O(log(N))
// S.C. = O(1)
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int low = 1, high = x, ans ;
        
        while(low <= high){
            long long int mid = (low+high)/2 ;
            
            if(mid * mid <= x){
                ans = mid ;
                low = mid + 1 ;
            }else high = mid - 1 ;
        }
        
        return ans ;
    }
};