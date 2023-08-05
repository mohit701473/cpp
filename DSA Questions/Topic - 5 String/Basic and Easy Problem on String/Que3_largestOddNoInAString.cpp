

// Approch -> 1: String
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1 ;
        while(i >= 0){
            int ch = num[i] - '0' ;
            if(ch & 1) break ;
            i-- ;
        }
        //if(i<0) return "" ;
        return num.substr(0, i+1) ;
    }
};