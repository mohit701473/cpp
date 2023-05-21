



// Approch -> 1 recursive approch
// T.C. => exponential
// S.C. => Exponential
long long int solveRecursive(vector<int>& valueInHouse, int N, int i){
    if( i>=N )
        return 0 ;

    int incl = valueInHouse[i] + solveRecursive(valueInHouse, N, i+2) ;
    int excl = solveRecursive(valueInHouse, N, i+1) + 0 ;

    return max(incl, excl) ;
}

long long int houseRobber(vector<int>& valueInHouse)
{   
    int n = valueInHouse.size() ;

    if(n==1)
        return valueInHouse[0] ;


    return max(solveRecursive(valueInHouse, n-1, 0), solveRecursive(valueInHouse, n, 1)) ;
}




// Approch -> 2 Top-Down Approch(recursion + memoization)
// T.C. => O(n)
// S.C. => O(n)
long long int solveMemoization(vector<int> &valueInHouse, int N, int i, vector<long long int> &dp){

    if( i >= N)
        return 0 ;

    if(dp[i] != -1) 
        return dp[i] ;

    long long int incl = valueInHouse[i] + solveMemoization(valueInHouse, N, i+2, dp) ;
    long long int excl = solveMemoization(valueInHouse, N, i+1, dp) + 0 ;

    dp[i] =  max(incl, excl) ;
    return dp[i] ;
}


long long int houseRobber(vector<int>& valueInHouse)
{   
    int n = valueInHouse.size() ;
    vector<long long int> dp(n, -1) ;

    if(n==1)
        return valueInHouse[0] ;

    long long int ans1 = solveMemoization(valueInHouse, n-1, 0, dp) ;  
    //cout<<"ans1 -> "<<ans1 <<endl;

    for(auto &i: dp)
        i = -1 ;

    long long int ans2 = solveMemoization(valueInHouse, n, 1, dp) ;
    //cout<<"ans2 -> "<<ans2<<endl;


    return max(ans1, ans2) ;
}


