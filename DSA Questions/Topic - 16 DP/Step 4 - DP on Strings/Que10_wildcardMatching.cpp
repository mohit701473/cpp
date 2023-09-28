// LeetCode -> 44. Wildcard Matching
https://leetcode.com/problems/wildcard-matching/



// Approch -> 1: recursion
// T.C. = Exponential
// S.C. = O(N + M)
class Solution {

    bool solve(int i, int j, string &s, string &p){

        // Base cases
        if(i < 0 && j < 0) return true ;
        if(j < 0 && i >= 0 ) return false ;
        if(i < 0 ) {
            for(j ; j >=0 ; j--) {
                if(p[j] != '*') 
                    return false ;
            }
            return true ;
        }

        // explore all possibilities
        // matched
        if(s[i] == p[j] || p[j] == '?') return solve(i-1, j-1, s, p) ;

        else if(p[j] == '*') return ( solve(i-1, j, s, p) || solve(i, j-1, s, p)) ;

        return false ;
    }

public:
    bool isMatch(string s, string p) {

        int n = s.size() , m = p.size() ;

        return solve(n-1, m-1, s, p) ;
    }
};




// Approch -> 2: Memoization
// T.C. = O(M * N)
// S.C. = O(M * N) + O(N + M)
class Solution {

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){

        // Base cases
        if(i < 0 && j < 0) return true ;
        if(j < 0 && i >= 0 ) return false ;
        if(i < 0 ) {
            for(j ; j >=0 ; j--) {
                if(p[j] != '*') 
                    return false ;
            }
            return true ;
        }

        if(dp[i][j] != -1) return dp[i][j] ;

        // explore all possibilities
        // matched
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(i-1, j-1, s, p, dp) ;

        else if(p[j] == '*') return  dp[i][j] = (solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp)) ;

        return dp[i][j] = false ;
    }

public:
    bool isMatch(string s, string p) {

        int n = s.size() , m = p.size() ;

        vector<vector<int>> dp(n, vector<int>(m, -1)) ;

        return solve(n-1, m-1, s, p, dp) ;
    }
};




// Approch -> 2: Memoization with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(M * N) + O(N + M)
class Solution {

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){

        // Base cases
        if(i == 0 && j == 0) return true ;
        if(j == 0 && i > 0 ) return false ;
        if(i == 0 && j > 0) {
            for(j ; j > 0 ; j--) {
                if(p[j-1] != '*') 
                    return false ;
            }
            return true ;
        }

        if(dp[i][j] != -1) return dp[i][j] ;

        // explore all possibilities
        // matched
        if(s[i-1] == p[j-1] || p[j-1] == '?') return dp[i][j] = solve(i-1, j-1, s, p, dp) ;

        else if(p[j-1] == '*') return  dp[i][j] = (solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp)) ;

        return dp[i][j] = false ;
    }

public:
    bool isMatch(string s, string p) {

        int n = s.size() , m = p.size() ;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1)) ;

        return solve(n, m, s, p, dp) ;
    }
};




// Approch -> 3: Tabulation with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(M * N)
class Solution {

public:
    bool isMatch(string s, string p) {

        int n = s.size() , m = p.size() ;

        vector<vector<int>> dp(n+1, vector<int>(m+1, false)) ;

        // base cases
        dp[0][0] = true ;
        for(int i=1 ; i<=n ; i++) dp[i][0] = false ;
        for(int j=1 ; j<=m ; j++){
            if(p[j-1] != '*') break ;
            dp[0][j] = true ;
        }

        // loops
        for(int i=1 ; i<=n ; i++){

            for(int j=1 ; j<=m ; j++){
                
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1] ; // return dp[i][j] = solve(i-1, j-1, s, p, dp) ;
                }

                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] ; // return  dp[i][j] = (solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp)) ;
                }

                // else{
                //     dp[i][j] = false ; // return dp[i][j] = false ;
                // }
            }
        }



        return dp[n][m] ; // solve(n, m, s, p, dp) ;
    }
};




