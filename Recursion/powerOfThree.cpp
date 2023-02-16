// LeetCode Que 326. Power of Three


// Que : Given an integer n, return true if it is a power of three. Otherwise, return false.
//       An integer n is a power of three, if there exists an integer x such that n == 3x.

class Solution {
public: 

    // Recursive Code
    bool isPowerOfThree(int n) {

        if(n==1) 
            {return true ;}

            bool ans = false ;

        if(n%3 != 0 || n<=0) 
            {return false ;}

        else{
            if(n > 1) 
                {
                    ans = isPowerOfThree(n/3) ;
                }

            else 
                {
                    ans = isPowerOfThree(3*n) ;
                }

                return ans ;
        }
    }

    // Itrative Code
    bool powerOfThree(int n) {

        if(n==1)
            return true ;

       if(n%3 != 0 || n<=0) {
           return false ;
       }

        if(n>1) {

            while(n != 1) {

                if(n%3 !=0) {
                    return false ;
                }

                n = n/3 ;
            }
        }

        else{
            while(n != 1) {

                if(n%3 !=0) {
                    return false ;
                }

                n = n*3 ;
            }
        }
       
       return true ;
    }
};