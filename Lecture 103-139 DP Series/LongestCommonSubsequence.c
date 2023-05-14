// Longest Common Subsequence 
// Method 1 -> recursive

#include<stdio.h>
#include<string.h>

int max(int a, int b){
    if(a > b)
        return a ;

    return b ;
}

int LCS(char *str1, char *str2, int i, int j){
        // base case 
    if(i == strlen(str1) || j == strlen(str2))
        return 0 ;

    int ans = 0 ;
    if(str1[i] == str2[j]){
        ans = 1 + LCS(str1, str2, i+1, j+1) ;
    }

    else{
        ans = max( LCS(str1, str2, i+1, j), LCS(str1, str2, i, j+1)) ;
    }

    return ans ;
}


int main()
{
    char str1[100], str2[100];

    printf("Enter a string: ");
    scanf("%s", str1);

    printf("Enter a string: ");
    scanf("%s", str2);

    int ans = LCS(str1, str2, 0, 0) ;
    printf("%d", ans) ;

    return 0;
}


// Method 2 -> DP
#include<stdio.h>
#include<string.h>

int len1, len2 ;

int max(int a, int b){
    if(a > b)
        return a ;

    return b ;
}

int LCS(char *str1, char *str2, int i, int j, int dp[][len2]){
        // base case 
    if(i == strlen(str1) || j == strlen(str2))
        return 0 ;

    if(dp[i][j] != -1)
        return dp[i][j] ;

    int ans = 0 ;
    if(str1[i] == str2[j]){
        ans = 1 + LCS(str1, str2, i+1, j+1, dp) ;
    }

    else{
        ans = max( LCS(str1, str2, i+1, j, dp), LCS(str1, str2, i, j+1, dp)) ;
    }
    //dp[i][j] = ans ;
    return  dp[i][j] = ans;
}


int main()
{
    char str1[100], str2[100];

    printf("Enter a string: ");
    scanf("%s", str1);
    len1 = strlen(str1) ;

    printf("Enter a string: ");
    scanf("%s", str2);
    len2 = strlen(str2) ;

    int dp[len1][len2] ;
    for(int i=0 ; i<len1 ; i++){
        for(int j=0 ; j<len2 ; j++){
            dp[i][j] = -1 ;
        }
    }

    int ans = LCS(str1, str2, 0, 0, dp) ;
    printf("%d", ans) ;

    return 0;
}