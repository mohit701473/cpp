// Leet Code   Que: 1922. Count Good Numbers

// T.C. = O(log(n))
class Solution {
public:
    int myPow(long long x, long long n) { 
        if(n == 0) 
            return 1;

        long long int m = 1000000007 ;
        int ans = myPow(x, n/2)%m;
        
        if(n%2 == 0)
            return ((ans%m) * (ans%m))%m  ;

        else 
            return ((x%m) *(ans%m) * (ans%m))%m ;
    }


    int countGoodNumbers(long long n) {
        long long evenIndex = n/2 ;
        long long oddIndex  = n/2 ;
        long long m = 1000000007;
    
        if(n%2 != 0) {
            evenIndex = n/2 + 1 ;
            oddIndex  = n/2 ;
        }

        int ans1 = myPow(5,evenIndex) % m ;
        int ans2 = myPow(4,oddIndex) % m ;

        int ans = ((ans1 % m )*(ans2 % m)) % m ;

        return ans ;
    }
};

