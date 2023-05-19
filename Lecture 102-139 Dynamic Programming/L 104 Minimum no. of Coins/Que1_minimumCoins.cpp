

//Minimum Elements  code studio




// Approch - 1 using recursion
// T.C. = 
// S.C. = 
int solveRec(vector<int> &num, int x){

    if(x == 0)
        return 0 ;

    if(x < 0)
        return INT_MAX ;

    int mini = INT_MAX ;

    for(int i=0 ; i<num.size() ; i++){
        int ans = solveRec(num, x-num[i]) ;

        if(ans != INT_MAX)
            mini = min(mini, 1+ans) ;
    }

    return mini ;
}

int minimumElements(vector<int> &num, int x)
{
    int ans = solveRec(num, x) ;

    if(ans == INT_MAX) return -1 ;

    return ans ;
}




// Approch - 1 using recursion + memoziation(top-down)
// T.C. = O(N*x)  N => no. of coins x => target
// S.C. = O(x)
int solveMem(vector<int> &num, int x, vector<int> &dp){

    if(x == 0)
        return 0 ;

    if(x < 0)
        return INT_MAX ;

    if(dp[x] != -1)
        return dp[x] ;

    int mini = INT_MAX ;

    for(int i=0 ; i<num.size() ; i++){
        int ans = solveMem(num, x-num[i], dp) ;

        if(ans != INT_MAX)
            mini = min(mini, 1+ans) ;
    }

    dp[x] = mini ;

    return mini ;
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1, -1) ;
    int ans = solveMem(num, x, dp) ;

    if(ans == INT_MAX) return -1 ;

    return ans ;
}



// Approch - 3 using Tabulation
// T.C. = O(N*x)
// S.C. = O(x)
int minimumElements(vector<int> &num, int x)
{

    vector<int> dp(x+1, INT_MAX) ;
    dp[0] = 0 ;

    for(int i=1 ; i<=x ; i++){
        for(int j=0 ; j<num.size() ; j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-num[j]]) ;
        }
    }

    if(dp[x] == INT_MAX) return -1 ;

    return dp[x] ;
}