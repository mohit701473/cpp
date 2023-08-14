// LeetCode -> 378. Kth Smallest Element in a Sorted Matrix
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/




// Approch -> 1: Similear to median of row wise sorted matrix question
// T.C. = O(log(max-min) * R * log(C))
// S.C. = O(1)
class Solution {
    int numberOfSmallerElement(vector<vector<int>> &matrix, int assumedKthElement){
        int count = 0 ;
        
        for(int i=0 ; i<matrix.size() ; i++){
            int start = 0 , end = matrix[i].size() - 1 ;
            
            // 2nd binary search to find the no. of element lesser then assumedKthElement in a i-th row
            while(start <= end){
                int mid = start + (end - start)/2 ;
                
                if(matrix[i][mid] <= assumedKthElement) start = mid + 1 ;
                else end = mid - 1;
            }
            
            count += start ;
        }
        
        return count ;
    }


public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int R = matrix.size() , C = matrix[0].size() ;
        int n = R * C ;
        int start = matrix[0][0] , end = matrix[R-1][C-1] ;
        int requiredSmallerElement = k-1 ;
        
        // 1st binary search to get assumedKthElement
        while(start <= end){
            
            int assumedKthElement = start + (end - start)/2 ;
            
            int countSmallerElement = numberOfSmallerElement(matrix, assumedKthElement) ;
            
            if(countSmallerElement <= requiredSmallerElement) {
                start = assumedKthElement + 1 ;
            }
            else end = assumedKthElement - 1 ;
        }
        
        return start ;
    }
};