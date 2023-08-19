// LeetCode -> 120. Triangle
https://leetcode.com/problems/triangle/description/




// Approch -> 1: Recursive Approch(bottom-up recursion)
// T.C. = O(2^N) where N = total no. of element in traingle
// S.C. = O(row)
class Solution {

    int solveRecursive(int row, int idx, vector<vector<int>>& triangle){
        // base cases
        if(row == triangle.size()-1 && idx < triangle[row].size()){
            return triangle[row][idx] ;
        }

        if(row >= triangle.size() || idx >= triangle[row].size()){
            return INT_MAX ;
        }

        // compute result for subprobelm
        int sameIdx = solveRecursive(row+1, idx, triangle) ;
        int nextIdx = solveRecursive(row+1, idx+1, triangle) ;

        int ans = triangle[row][idx] + min(sameIdx , nextIdx) ;

        return ans ;
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solveRecursive(0, 0, triangle) ;
    }
};






// Approch -> 2: Memoization + Recursion(Bottum-Up recursion)
// T.C. = O(N) => where N = total no. of element in traingle
// S.C. = (N) + O(row)
class Solution {

    int solveMem(int row, int idx, vector<vector<int>>& triangle, vector<vector<int> > &dp){
        // base cases
        if(row == triangle.size()-1 && idx < triangle[row].size()){
            return triangle[row][idx] ;
        }

        if(row >= triangle.size() || idx >= triangle[row].size()){
            return INT_MAX ;
        }

        if(dp[row][idx] != -1)
            return dp[row][idx] ;

        // compute result for subprobelm
        int sameIdx = solveMem(row+1, idx, triangle, dp) ;
        int nextIdx = solveMem(row+1, idx+1, triangle, dp) ;

        int ans = triangle[row][idx] + min(sameIdx , nextIdx) ;
        
        dp[row][idx] = ans ;
        return dp[row][idx] ;
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp ;

        for(int i=0 ; i<triangle.size() ; i++){
            vector<int> temp ;
            for(int j=0 ; j<triangle[i].size() ; j++){
                temp.push_back(-1) ;
            }
            dp.push_back(temp) ;
        }

        return solveMem(0, 0, triangle, dp) ;
    }
};



// Approch -> 3: Tabulation
// T.C. = O(N) 
// S.C. = O(N)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size() ;
        int n = triangle[m-1].size() ;

        vector<vector<int> > dp ;

        for(int i=0 ; i<triangle.size() ; i++){
            vector<int> temp ;
            for(int j=0 ; j<triangle[i].size() ; j++){
                temp.push_back(-1) ;
            }
            dp.push_back(temp) ;
        }


        dp[0][0] = triangle[0][0] ;

        for(int row = 1 ; row < triangle.size() ; row++){

            for(int idx = 0 ; idx < triangle[row].size() ; idx++){

                // compute result for subprobelm
                int prevIdx = idx-1 >=0 ? dp[row-1][idx-1] : INT_MAX ; 
                int sameIdx = idx < triangle[row-1].size() ?  dp[row-1][idx] : INT_MAX ;

                int ans = triangle[row][idx] + min(sameIdx , prevIdx) ;
        
                dp[row][idx] = ans ;
            }
        }

        int mini = INT_MAX ;
        for(auto it : dp[m-1]){
            mini = min(mini, it) ;
        }

        return mini ;
    }
};




// Approch -> 4: Space Optimization
// T.C. = O(N)
// S.C. = O(last row) 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<int> prevRow(1, triangle[0][0]) ;

        for(int row = 1 ; row < triangle.size() ; row++){

            int rowSize = triangle[row].size() ;

            vector<int> temp(rowSize, 0) ;

            for(int idx = 0 ; idx < triangle[row].size() ; idx++){

                // compute result for subprobelm
                int prevIdx = idx-1 >=0 ? prevRow[idx-1] : INT_MAX ; 
                int sameIdx = idx < triangle[row-1].size() ?  prevRow[idx] : INT_MAX ;

                int ans = triangle[row][idx] + min(sameIdx , prevIdx) ;
        
                temp[idx] = ans ;
            }

            prevRow = temp ;
        }

        int mini = INT_MAX ;
        for(auto it : prevRow){
            mini = min(mini, it) ;
        }

        return mini ;
    }
};