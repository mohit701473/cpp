https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

// T.C. = O(log(max(start,goal))) or O(31)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int countFilp = 0 ;
        while(start != 0 || goal != 0){
            if((start & 1) != (goal & 1)) countFilp++ ;
            start = start != 0 ? start >> 1 : 0 ;
            goal = goal != 0 ? goal >> 1 : 0 ;
        }

        return countFilp ;
    }
};