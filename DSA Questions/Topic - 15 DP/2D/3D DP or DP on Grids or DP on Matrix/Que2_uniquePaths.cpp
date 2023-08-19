// LeetCode -> 62. Unique Paths
https://leetcode.com/problems/unique-paths/description/




// Approch -> 1: Bottum Up recursion
// T.C. = O(2^(m*n))
// S.C. = O(path length) => O((m-1) + (n-1)) 
class Solution {

    int bottumUpRecursive(int x, int y, int m , int n){
        if(x==m-1 && y==n-1)
            return 1 ;

        if(x>=m || y>=n)
            return 0 ;

        int down = bottumUpRecursive(x+1 , y , m , n) ;
        int right = bottumUpRecursive(x , y+1 , m , n) ;

        return down + right ;
    }

public:
    int uniquePaths(int m, int n) {
        return bottumUpRecursive(0, 0, m, n) ;
    }
};



// Approch -> 2: Memoization + Recursion (Top Down Approch)
// T.C. = O(m * n)
// S.C. = O(path length) => O((m-1) + (n-1)) + O(m * n)
class Solution {

    int soleMem(int x, int y, vector<vector<int>> &dp){
        if(x == 0 && y == 0)
            return 1 ;

        if(x < 0 || y < 0)
            return 0 ;

        if(dp[x][y] != -1)
            return dp[x][y] ;

        int up = soleMem(x-1 , y, dp) ;
        int left = soleMem(x , y-1, dp) ;

        dp[x][y] = up + left ;
        return dp[x][y] ;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector(n,-1)) ;
        return soleMem(m-1, n-1, dp) ;
    }
};




// Approch -> 3: Tabulation
// T.C. = O(m * n)
// S.C. = O(m * n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector(n,-1)) ;

        // step -> 1: Base cases analyses
        dp[0][0] = 1 ;

        for(int i=0 ; i<m ; i++){

            for(int j=0 ; j<n ; j++){

                if(i==0 && j==0)
                    continue;

                int down = i-1 >= 0 ? dp[i-1][j] : 0 ;
                int right = j-1 >= 0 ? dp[i][j-1] : 0 ;

                dp[i][j] = down + right ;
            }
        }
        return dp[m-1][n-1] ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(m * n)
// S.C. = O(m + n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector(n,-1)) ;

        vector<int> upRow(n, 0) ; // dp[i-1][j] => (x-1)
        vector<int> leftCol(m, 0) ; // dp[i][j-1] => (y-1)
        upRow[0] = leftCol[0] = 1 ;

        for(int i=0 ; i<m ; i++){

            for(int j=0 ; j<n ; j++){

                if(i==0 && j==0)
                    continue;

                int down = upRow[j] ;  // i-1 >= 0 ? dp[i-1][j] : 0 ;
                int right = leftCol[i] ; // j-1 >= 0 ? dp[i][j-1] : 0 ;
                
                upRow[j] = down + right ;
                leftCol[i] = down + right ;
            }
        }
        return leftCol[m-1] ;
    }
};

