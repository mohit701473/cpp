// LeetCode -> 931. Minimum Falling Path Sum
https://leetcode.com/problems/minimum-falling-path-sum/


// Approch -> 1: Recursive Approch(Bottom-Up Recursive Approch)
// T.C. = O( n * 3^(m*n) )
// S.C. = O(m)
class Solution {

    int solveRecursive(int row, int col, vector<vector<int>> &matrix){
        int m = matrix.size() , n = matrix[m-1].size() ;
        // Base cases
        if( ( row == m-1 ) && ( col >=0 && col < n ) ){
            return matrix[row][col] ;
        }

        if(row >= m || col < 0 || col >= n){
            return INT_MAX ;
        }


        // Compute result for subproblems
        int prevCol = solveRecursive(row+1, col-1, matrix) ; 
        int sameCol = solveRecursive(row+1, col, matrix) ;
        int nextCol = solveRecursive(row+1 , col+1, matrix) ;

        int ans = matrix[row][col] + min(prevCol , min(sameCol , nextCol)) ;

        return ans ;
    }


public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ;
        int ans = INT_MAX ;

        for(int i=0 ; i<n ; i++){
            int mini = solveRecursive(0, i, matrix) ;

            ans = min(ans, mini) ;
        }

        return ans ;
    }
};







// Approch -> 2: Memoization + Recursion(Bottom-Up recursion)
// T.C. = O(n^3)
// S.C. = O(n^2) + O(n)
class Solution {

    int solveMem(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){

        int m = matrix.size() , n = matrix[m-1].size() ;
        // Base cases
        if( ( row == m-1 ) && ( col >=0 && col < n ) ){
            return matrix[row][col] ;
        }

        if(row >= m || col < 0 || col >= n){
            return INT_MAX ;
        }
        
        // step -> 3: return subproblem result
        if(dp[row][col] != -1){
            return dp[row][col] ;
        }

        // Compute result for subproblems
        int prevCol = solveMem(row+1, col-1, matrix, dp) ; 
        int sameCol = solveMem(row+1, col, matrix, dp) ;
        int nextCol = solveMem(row+1 , col+1, matrix, dp) ;

        int ans = matrix[row][col] + min(prevCol , min(sameCol , nextCol)) ;
        // step -> 2: Store subproblem result
        dp[row][col] = ans ;
        return dp[row][col] ;
    }


public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size() ;
        int ans = INT_MAX ;
        
        // step -> 1: Create a DP data structure
        vector<vector<int> > dp(m, vector<int>(n,-1)) ;

        for(int i=0 ; i<n ; i++){
            int mini = solveMem(0, i, matrix, dp) ;

            ans = min(ans, mini) ;
        }

        return ans ;
    }
};




// Approch -> 3: Tabulation Method
// T.C. = O(N) + O(N^2) + O(N)
// S.C. = o(N^2)
class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;

        // step -> 1: Declear a DP data structure
        vector<vector<int>> dp(n, vector<int>(n,-1)) ;

        // Step -> 2: Base cases analysis 
        for(int col=0 ; col<n ; col++){
            dp[0][col] = matrix[0][col] ;
        }

        // step -> 3: apply loop to get ans
        for(int row=1 ; row<n ; row++){

            for(int col=0 ; col<n ; col++){
                // Compute result for subproblems
                int prevCol = col-1 >= 0 ? dp[row-1][col-1] : INT_MAX ; // solveMem(row+1, col-1, matrix, dp) ;

                int sameCol = dp[row-1][col] ; // solveMem(row+1, col, matrix, dp) ;

                int nextCol = col+1 < n ? dp[row-1][col+1] : INT_MAX ; // solveMem(row+1 , col+1, matrix, dp) ;


                int ans = matrix[row][col] + min(prevCol , min(sameCol , nextCol)) ;
                // Store subproblem result in DP Matrix
                dp[row][col] = ans ;
            }
        }

        // Now find the minimum falling path
        int res = INT_MAX ;
        for(int i=0 ; i<n ; i++){
            res = min(res, dp[n-1][i]) ;
        }

        return res ;
    }
};





// Approch -> 3: Space Optimization
// T.C. = O(N) + O(N^2) + O(N)
// S.C. = o(N)
class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;

        // step -> 1: Declear a DP data structure
        vector<int> dp(n, -1) ; // this will store results of previous row

        // Step -> 2: Base cases analysis 
        for(int col=0 ; col<n ; col++){
            dp[col] = matrix[0][col] ;
        }

        // step -> 3: apply loop to get ans
        for(int row=1 ; row<n ; row++){

            vector<int> temp(n, -1) ;

            for(int col=0 ; col<n ; col++){

                // Compute result for subproblems
                int prevCol = col-1 >= 0 ? dp[col-1] : INT_MAX ; // solveMem(row+1, col-1, matrix, dp) 
                int sameCol = dp[col] ; // solveMem(row+1, col, matrix, dp) ;
                int nextCol = col+1 < n ? dp[col+1] : INT_MAX ; // solveMem(row+1 , col+1, matrix, dp) 

                int ans = matrix[row][col] + min(prevCol , min(sameCol , nextCol)) ;

                // Store subproblem result in tempory vector
                temp[col] = ans ;
            }

            // copy the temp vector into dp array so this dp array is furthure use as a previous row
            dp = temp ;
        }
        

        // Now find the minimum falling path
        int res = INT_MAX ;
        for(int i=0 ; i<n ; i++){
            
            res = min(res, dp[i]) ;
        }

        return res ;
    }
};