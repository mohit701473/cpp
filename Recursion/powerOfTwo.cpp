// Leet Code   Que: 231. Power of Two

class Solution {
public:
    // T.C. = O(log(n))

    // Recursive Code
    bool isPowerOfTwo(int n) {
        if(n==1) 
            return true ;

        if(n <= 0)
            return false ;

        if(n%2 != 0) {
            return false ;
        }

        bool ans = isPowerOfTwo(n/2) ;
        return ans ;
    }

    // Using Loop 
    bool isPowerOfTwo(int n) {
            if(n==1) 
                return true ;

            if(n <= 0)
                return false ;

            while(n>1) {
                if(n%2 != 0) {
                    return false ;
                }
                n = n/2 ;
            }
            return true ;
        }

    // Without Recursion or Loop  code
     bool isPowerOfTwo(int n) {
        if(n==1) 
            return true ;

        if(n <= 0)
            return false ;

        int x = log2(n) ;

        if(n == pow(2,x)) 
            return true ;

        return false ;
    }

};