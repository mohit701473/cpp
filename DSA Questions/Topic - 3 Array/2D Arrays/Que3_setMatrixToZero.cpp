// LeetCode -> 73. Set Matrix Zeroes
https://leetcode.com/problems/set-matrix-zeroes/


// Approch -> 1: Brute Force Approch
// T.C. = O(nm(n+m) + nm)
// S.C. = O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == 0){
                    markRow(matrix, i) ; // mark the non zero to -1
                    markCol(matrix, j) ; // mark the non zero to -1
                }
            }
        }

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0 ;
                }
            }
    }
}
};



// Approch -> 2: check which row and col should be mark zero i.e. store that row & col then mark zero these 
// row and col
// T.C. = O(mn)
// S.C. = O(n + m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ;
        vector<int> rowToBeSetZero(m,0) ;
        vector<int> colToBeSetZero(n,0) ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == 0){
                    rowToBeSetZero[i] = 1 ;
                    colToBeSetZero[j] = 1 ;
                }
            }
        }

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(rowToBeSetZero[i] || colToBeSetZero[j]){
                    matrix[i][j] = 0 ;
                }
            }
        }
    }
};




// Approch -> 3: check which row and col should be mark zero i.e. store that row & col then mark zero these 
// row and col
// T.C. = O(mn)
// S.C. = O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ;
        // vector<int> rowToBeSetZero(m,0) -> matrix[0][..] 
        // vector<int> colToBeSetZero(n,0) -> matrix[..][0]
        int col0 = 1 ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == 0){
                    // mark the i-th row
                    matrix[i][0] = 0 ;
                    
                    // mark the j-th col
                    if(j != 0) matrix[0][j] = 0 ;
                    else col0 = 0 ;
                }
            }
        }

        for(int i=1 ; i<m ; i++){
            for(int j=1 ; j<n ; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0 ;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int i=0 ; i<n ; i++) matrix[0][i] = 0 ;
        }

        if(col0 == 0){
            for(int i=0 ; i<m ; i++) matrix[i][0] = 0 ;
        }
    }
};