// Coding Ninja -> Rod cutting problem
https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284





// Approch -> 1: Recursion
// T.C. = Exponential
// S.C. = O(N)
int solveRecursive(int idx, int N, vector<int> &price){
	// base case
	if(idx == 0){
		return N * price[0] ;
	}

	// explore all possibilities 
	int notTake = solveRecursive(idx-1, N, price) ;

	int take = INT_MIN ;
	int roadLen = idx+1 ;
	if(N >= roadLen){
		take = price[idx] + solveRecursive(idx, N-roadLen, price) ;
	}

	return max(take, notTake) ;
}

int cutRod(vector<int> &price, int n)
{
	return solveRecursive(n-1, n, price) ;
}




// Approch -> 2: Memoization
// T.C. = O(N * N)
// S.C. = O(N * N) + O(N)
int solveRecursive(int idx, int N, vector<int> &price, vector<vector<int>> &dp){
	// base case
	if(idx == 0){
		return N * price[0] ;
	}

	if(dp[idx][N] != -1)
		return dp[idx][N] ;

	// explore all possibilities 
	int notTake = solveRecursive(idx-1, N, price, dp) ;

	int take = INT_MIN ;
	int roadLen = idx+1 ;
	if(N >= roadLen){
		take = price[idx] + solveRecursive(idx, N-roadLen, price, dp) ;
	}

	dp[idx][N] = max(take, notTake) ;
	return dp[idx][N] ;
}

int cutRod(vector<int> &price, int n)
{	vector<vector<int>> dp(n, vector<int>(n+1, -1)) ;

	return solveRecursive(n-1, n, price, dp) ;
}





// Approch -> 3: Tabulation
// T.C. = O(N * N)
// S.C. = O(N * N) 
int cutRod(vector<int> &price, int n)
{	
	vector<vector<int>> dp(n, vector<int>(n+1, 0)) ;

	// base case
	for(int N = 0 ; N <= n ; N++){
		dp[0][N] = N * price[0] ;
	}

	// loops
	for(int idx=1 ; idx<n ; idx++){

		for(int N=0 ; N<=n ; N++){

			int notTake = dp[idx-1][N] ; // solveRecursive(idx-1, N, price, dp) ;

			int take = 0 ;
			int roadLen = idx+1 ;
			if(N >= roadLen){
				take = price[idx] + dp[idx][N-roadLen] ;  // solveRecursive(idx, N-roadLen, price, dp) ;
			}

			dp[idx][N] = max(take, notTake) ;
		}
	}

	return dp[n-1][n] ; // solveRecursive(n-1, n, price, dp) ;
}




// Approch -> 4: Space Optimization in two row
// T.C. = O(N * N)
// S.C. = O(2 * N) 
int cutRod(vector<int> &price, int n)
{	
	vector<int> prev(n+1, 0), curr(n+1, 0) ;

	// base case
	for(int N = 0 ; N <= n ; N++){
		prev[N] = N * price[0] ;
	}

	// loops
	for(int idx=1 ; idx<n ; idx++){

		for(int N=0 ; N<=n ; N++){

			int notTake = prev[N] ; // solveRecursive(idx-1, N, price, dp) ;

			int take = 0 ;
			int roadLen = idx+1 ;
			if(N >= roadLen){
				take = price[idx] + curr[N-roadLen] ;  // solveRecursive(idx, N-roadLen, price, dp) ;
			}

			curr[N] = max(take, notTake) ;
		}

		prev = curr ;
	}

	return prev[n] ; // solveRecursive(n-1, n, price, dp) ;
}




// Approch -> 5: Space Optimization in one row
// T.C. = O(N * N)
// S.C. = O(N) 
int cutRod(vector<int> &price, int n)
{	
	vector<int> prev(n+1, 0) ;

	// base case
	for(int N = 0 ; N <= n ; N++){
		prev[N] = N * price[0] ;
	}

	// loops
	for(int idx=1 ; idx<n ; idx++){

		for(int N=0 ; N<=n ; N++){

			int notTake = prev[N] ; // solveRecursive(idx-1, N, price, dp) ;

			int take = 0 ;
			int roadLen = idx+1 ;
			if(N >= roadLen){
				take = price[idx] + prev[N-roadLen] ;  // solveRecursive(idx, N-roadLen, price, dp) ;
			}

			prev[N] = max(take, notTake) ;
		}
	}

	return prev[n] ; // solveRecursive(n-1, n, price, dp) ;
}


