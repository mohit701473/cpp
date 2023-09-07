// LeetCode -> 64. Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/description/



/*
Que1 -> Why are we not useing greedy approch ?
ans. -> bcz in greedy approch we always consider next optimal subproblem by which missed some subproblems which are not
        optimal subproblem at that movement but they gives overall optimal answer
*/


// Approch -> 1: Top Down recursive approch
// T.C. = O(2^(m*n))
// S.C. = O(path length) => O((m-1) + (n-1)) 
class Solution {

    int solveRecursive(int x, int y, vector<vector<int>> &grid){
        // base cases
        if(x == 0 && y == 0){
            return grid[x][y] ;
        }

        if(x < 0 || y < 0){
            return INT_MAX ;
        }

        // compute the result for subproble
        int up = solveRecursive(x-1, y, grid) ; // up will store result of subproblem(x-1, y)
        int left = solveRecursive(x, y-1, grid) ; // left will store result of subproblem(x, y-1)

        // this ans will store the result of subproblem(x, y) that mens if suppose x = 1 & y = 1
        // to (0,0) se (1,1) tk pahunchne ka jo minimum path sum h vo ans m store hoga
        int ans = grid[x][y] + min(up, left) ;

        return ans ;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;

        return solveRecursive(m-1, n-1, grid) ;
    }
};





// Approch -> 2: Memoization + Recursion (Top Down Approch)
// T.C. = O(m * n)
// S.C. = O(path length) => O((m-1) + (n-1)) + O(m * n)
class Solution {

    int solveMem(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp){
        // base cases
        if(x == 0 && y == 0){
            return grid[x][y] ;
        }

        if(x < 0 || y < 0){
            return INT_MAX ;
        }

        // step -> 3: if result of subproblem is previously computed the return it
        if(dp[x][y] != -1){
            return dp[x][y] ;
        }

        // compute the result for subproble
        int up = solveMem(x-1, y, grid, dp) ; // up will store result of subproblem(x-1, y)
        int left = solveMem(x, y-1, grid, dp) ; // left will store result of subproblem(x, y-1)

        // this ans will store the result of subproblem(x, y) that mens if suppose x = 1 & y = 1
        // to (0,0) se (1,1) tk pahunchne ka jo minimum path sum h vo ans m store hoga
        int ans = grid[x][y] + min(up, left) ;

        // step -> 2: store result of subproblem
        dp[x][y] = ans ;
        return dp[x][y] ;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;

        // step -> 1: Create a dp data structure
        vector<vector<int> > dp(m, vector<int>(n,-1)) ;
        return solveMem(m-1, n-1, grid, dp) ;
    }
};





// Approch -> 3: Tabulation
// T.C. = O(m * n)
// S.C. = O(m * n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;

        // step -> 1: Create a dp data structure
        vector<vector<int> > dp(m, vector<int>(n,-1)) ;

        // step -> 2: Base cases analysis 
        dp[0][0] = grid[0][0] ;

        // step -> 3: apply loops
        for(int i=0 ; i<m ; i++){

            for(int j=0 ; j<n ; j++){

                if(i==0 && j==0) continue ;

                // compute the result for subproble(i, j)
                int up = i-1 >= 0 ? dp[i-1][j] : INT_MAX ; // up will store result of subproblem(i-1, j)
                int left = j-1 >= 0 ? dp[i][j-1] : INT_MAX ; // left will store result of subproblem(i, j-1)

                // this ans will store the result of subproblem(i, j) that mens if suppose i = 1 & j = 1
                // to (0,0) se (1,1) tk pahunchne ka jo minimum path sum h vo ans m store hoga
                int ans = grid[i][j] + min(up, left) ;

                dp[i][j] = ans ;
            }
        }
        return dp[m-1][n-1] ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(m * n)
// S.C. = O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;

        // this will store the previos row's results i.e. if we are at i-th row then dp will store teh results 
        // of(i-1)-th row i.e (i-1, j)-th grid's result
        vector<int> dp(n, 0) ;

        for(int i=0 ; i<m ; i++){
            
            // this tempory vector will store the result of previous columns i.e if we are at j-th colummn the 
            // temp[j-1] will gives us the previos (j-1)-th column's result i.e (i, j-1)-th grid's result
            vector<int> temp(n, 0) ;

            for(int j=0 ; j<n ; j++){
                
                if(i == 0 && j == 0){
                    temp[0] = grid[0][0] ;
                    continue ;
                }

                // compute the result for subproble(i, j)

                int up = i-1 >= 0 ? dp[j] : INT_MAX ; // up will store result of subproblem(i-1, j)
                int left = j-1 >= 0 ? temp[j-1] : INT_MAX ; // left will store result of subproblem(i, j-1)

                // this ans will store the result of subproblem(i, j) that mens if suppose i = 1 & j = 1
                // to (0,0) se (1,1) tk pahunchne ka jo minimum path sum h vo ans m store hoga
                int ans = grid[i][j] + min(up, left) ;

                temp[j] = ans ;
            }

            dp = temp ;
        }

        return dp[n-1] ;
    }
};