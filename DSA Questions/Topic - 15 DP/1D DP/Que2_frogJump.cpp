// Code Studio -> Frog Jump
https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


/*
Que. -> 1: Why we can't apply greedy approch here ?
ans. -> we can't use greedy approch heare bcz jb hum next optimal solution ki tarf badte hai greedy approch se to 
        is beech hum bhut se ese solution ko miss kr denge jo hume global optimal solution dete ho.

        Ex. -> heights = {30, 10, 60, 10, 60, 50} 0-base index
        By the greedy approch 1st jump to 1st idx bcz abs(10-30) < abs(60-30) so energy require => 20
        2nd jump from 1st idx to 3rd idx bcz abs(10-10) = 0 
        3rd jump from 3rd idx to 5th idx bcz abs(50-10) = 40 
        total energy require = 20 + 0 + 40 => 60

        but the ans is => 40 
        1st jump from 0th idx to 2nd idx, energy required => 60-30 => 30 
        2nd jump from 2nd idx to 4th idx, energy required => 60-60 => 0
        3nd jump from 4nd idx to 5th idx, energy required => abs(50-60) => 10
        total energy require = 30 + 0 + 10 => 40
*/  




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

