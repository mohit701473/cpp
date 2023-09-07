// Coding Ninja -. Minimum Number of Deletions and Insertions
https://www.codingninjas.com/studio/problems/minimum-number-of-deletions-and-insertions_4244510



// Approch -> 3: Tabulation -> shifted index method
// T.C. = O(N * M)
// S.C. = O(N * M)
int longestCommonSubsequence(string &text1, string &text2) {
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

int canYouMake(string &s1, string &s2){
    int lcs_len = longestCommonSubsequence(s1, s2) ; 

    int remove = s1.size() - lcs_len ;
    int insert = s2.size() - lcs_len ;

    return remove + insert ;
}




// LeetCode -> 583. Delete Operation for Two Strings
https://leetcode.com/problems/delete-operation-for-two-strings/description/


// Approch -> 3: Tabulation -> shifted index method
// T.C. = O(N * M)
// S.C. = O(N * M)
class Solution {

    int longestCommonSubsequence(string &text1, string &text2) {
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
    int minDistance(string word1, string word2) {
        int lcs_len = longestCommonSubsequence(word1, word2) ; 

        int remove_w1 = word1.size() - lcs_len ;
        int remove_w2 = word2.size() - lcs_len ;

        return remove_w1 + remove_w2 ;
    }
};