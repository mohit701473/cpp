// Coding Ninja -> Longest Common Substring
https://www.codingninjas.com/studio/problems/longest-common-substring_1235207



// Approch -> 1: tabulation
// T.C. = O(N * M)
// S.C. = O(N * M)
int lcs(string &str1, string &str2) {

    int n = str1.size(), m = str2.size();

    int maxi = 0 ;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;

    for(int j=0 ; j<=m ; j++) dp[0][j] = 0 ;
    for(int i=0 ; i<=n ; i++) dp[i][0] = 0 ;

    for(int i=1 ; i<=n ; i++){

        for(int j=1 ; j<=m ; j++){

            // matched
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1] ;
                maxi = max(maxi, dp[i][j]) ;
            }

            // not matched
            else dp[i][j] = 0 ;
        }
    }

    return maxi ;
}





// Approch -> 1: Space Optimization to Two Rows
// T.C. = O(N * M)
// S.C. = O(2 * M)
int lcs(string &str1, string &str2) {

    int n = str1.size(), m = str2.size();

    int maxi = 0 ;

    vector<int> prev(m+1, 0), curr(m+1, 0) ;

    for(int i=1 ; i<=n ; i++){

        for(int j=1 ; j<=m ; j++){

            // matched
            if(str1[i-1] == str2[j-1]){
                curr[j] = 1 + prev[j-1] ;
                maxi = max(maxi, curr[j]) ;
            }

            // not matched
            else curr[j] = 0 ;
        }

        prev = curr ;
    }
    return maxi ;
}

