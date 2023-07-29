https://leetcode.com/problems/divide-two-integers/


// T.C. = O(dividend)
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1 ;

        long long int x = abs(dividend) ;
        long long int y = abs(divisor) ;

        int quotient = 0 ;

        while(x >= y){
            x -= y ; 
            ++quotient ;
            if(quotient == INT_MAX ) return sign < 0 ? INT_MIN : INT_MAX ;
        } 

        return quotient * sign ;
    }
};



// T.C. = O(31)
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1 ;

        long long int x = abs(dividend) ;
        long long int y = abs(divisor) ;

        int quotient = 0 ;
        long long int temp = 0 ;

        for(int i=31 ; i>=0 ; i--){
            if(temp + (y << i) <= x){
                temp += y << i ;
                quotient += 1LL << i ;
                if(i == 31 ) return sign < 0 ? INT_MIN : INT_MAX ;
            }
        }

        return quotient * sign ;
    }
};