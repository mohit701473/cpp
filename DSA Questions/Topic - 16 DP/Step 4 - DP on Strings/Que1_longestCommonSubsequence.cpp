// LeetCode -> 1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/



// Approch -> 1: recursion
// T.C. = Exponential
// S.C. = O(N + M)
class Solution {

    int solveRecursive(int idx1, int idx2, string &text1, string &text2){
        // Base cases
        if(idx1 < 0 || idx2 < 0){
            return 0 ;
        }

        // Explore all posibilities
        // 1st possibility if character matched
        if(text1[idx1] == text2[idx2]){
            return 1 + solveRecursive(idx1-1, idx2-1, text1, text2) ;
        }

        // 2nd possibility not matched
        return max(solveRecursive(idx1-1, idx2, text1, text2), solveRecursive(idx1, idx2-1, text1, text2)) ;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size() ;

        return solveRecursive(n1-1, n2-1, text1, text2) ;
    }
};




// Approch -> 2: Memoization + Recursion
// T.C. = O(M * N)
// S.C. =  O(N + M) + O(M * N)
class Solution {

    int solveMem(int idx1, int idx2, string &text1, string &text2,vector<vector<int>> &dp){
        // Base cases
        if(idx1 < 0 || idx2 < 0){
            return 0 ;
        }

        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2] ;
        }

        // Explore all posibilities
        // 1st possibility if character matched
        if(text1[idx1] == text2[idx2]){
            dp[idx1][idx2] = 1 + solveMem(idx1-1, idx2-1, text1, text2, dp) ;

            return dp[idx1][idx2] ;
        }

        // 2nd possibility not matched
        dp[idx1][idx2] = max(solveMem(idx1-1, idx2, text1, text2, dp), solveMem(idx1, idx2-1, text1, text2, dp)) ;

        return dp[idx1][idx2] ;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size() ;

        vector<vector<int>> dp(n1, vector<int>(n2, -1)) ;

        return solveMem(n1-1, n2-1, text1, text2, dp) ;
    }
};



// Approch -> 3: Tabulation -> without shifted index method
// T.C. = O(N * M)
// S.C. = O(N * M)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size() ;

        vector<vector<int>> dp(n1 , vector<int>(n2 , 0)) ;

        // nestde loops
        for(int i=0 ; i < n1 ; i++){

            for(int j=0 ; j < n2 ; j++){
                // Copy recurance from memoization method
                
                // Explore all posibilities
                // 1st possibility if character matched
                if(text1[i] == text2[j])
                    dp[i][j] = 1 + (i-1 < 0 || j -1 < 0 ? 0 : dp[i-1][j-1]) ;   // solveMem(idx1-1, idx2-1, text1, text2, dp) ;

                // 2nd possibility not matched
                else {
                    int l1 = (i - 1 < 0 ? 0 : dp[i-1][j]) ;
                    int l2 = (j - 1 < 0 ? 0 : dp[i][j-1]) ;
                    dp[i][j] = max(l1, l2) ;
                }
            }
        }

        return dp[n1-1][n2-1] ;   // solveMem(n1, n2, text1, text2, dp) ;
    }
};





// Shifted index memoization aproch
class Solution {

    int solveMem(int idx1, int idx2, string &text1, string &text2,vector<vector<int>> &dp){
        // Base cases
        if(idx1 == 0 || idx2 == 0){
            return 0 ;
        }

        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2] ;
        }

        // Explore all posibilities
        // 1st possibility if character matched
        if(text1[idx1 - 1] == text2[idx2 - 1]){
            dp[idx1][idx2] = 1 + solveMem(idx1-1, idx2-1, text1, text2, dp) ;

            return dp[idx1][idx2] ;
        }

        // 2nd possibility not matched
        dp[idx1][idx2] = max(solveMem(idx1-1, idx2, text1, text2, dp), solveMem(idx1, idx2-1, text1, text2, dp)) ;

        return dp[idx1][idx2] ;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size() ;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1)) ;

        return solveMem(n1, n2, text1, text2, dp) ;
    }
};





// Approch -> 3: Tabulation -> shifted index method
// T.C. = O(N * M)
// S.C. = O(N * M)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size() ;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1)) ;

        // Base cases 
        for(int j=0 ; j <= n2 ; j++) dp[0][j] = 0 ;
        for(int i=0 ; i <= n1 ; i++) dp[i][0] = 0 ;

        // nestde loops
        for(int i=1 ; i <= n1 ; i++){

            for(int j=1 ; j <= n2 ; j++){
                // Copy recurance from memoization method
                
                // Explore all posibilities
                // 1st possibility if character matched
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i-1][j-1] ;   // solveMem(idx1-1, idx2-1, text1, text2, dp) ;

                // 2nd possibility not matched
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
            }
        }

        return dp[n1][n2] ;   // solveMem(n1, n2, text1, text2, dp) ;
    }
};




// Approch -> 4: Space Optimization to Two rows
// T.C. = O(N * M)
// S.C. = O(2 * M)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size() ;

        vector<int> prev(n2 + 1, 0) , curr(n2 + 1, 0) ;

        // Base cases 
        for(int j=0 ; j <= n2 ; j++) prev[j] = 0 ;

        // nestde loops
        for(int i=1 ; i <= n1 ; i++){

            for(int j=1 ; j <= n2 ; j++){
                // Copy recurance from memoization method
                
                // Explore all posibilities
                // 1st possibility if character matched
                if(text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j-1] ;   // solveMem(idx1-1, idx2-1, text1, text2, dp) ;

                // 2nd possibility not matched
                else curr[j] = max(prev[j] , curr[j-1]) ;
            }

            prev = curr ;
        }

        return prev[n2] ;   // solveMem(n1, n2, text1, text2, dp) ;
    }
};




