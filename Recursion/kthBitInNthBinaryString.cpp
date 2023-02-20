// Leet Code   Que: 1545. Find Kth Bit in Nth Binary String

// T(n) = T(n-1) + O(n) 
// T.C. = O(n^2) 
class Solution {
public:

     vector<char> invert(vector<char> str, int n) {

        int i = 0 ;
        int size = str.size() ;

        while(i<size) {
            if(str[i] == '0') 
                str[i] = '1' ;

            else 
                str[i] = '0' ;

            i++ ;
        }

        return str ;
    }

    vector<char> reverse(vector<char> str) {
        int i = 0 ;
        int j = str.size() - 1 ;

        while(i <= j){
           char temp = str[i] ;
           str[i] = str[j] ;
           str[j] = temp ;
           i++ ;
           j-- ; 
        }
        
        return str ;
    }

     vector<char> makeString(vector<char> &str, int n) {

        if(n == 1) {
            str.push_back('0') ;
            return str ;
        }

        vector<char> new_str1 = makeString(str, n-1) ;

        str.push_back('1') ;

        vector<char> new_str2 = reverse((invert(new_str1, n-1)));
        for(auto it: new_str2) {
            str.push_back(it) ;
        }

        return str ;
    }

    char findKthBit(int n, int k) {

        vector<char> str ;
        str = makeString(str , n) ;
        return str[k-1];
    }
};

