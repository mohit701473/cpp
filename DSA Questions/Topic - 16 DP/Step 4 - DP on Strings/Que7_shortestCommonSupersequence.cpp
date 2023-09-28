// LeetCode -> 1092. Shortest Common Supersequence
https://leetcode.com/problems/shortest-common-supersequence/



class Solution {

  void getLCS(string &str1, string &str2, vector<vector<int>> &dp){

    int m = str1.size() , n = str2.size() ;
    for(int i=0 ; i<=m ; i++) dp[i][0] = 0 ;
    for(int j=0 ; j<=n ; j++) dp[0][j] = 0 ;

    int i=1 ; 

    while(i <= str1.size()){
      int j = 1 ;
      while(j <= str2.size()){

        if(str1[i-1] == str2[j-1]){
          dp[i][j] = 1 + dp[i-1][j-1] ;
        }

        else{
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
        }

        j++ ;
      }

      i++ ;
    }
  }

  string getSCS(string str1, string str2, vector<vector<int>> &dp){
    
    int i = str1.size() , j = str2.size() ;
    string res = "" ;

    while(i > 0 && j > 0){

      if(str1[i-1] == str2[j-1]){
        res = str1[i-1] + res ;
        i-- , j-- ;
      }

      else{

        if(dp[i-1][j] > dp[i][j-1]){
          res = str1[i-1] + res ;
          i = i-1 ;
        }
        else{
          res = str2[j-1] + res ;
          j = j-1 ;
        }
      }

    }

    if(i == 0){
      while(j > 0){
        res = str2[j-1] + res ;
        j-- ;
      }
    }

    if(j == 0){
      while(i > 0){
        res = str1[i-1] + res ;
        i-- ;
      }
    }

    return res ; 
  }

public:
    string shortestCommonSupersequence(string str1, string str2) {

      int m = str1.size() , n = str2.size() ;

      vector<vector<int>> dp(m+1, vector<int>(n+1)) ;

      getLCS(str1, str2, dp) ;

       for(int i=0 ; i<=m ; i++){
        for(int j=0 ; j<=n ; j++){
          cout << dp[i][j] << " " ;
        }
        cout << endl ;
      }

      return getSCS(str1, str2, dp) ;
    }
};