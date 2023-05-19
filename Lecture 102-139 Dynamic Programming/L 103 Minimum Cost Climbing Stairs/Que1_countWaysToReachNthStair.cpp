

// Approch - 1 recursive Approch
// T.C. = O(2^n)
// S.C. = O(2^n) recursive stack
class Solution
{
    public:
    int countWays(int n)
    {
        your code here
        if(n < 0)
            return 0;
            
        if(n == 0)
            return 1 ;
            
        return countWays(n-1) + countWays(n-2) ;  

    }
};