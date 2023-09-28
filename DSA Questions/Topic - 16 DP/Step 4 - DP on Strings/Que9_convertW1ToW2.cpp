// LeetCode -> 72. Edit Distance
https://leetcode.com/problems/edit-distance/




// Approch -> 1: recursion
// T.C. = Exponential
// S.C. = O(N + M)
class Solution {

    int solve(int i, int j, string &word1, string &word2){

        // base cases
        if(i < 0) return j+1 ; // string word1 exhausted return j+1 i.e. from empty string word1 convert to word2[0...j] no. of minimum operation required
        if(j < 0 ) return i+1 ; // string word2 exhausted return i+1 i.e. convert word1[0...i] to word2 which is an empty string no. of minimum operation required

        // Explore all possibilities

        // Matched
        if(word1[i] == word2[j]){
            int matched = solve(i-1, j-1, word1, word2) ;
            return matched ;
        }

        else{
            // replace 
            int replace = 1 + solve(i-1, j-1, word1, word2) ;

            // remove
            int remove = 1 + solve(i-1, j, word1, word2) ;

            // insert
            int insert = 1 + solve(i, j-1, word1, word2) ;

            return  min(replace, min(remove, insert)) ;
        }
        
    }

public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size() , m = word2.size() ;

        return solve(n-1, m-1, word1, word2) ;
    }
};




// Approch -> 2: Memoization
// T.C. = O(M * N)
// S.C. = O(M * N) + O(N + M)
class Solution {

    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){

        // base cases
        if(i < 0) return j+1 ;
        if(j < 0 ) return i+1 ;

        if(dp[i][j] != -1) return dp[i][j] ;

        // Explore all possibilities

        // Matched
        if(word1[i] == word2[j]){
            int matched = solve(i-1, j-1, word1, word2, dp) ;
            return dp[i][j] =  matched ;
        }

        else{
            // replace 
            int replace = 1 + solve(i-1, j-1, word1, word2, dp) ;

            // remove
            int remove = 1 + solve(i-1, j, word1, word2, dp) ;

            // insert
            int insert = 1 + solve(i, j-1, word1, word2, dp) ;

            return dp[i][j] =  min(replace, min(remove, insert)) ;
        }
        
    }

public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size() , m = word2.size() ;

        vector<vector<int> > dp(n, vector<int>(m, -1)) ;

        return solve(n-1, m-1, word1, word2, dp) ;
    }
};




// Approch -> 2: Memoization with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(M * N) + O(N + M)
class Solution {

    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){

        // base cases
        if(i == 0) return j ;
        if(j == 0 ) return i ;

        if(dp[i][j] != -1) return dp[i][j] ;

        // Explore all possibilities

        // Matched
        if(word1[i-1] == word2[j-1]){
            int matched = solve(i-1, j-1, word1, word2, dp) ;
            return dp[i][j] =  matched ;
        }

        else{
            // replace 
            int replace = 1 + solve(i-1, j-1, word1, word2, dp) ;

            // remove
            int remove = 1 + solve(i-1, j, word1, word2, dp) ;

            // insert
            int insert = 1 + solve(i, j-1, word1, word2, dp) ;

            return dp[i][j] =  min(replace, min(remove, insert)) ;
        }
        
    }

public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size() , m = word2.size() ;

        vector<vector<int> > dp(n+1, vector<int>(m+1, -1)) ;

        return solve(n, m, word1, word2, dp) ;
    }
};





// Approch -> 3: Tabulation with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(M * N)
class Solution {
    
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size() , m = word2.size() ;

        vector<vector<int> > dp(n+1, vector<int>(m+1, -1)) ;

        // base cases
        for(int j=0 ; j<=m ; j++) dp[0][j] = j ;
        for(int i=0 ; i<=n ; i++) dp[i][0] = i ;

        // loops
        for(int i=1 ; i<=n ; i++){

            for(int j=1 ; j<=m ; j++){
                
                // copy paste recurrance

                // Explore all possibilities

                // 1-st -> Matched
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] ;
                }
                
                // 2nd -> not matched
                else{
                    // replace 
                    int replace = 1 + dp[i-1][j-1] ;

                    // remove
                    int remove = 1 + dp[i-1][j] ;

                    // insert
                    int insert = 1 + dp[i][j-1] ;

                    dp[i][j] =  min(replace, min(remove, insert)) ;
                }

            }
        }


        return dp[n][m] ;
    }
};





// Approch -> 4: Space Optimization with 1 based indexing
// T.C. = O(M * N)
// S.C. = O(2 * M)
class Solution {

public:
    int minDistance(string S1, string S2) {


        int n = S1.size();
        int m = S2.size();
        
        vector<int> prev(m+1,0);
        vector<int> cur(m+1,0);
        
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        
        for(int i=1;i<n+1;i++){
            cur[0]=i;
            for(int j=1;j<m+1;j++){
                if(S1[i-1]==S2[j-1])
                    cur[j] = 0+prev[j-1];
                
                else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
            }
            prev = cur;
        }
        
        return prev[m];



        
        // int n = S1.size() , m = S2.size() ;

        // vector<int> prev(m+1, 0) , curr(m+1, 0);
        // // base cases
        // for(int j=0 ; j<=m ; j++) prev[j] = j ;

        // // loops
        // for(int i=1 ; i<=n ; i++){
        //     curr[0] = i ;
        //     for(int j=1 ; j<=m ; j++){
                
        //         // copy paste recurrance

        //         // Explore all possibilities

        //         // 1-st -> Matched
        //         if(S1[i-1] == S2[j-1]){
        //             curr[j] = prev[j-1] ;
        //         }
                
        //         // 2nd -> not matched
        //         else{
        //             // replace 
        //             // int replace = 1 + prev[j-1] ;

        //             // // remove
        //             // int remove = 1 + prev[j] ;

        //             // // insert
        //             // int insert = 1 + curr[j-1] ;

        //             curr[j] = 1 + min(prev[j], min(prev[j-1], curr[j-1])) ;
        //         }

        //         prev = curr ;
        //     }
        // }


        // return prev[m] ;
    }
};