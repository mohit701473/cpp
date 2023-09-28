// Coding Ninja -> Count Subsets with Sum K
https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532




// Approch -> 1: Using Recursion
// T.C. = O(2^N)
// S.C. = O(N)
#define MOD 1000000007 
int solveRecursive(int idx, int sum, vector<int> &arr){
	// Base Cases
	if(sum == 0) return 1 ;

	if(idx == 0) return arr[idx] == sum ? 1 : 0 ;

	// Explore all stuffs
	int notTake = solveRecursive(idx-1, sum, arr) ;

	int take = 0 ;

	if(arr[idx] <= sum){
		take = solveRecursive(idx-1, sum-arr[idx], arr) ;
	}

	return ((take % MOD) + (notTake % MOD)) % MOD ;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size() ;

	return solveRecursive(n-1, k, arr) ;
}





// Approch -> 2: Memoization + recursion
// T.C. = O(N * Target)
// S.C. = O(N * Target) + O(N)
#define MOD 1000000007 
int solveMem(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp){
	// Base Cases
	if(sum == 0) return 1 ;

	if(idx == 0) return arr[idx] == sum ? 1 : 0 ;

	if(dp[idx][sum] != -1) return dp[idx][sum] ;

	// Explore all stuffs
	int notTake = solveMem(idx-1, sum, arr, dp) ;

	int take = 0 ;

	if(arr[idx] <= sum){
		take = solveMem(idx-1, sum-arr[idx], arr, dp) ;
	}

	dp[idx][sum] = ((take % MOD) + (notTake % MOD)) % MOD ;
	return dp[idx][sum] ;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size() ;
	vector<vector<int>> dp(n, vector<int>(k+1, -1)) ;
	return solveMem(n-1, k, arr, dp) ;
}






// Approch -> 3: Tabulation Approch
// T.C. = O(N * Target)
// S.C. = O(N * Target)
#define MOD 1000000007 
int findWays(vector<int>& arr, int k)
{
	int n = arr.size() ;
	vector<vector<int>> dp(n, vector<int>(k+1)) ;

	for(int i=0 ; i<n ; i++) dp[i][0] = 1 ;

	if(arr[0] <= k) dp[0][arr[0]] = 1 ;

	for(int idx = 1 ; idx<n ; idx++){

		for(int target = 1 ; target <= k ; target++){

			int notTake = dp[idx-1][target] ;  // solveMem(idx-1, sum, arr, dp) ;

			int take = 0 ;

			if(arr[idx] <= target){
				take = dp[idx-1][target-arr[idx]] ; // solveMem(idx-1, sum-arr[idx], arr, dp) ;
			}

			dp[idx][target] = ((take % MOD) + (notTake % MOD)) % MOD ;			
		}
	}


	return dp[n-1][k] ;
}





// Approch -> 4: Sapce Optimization
// T.C. = O(N * Target)
// S.C. = O(Target)
#define MOD 1000000007 
int findWays(vector<int>& arr, int k)
{
	int n = arr.size() ;
	vector<int> prev(k+1, 0) ;
	vector<int> curr(k+1, 0) ;

	prev[0] = curr[0] = 1 ;
	if(arr[0] <= k) prev[arr[0]] = 1 ;


	for(int idx = 1 ; idx<n ; idx++){

		for(int target = 1 ; target <= k ; target++){

			int notTake = prev[target] ;  // solveMem(idx-1, sum, arr, dp) ;

			int take = 0 ;

			if(arr[idx] <= target){
				take = prev[target-arr[idx]] ; // solveMem(idx-1, sum-arr[idx], arr, dp) ;
			}

			curr[target] = ((take % MOD) + (notTake % MOD)) % MOD ;			
		}

		prev = curr ;
	}


	return prev[k] ;
}
