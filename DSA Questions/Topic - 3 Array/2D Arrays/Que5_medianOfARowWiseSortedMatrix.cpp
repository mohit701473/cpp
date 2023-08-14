// GFG -> Median in a row-wise sorted Matrix
https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1


// Approch -> 1: Binary Search
// Expected Time Complexity: O(32 * R * log(C))
// Expected Auxiliary Space: O(1)
class Solution{  
    
    int numberOfSmallerElementThenAssumedMedian(vector<vector<int>> &matrix, int assumedMedian){
        int count = 0 ;
        
        for(int i=0 ; i<matrix.size() ; i++){
            int start = 0 , end = matrix[i].size() - 1 ;
            
            // 2nd binary search to find the no. of element lesser then assumedMedain in a i-th row
            while(start <= end){
                int mid = start + (end - start)/2 ;
                
                if(matrix[i][mid] <= assumedMedian) start = mid + 1 ;
                else end = mid - 1;
            }
            
            count += start ;
        }
        
        return count ;
    }
    
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int n = R * C ;
        int start = 1 , end = 2000 ;
        
        // 1st binary search to get assumed medain
        // This loop will run at max 32 times
        while(start <= end){
            
            int assumedMedian = start + (end - start)/2 ;
            
            int countLesserElement = numberOfSmallerElementThenAssumedMedian(matrix, assumedMedian) ;
            
            if(countLesserElement <= n/2) {
                start = assumedMedian + 1 ;
            }
            else end = assumedMedian - 1 ;
        }
        
        return start ;
    }
};