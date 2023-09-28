// LeetCode -> 516. Longest Palindromic Subsequence
https://leetcode.com/problems/longest-palindromic-subsequence/



// Approch -> 3: Tabulation -> shifted index method
// T.C. = O(N * M)
// S.C. = O(N * M)
class Solution {

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

public:
    int longestPalindromeSubseq(string s) {
        int n = s.size() ;
        // string str = reverse(s.begin(), s.end()) ; error bcz reverse() is a void function

        string str = string(s.rbegin(), s.rend());  // reveres s 

        return longestCommonSubsequence(s, str) ;
    }
};