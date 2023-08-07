// LeetCode -> 8. String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/description/


// Approch -> :1 
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    int myAtoi(string s) {
        int i = 0 , n = s.size() , sign = 1 ;
        // leading whitespace
        while(i<n && s[i] == ' ') i++ ;

        // sign
        if(s[i] == '-'){
            sign = -1 ;
            i++ ;
        }else if(s[i] == '+') i++ ;

        // leading 0
        while(i<n && s[i] == 0) i++ ;

        int result = 0 ;
        //cout << s[i] - '0' ;
        while(i<n && (s[i] - '0' >= 0 && s[i] - '0' <= 9)){
            int digit = s[i] - '0' ;
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) return sign == 1 ? INT_MAX : INT_MIN ;
            result = result * 10 + digit ;
            i++ ;
        }

        return result * sign ;
    }
};