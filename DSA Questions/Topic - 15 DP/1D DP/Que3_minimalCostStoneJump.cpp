// Code Studio -> Minimal Cost
https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0



// Approch 1: Recursive Approch(bottum-Up Recursive Tree)
/*
Recursive Approch -> In this solution recursive tree is Bottum to Up 
*/
// T.C. = Exponential
// S.C. = O(N)
void solve(int stone, int n, int k, vector<int> &height, int &ans, int &cost){

    if(stone == n){
        ans = min(ans, cost) ;
        return ;
    }
    if(stone > n) return ;

    for(int i=1 ; i<=k ; i++){
        cost += abs(height[stone+i] - height[stone]) ;
        solve(stone+i, n, k, height, ans, cost) ;
        cost -= abs(height[stone+i] - height[stone]) ;
    }
}

int minimizeCost(int n, int k, vector<int> &height){
    int ans = INT_MAX , cost = 0 ;

    solve(0, n-1, k, height, ans, cost) ;

    return ans ;
}



// Approch 1: Recursive Approch(Top-Down Recursive Tree)
/*
Recursive Approch -> In this solution recursive tree is Top to Down
*/
// T.C. = Exponential
// S.C. = O(N)
int solve(int n, int k, vector<int> &height){

    if(n == 0){
        return 0 ;
    }
    int ans = INT_MAX ;

    for(int i=1 ; i<=k ; i++){
        int cost = INT_MAX ;
        
        if(n-i >= 0)
            cost = solve(n-i, k, height) + abs(height[n] - height[n-i]) ;

        ans = min(ans, cost) ;
    }

    return ans ;
}

int minimizeCost(int n, int k, vector<int> &height){
    return solve(n-1, k, height) ;
}



// Approch -> 2: Recusion + Memoization
// T.C. = O(N*K)
// S.C. = O(N) + O(N) {Dp array + recursive call satck}
int solve(int n, int k, vector<int> &height, vector<int> &dp){

    if(n == 0){
        return 0 ;
    }

    // step -> 3: if this subproblem previously solved then directly return its stored ans
    if(dp[n] != -1)
        return dp[n] ;
    
    int ans = INT_MAX ;

    for(int i=1 ; i<=k ; i++){
        int cost = INT_MAX ;
        
        if(n-i >= 0)
            cost = solve(n-i, k, height, dp) + abs(height[n] - height[n-i]) ;

        ans = min(ans, cost) ;
    }

    // sgtep -> 2: store the result of subproblem into dp array
    dp[n] = ans ;
    return dp[n] ;
}

int minimizeCost(int n, int k, vector<int> &height){
    // step -> 1: declear a dp array
    vector<int> dp(n, -1) ;
    return solve(n-1, k, height, dp) ;
}




// Approch -> 3: Tabulation Method
// T.C. = O(N*K)
// S.C. = O(N) 
int minimizeCost(int n, int k, vector<int> &height){
    // Step -> 1: Declear DP array
    vector<int> dp(n, -1) ;

    // Step -> 2: Base cases analyses
    dp[0] = 0 ;

    // step -> 3: use of loop
    for(int i=1 ; i<n ; i++){
        int ans = INT_MAX ;

        for(int j=1 ; j<=k && i-j >=0 ; j++){
            int cost = dp[i-j] + abs(height[i] - height[i-j]) ;

            ans = min(ans, cost) ;
        }

        // store the result of subproblem into dp array
        dp[i] = ans ;
    }

    return dp[n-1] ;
}