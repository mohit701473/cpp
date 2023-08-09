// LeetCode -> 48. Rotate Image
https://leetcode.com/problems/rotate-image/


// Approch -> Brute Force Approch
// T.C. = O(3N^2)
// S.C. = O(N^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size() ;
        vector<vector<int> > mat(row, vector<int>(col,0)) ;

        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                mat[j][i] = matrix[row-i-1][j] ;
            }
        }
        

        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                matrix[i][j] = mat[i][j] ;
            }
        }
    }
};



// Approch -> Diagonaly Swap + Reverse The Matrix
/*
first swap the matrix via diagonaly i.e. swap(matrix[i][j], matrix[j][i])
and then reverse the every row of the matrix i.e. reverse(matrix[i].begin(), matrix[i].end())
*/
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Diagonaly Swap
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse The Matrix
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};