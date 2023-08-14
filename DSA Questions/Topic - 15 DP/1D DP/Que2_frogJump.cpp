// Code Studio -> Frog Jump
https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0



// Approch 1: Recursive Approch(bottum-Up Recursive Tree)
/*
Recursive Approch -> In this solution recursive tree is Bottum to Up 
*/
// T.C. = O(2^n)
// S.C. = O(N)
void solve(int i, int &n, int &energyLost, int &ans, vector<int> &heights){
    if( i == n){
        ans = min(ans, energyLost) ;
        return ;
    }
    if(i>n) return ;

    energyLost += abs(heights[i] - heights[i-1]) ;
    solve(i+1, n, energyLost, ans, heights) ;

    energyLost -= abs(heights[i] - heights[i-1]) ;

    energyLost += abs(heights[i+1] - heights[i-1]) ;
    solve(i+2, n, energyLost, ans, heights) ;

    energyLost -= abs(heights[i+1] - heights[i-1]) ;
}

int frogJump(int n, vector<int> &heights)
{
    int ans = INT_MAX, energyLost = 0 , i = 1 ;
    solve(i, n, energyLost, ans, heights) ;
    return ans ;
}



// Approch 1: Recursive Approch(Top-Down Recursive Tree)
/*
Recursive Approch -> In this solution recursive tree is Top to Down
*/
// T.C. = O(2^n)
// S.C. = O(N)
int solve(int idx , vector<int> &heights){
    
    if(idx == 0) return 0 ;
    
    int left, right ;
    
    left = solve(idx-1, heights) + abs(heights[idx] - heights[idx-1]) ;
    
    if(idx > 1)
        right = solve(idx-2, heights) + abs(heights[idx] - heights[idx-2]) ;
    else right = INT_MAX ;

    return min(left, right) ;
}

int frogJump(int n, vector<int> &heights)
{
    return solve(n-1, heights) ;
}





// Approch -> 2: Recusion + Memoization
// T.C. = O(N)
// S.C. = O(N) + O(N) {Dp array + recursive call satck}
int solve(int idx , vector<int> &heights, vector<int> &dp){
    
    if(idx == 0) return 0 ;

    if(dp[idx] != -1) return dp[idx] ;
    
    int left, right ;
    
    left = solve(idx-1, heights, dp) + abs(heights[idx] - heights[idx-1]) ;
    
    if(idx > 1)
        right = solve(idx-2, heights, dp) + abs(heights[idx] - heights[idx-2]) ;
    else right = INT_MAX ;

    dp[idx] = min(left, right) ;

    return dp[idx] ;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1) ;
    return solve(n-1, heights, dp) ;
}




// Approch -> 3: Tabulation Method
// T.C. = O(N)
// S.C. = O(N)
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1) ;
    dp[0] = 0 ;
    dp[1] = dp[0] + abs(heights[1] - heights[0]) ;

    for(int idx=2 ; idx<n ; idx++){
        int left = dp[idx-1] + abs(heights[idx] - heights[idx-1]) ;
        int right = dp[idx-2] + abs(heights[idx] - heights[idx-2]) ;

        dp[idx] = min(left, right) ; 
    }

    return dp[n-1] ;
}




// Approch -> 4: Space Optimization
// T.C. = O(N)
// S.C. = O(1) 
int frogJump(int n, vector<int> &heights)
{
    int prev2 = 0 ;
    int prev1 = abs(heights[1] - heights[0]) ;

    for(int idx=2 ; idx<n ; idx++){
        int left = prev1 + abs(heights[idx] - heights[idx-1]) ;
        int right = prev2 + abs(heights[idx] - heights[idx-2]) ;

        prev2 = prev1 ;
        prev1 = min(left, right) ; 
    }

    return prev1 ;
}

