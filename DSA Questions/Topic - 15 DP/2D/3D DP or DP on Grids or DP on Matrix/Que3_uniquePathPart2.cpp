// LeetCode -> 63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/




// Approch -> 1: Top Down recursion
// T.C. = O(2^(m*n))
// S.C. = O(path length) => O((m-1) + (n-1)) 
class Solution {

    int solveRecursive(int x, int y, vector<vector<int>> &obstacleGrid){
        if(x == 0 && y == 0)
            return 1 ;

        if(x < 0 || y < 0)
            return 0 ;

        int up = 0 , left = 0 ;

        // move up
        if(x > 0 && obstacleGrid[x-1][y] != 1)
            up = solveRecursive(x-1, y, obstacleGrid) ;

        // move left
        if(y > 0 && obstacleGrid[x][y-1] != 1)
            left = solveRecursive(x, y-1, obstacleGrid) ;

        return up + left ;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;

        if(obstacleGrid[m-1][n-1] == 1)
            return 0 ;

        return solveRecursive(m-1, n-1, obstacleGrid) ;
    }
};




// Approch -> 2: Memoization + Recursion (Top Down Approch)
// T.C. = O(m * n)
// S.C. = O(path length) => O((m-1) + (n-1)) + O(m * n)
class Solution {

    int solveMem(int x, int y, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        // Base cases
        if(x == 0 && y == 0)
            return 1 ;

        if(x < 0 || y < 0)
            return 0 ;

        // step -> 3: return the resulr of subproblem
        if(dp[x][y] != -1)
            return dp[x][y] ;

        int up = 0 , left = 0 ;

        // move up
        if(x > 0 && obstacleGrid[x-1][y] != 1)
            up = solveMem(x-1, y, obstacleGrid, dp) ;

        // move left
        if(y > 0 && obstacleGrid[x][y-1] != 1)
            left = solveMem(x, y-1, obstacleGrid, dp) ;

        // step -> 2: store the result of subproblem
        dp[x][y] = up + left ;
        return dp[x][y] ;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;

        if(obstacleGrid[m-1][n-1] == 1)
            return 0 ;
        
        // step -> 1: Declear a dp 2d array
        vector<vector<int> > dp(m, vector(n,-1)) ;
        return solveMem(m-1, n-1, obstacleGrid, dp) ;
    }
};




// Approch -> 3: Tabulation
// T.C. = O(m * n)
// S.C. = O(m * n)
class Solution {

    int solveTab(int m, int n, vector<vector<int>> &obstacleGrid){

        // step -> 1: Declear a dp 2d array
        vector<vector<int> > dp(m, vector(n,-1)) ;

        // step -> 2: base cases analyze
        dp[0][0] = 1 ;


        for(int i=0 ; i<m ; i++){

            for(int j=0 ; j<n ; j++){

                if(i==0 && j==0)
                    continue;

                int down = (i-1 >= 0) && (obstacleGrid[i][j] != 1) ? dp[i-1][j] : 0 ;
                int right = (j-1 >= 0) && (obstacleGrid[i][j] != 1) ? dp[i][j-1] : 0 ;

                dp[i][j] = down + right ;
            }
        }
        
        return dp[m-1][n-1] ;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;

        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
            return 0 ;
        
        return solveTab(m, n, obstacleGrid) ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(m * n)
// S.C. = O(n)
class Solution {

    int spaceOptimization(int m, int n, vector<vector<int>> &obstacleGrid){

        vector<int> dp(n,0) ;

        for(int i=0 ; i<m ; i++){
            vector<int> temp(n,0) ; // by this we get the previous col value i.e dp[i][j-1]
            for(int j=0 ; j<n ; j++){

                if(i==0 && j==0){
                    temp[j] = 1 ;
                    continue;
                }

                int down = (obstacleGrid[i][j] != 1) ? dp[j] : 0 ;
                int right = (j-1 >= 0) && (obstacleGrid[i][j] != 1) ? temp[j-1] : 0 ;

                temp[j] = down + right ;
            }

            dp = temp ;
        }

        return dp[n-1] ;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;

        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
            return 0 ;
        
        return spaceOptimization(m, n, obstacleGrid) ;
    }
};