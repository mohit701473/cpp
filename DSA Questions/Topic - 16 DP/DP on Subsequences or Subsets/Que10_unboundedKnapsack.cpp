// Coding Ninja -> Unbounded Knapsack
https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029




// Approch -> 1: Recursion
// T.C. = Exponential
// S.C. = O(W)
int solveRecursive(int idx, int W, vector<int> &profit, vector<int> &weight){
    // base case
    if(idx == 0){
        if(W >= weight[0]) return (profit[0]) * (W/weight[0]) ;

        return 0 ;
    }

    // explore all possibilities
    int notTake = solveRecursive(idx-1, W, profit, weight) ;

    int take = 0 ;
    if(W >= weight[idx])
        take = profit[idx] + solveRecursive(idx, W-weight[idx], profit, weight) ;

    return max(take, notTake) ;
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    
    return solveRecursive(n-1, w, profit, weight) ;
}





// Approch -> 2: Memoization
// T.C. = O(N * W)
// S.C. = O(N * W) + O(W)
int solveMem(int idx, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    // base case
    if(idx == 0){
        if(W >= weight[0]) return (profit[0]) * (W/weight[0]) ;

        return 0 ;
    }

    if(dp[idx][W] != -1)
        return dp[idx][W] ;

    // explore all possibilities
    int notTake = solveMem(idx-1, W, profit, weight, dp) ;

    int take = 0 ;
    if(W >= weight[idx])
        take = profit[idx] + solveMem(idx, W-weight[idx], profit, weight, dp) ;
    

    dp[idx][W] = max(take, notTake) ;
    return dp[idx][W] ;
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    
    vector<vector<int>> dp(n, vector<int>(w+1, -1)) ;

    return solveMem(n-1, w, profit, weight, dp) ;
}




// Approch -> 3: tabulation
// T.C. = O(W * N)
// S.C. = O(W * N)
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight){
    
    vector<vector<int>> dp(n, vector<int>(W+1, 0)) ;

    // Base case
    for(int knap_w = weight[0] ; knap_w <= W ; knap_w++){
        dp[0][knap_w] = (profit[0]) * (knap_w/weight[0]) ;
    }

    // nested loops
    for(int idx = 1 ; idx < n ; idx++){

        for(int knap_w = 0 ; knap_w <= W ; knap_w++){

            int notTake = dp[idx-1][knap_w] ;  // solveMem(idx-1, W, profit, weight, dp) ;

            int take = 0 ;
            if(knap_w >= weight[idx])
                take = profit[idx] + dp[idx][knap_w - weight[idx]] ; // solveMem(idx, W-weight[idx], profit, weight, dp) ;
            

            dp[idx][knap_w] = max(take, notTake) ;
        }
    }



    return dp[n-1][W] ; // solveMem(n-1, w, profit, weight, dp) ;
}




// Approch -> 4: Space Optimozation
// T.C. = O(W * N)
// S.C. = O(2 * W)
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight){
    
    vector<int> prev(W+1, 0) , curr(W+1, 0) ;

    // Base case
    for(int knap_w = weight[0] ; knap_w <= W ; knap_w++){
        prev[knap_w] = (profit[0]) * (knap_w/weight[0]) ;
    }

    // nested loops
    for(int idx = 1 ; idx < n ; idx++){

        for(int knap_w = 0 ; knap_w <= W ; knap_w++){

            int notTake = prev[knap_w] ;  // solveMem(idx-1, W, profit, weight, dp) ;

            int take = 0 ;
            if(knap_w >= weight[idx])
                take = profit[idx] + curr[knap_w - weight[idx]] ; // solveMem(idx, W-weight[idx], profit, weight, dp) ;
            

            curr[knap_w] = max(take, notTake) ;
        }

        prev = curr ;
    }



    return prev[W] ; // solveMem(n-1, w, profit, weight, dp) ;
}





// Approch -> 5: Space Optimozation from 2 vector to 1 vector
// T.C. = O(W * N)
// S.C. = O(W)
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight){
    
    vector<int> prev(W+1, 0) ;

    // Base case
    for(int knap_w = weight[0] ; knap_w <= W ; knap_w++){
        prev[knap_w] = (profit[0]) * (knap_w/weight[0]) ;
    }

    // nested loops
    for(int idx = 1 ; idx < n ; idx++){

        for(int knap_w = 0 ; knap_w <= W ; knap_w++){

            int notTake = prev[knap_w] ;  // solveMem(idx-1, W, profit, weight, dp) ;

            int take = 0 ;
            if(knap_w >= weight[idx])
                take = profit[idx] + prev[knap_w - weight[idx]] ; // solveMem(idx, W-weight[idx], profit, weight, dp) ;
            

            prev[knap_w] = max(take, notTake) ;
        }
    }



    return prev[W] ; // solveMem(n-1, w, profit, weight, dp) ;
}