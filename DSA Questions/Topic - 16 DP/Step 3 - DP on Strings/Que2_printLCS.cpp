// Coding Ninja -> Print Longest Common Subsequence
https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383


// Approch -> 3: Tabulation -> shifted index method
// T.C. = O(N * M) + O(N + M) in worst case
// S.C. = O(N * M)
void getMatrix(string text1, string text2, vector<vector<int>> &dp){

        int n1 = text1.size(), n2 = text2.size() ;

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
    }


string findLCS(int n, int m,string &text1, string &text2){

		int n1 = text1.size(), n2 = text2.size() ;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0)) ;
        
        getMatrix(text1, text2, dp) ;
        
        string lcs = "" ;

        int i = n1 , j = n2 ;

        while(i > 0 && j > 0){

			// matched so go diagonaly
            if(text1[i-1] == text2[j-1]){
                lcs = text1[i-1] + lcs ;
                i = i-1 , j = j-1 ;
            }

			// not matched so go for max
            else{
                if(dp[i][j] == dp[i-1][j]) i = i-1 ;
                else j = j-1 ;
            }
        }
       

        return lcs ;	
}