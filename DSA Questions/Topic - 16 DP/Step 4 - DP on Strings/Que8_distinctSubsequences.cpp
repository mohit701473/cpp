// LeetCode -> 115. Distinct Subsequences
https://leetcode.com/problems/distinct-subsequences/





// Approch -> 1: recursion
// T.C. = Exponential
// S.C. = O(N + M)
class Solution {

    int solve(int i, int j, string &s, string &t){

        if(j < 0) return 1 ; // string t exhausted 
        if(i < 0) return 0 ; // string s exhausted 

        // Explore all possibilities

        // possibility - 1: Match
        if(s[i] == t[j]){
            return solve(i-1, j-1, s, t) + solve(i-1, j, s, t) ;
        }
        // possibility - 2: Not Match
        else return solve(i-1, j, s, t) ;
        
    }

public:
    int numDistinct(string s, string t) {

        int n = s.size() , m = t.size() ;

        return solve(n-1, m-1, s, t) ;
    }
};



// Approch -> 2: Memoization
// T.C. = O(M * N)
// S.C. = O(M * N) + O(N + M)
class Solution {

    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){

        // base cases
        if(j < 0) return 1 ; // string t exhausted 
        if(i < 0) return 0 ; // string s exhausted 

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        // Explore all possibilities
        // possibility - 1: Match
        if(s[i] == t[j]){
            dp[i][j] =  solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp) ;
            return dp[i][j] ;
        }
        // possibility - 2: Not Match
        else {
            dp[i][j] = solve(i-1, j, s, t, dp) ;
            return dp[i][j] ;
        }

        
    }

public:
    int numDistinct(string s, string t) {

        int n = s.size() , m = t.size() ;

        vector<vector<int>> dp(n, vector<int>(m, -1)) ;

        return solve(n-1, m-1, s, t, dp) ;
    }
};





// Approch -> 2: Memoization with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(M * N) + O(N + M)
class Solution {

    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){

        // base cases
        if(j == 0) return 1 ; // string t exhausted 
        if(i == 0) return 0 ; // string s exhausted 

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        // Explore all possibilities
        // possibility - 1: Match
        if(s[i-1] == t[j-1]){
            dp[i][j] =  solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp) ;
            return dp[i][j] ;
        }
        
        // possibility - 2: Not Match
        dp[i][j] = solve(i-1, j, s, t, dp) ;
        return dp[i][j] ;
        
    }

public:
    int numDistinct(string s, string t) {

        int n = s.size() , m = t.size() ;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1)) ;

        return solve(n, m, s, t, dp) ;
    }
};



// Approch -> 3: Tabulation with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(M * N)
class Solution {

public:
    int numDistinct(string s, string t) {

        int n = s.size() , m = t.size() ;

        vector<vector<double>> dp(n+1, vector<double>(m+1, 0)) ;

        // write down base cases
        for(int i=0 ; i<=n ; i++) dp[i][0] = 1 ; // string t exhausted 
        for(int j=1 ; j<=m ; j++) dp[0][j] = 0 ; // string s exhausted 

        // loops
        for(int i=1 ; i<=n ; i++){

            for(int j=1 ; j<=m ; j++){

                // copy paste recurance
                // Explore all possibilities

                // possibility - 1: Match
                if(s[i-1] == t[j-1])
                    dp[i][j] =  dp[i-1][j-1] + dp[i-1][j] ;

                // possibility - 2: Not Match
                else  dp[i][j] = dp[i-1][j] ;
            }
        }

        return (int)dp[n][m] ;
    }
};



// Approch -> 4: Space Optimization with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(2 * M)
class Solution {

public:
    int numDistinct(string s, string t) {

        int n = s.size() , m = t.size() ;

        vector<double> prev(m+1, 0) , curr(m+1, 0) ;

        // write down base cases
        prev[0] = curr[0] = 1 ;

        // loops
        for(int i=1 ; i<=n ; i++){

            for(int j=1 ; j<=m ; j++){

                // copy paste recurance
                // Explore all possibilities

                // possibility - 1: Match
                if(s[i-1] == t[j-1])
                    curr[j] =  prev[j-1] + prev[j] ;

                // possibility - 2: Not Match
                else  curr[j] = prev[j] ;
            }

            prev = curr ;
        }

        return (int)prev[m] ;
    }
};




// Approch -> 4: 1-D Array Space Optimization with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(M)
class Solution {

public:
    int numDistinct(string s, string t) {

        int n = s.size() , m = t.size() ;

        vector<double> prev(m+1, 0) ;

        // write down base cases
        prev[0] = 1 ;

        // loops
        for(int i=1 ; i<=n ; i++){

            for(int j=m ; j>=1 ; j--){

                // copy paste recurance
                // Explore all possibilities

                // possibility - 1: Match
                if(s[i-1] == t[j-1])
                    prev[j] =  prev[j-1] + prev[j] ;

                // possibility - 2: Not Match
                else  prev[j] = prev[j] ;
            }
        }

        return (int)prev[m] ;
    }
};

