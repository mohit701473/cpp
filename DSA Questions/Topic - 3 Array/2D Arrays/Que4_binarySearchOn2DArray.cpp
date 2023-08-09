https://leetcode.com/problems/search-a-2d-matrix/description/

// T.C. = O(log(m * n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() , col = matrix[0].size() ;
        int s = 0 , e = row * col - 1 ;

        while(s <= e){
            int mid = (s+e) / 2 ;
            int ele = matrix[mid/col][mid % col] ;
            
            if(ele == target) return true ;

            else if(target < ele) e = mid-1 ;

            else s = mid + 1 ;
        }

        return false ;
    }
};