// Coding Ninja -> Count Subsets with Sum K
https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628




// Approch -> 1: Using Recursion
// T.C. = O(2^N)
// S.C. = O(N)
#define MOD 1000000007 
int solveRecursive(int idx, int sum, vector<int> &arr){
	if(idx == 0){
		if(arr[0] == 0 && sum == 0) return 2 ;
		if(sum == 0 || arr[0] == sum) return 1 ;
		return 0 ;
	}

	// Explore all stuffs
	int notTake = solveRecursive(idx-1, sum, arr) ;

	int take = 0 ;

	if(arr[idx] <= sum){
		take = solveRecursive(idx-1, sum-arr[idx], arr) ;
	}

	return ((take % MOD) + (notTake % MOD)) % MOD ;
}


int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0 ;

    for(auto it: arr){
        totalSum += it ;
    }

    if(totalSum - d < 0 || (totalSum - d) % 2 != 0) return  0 ;

    int k = (totalSum - d) / 2 ;

    return solveRecursive(n-1, k, arr) ;
}





// Approch -> 2: Memoization + recursion
// T.C. = O(N * Target)
// S.C. = O(N * Target) + O(N)
#define MOD 1000000007 
int solveMem(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp){
	// Base Cases
	if(idx == 0){
		if(arr[0] == 0 && sum == 0) return 2 ;
		if(sum == 0 || arr[0] == sum) return 1 ;
		return 0 ;
	}

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


int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0 ;

    for(auto it: arr){
        totalSum += it ;
    }

    if(totalSum - d < 0 || (totalSum - d) % 2 != 0) return  0 ;

    int k = (totalSum - d) / 2 ;
	
	vector<vector<int>> dp(n, vector<int>(k+1, -1)) ;
    return solveMem(n-1, k, arr, dp) ;
}





// Approch -> 3: Tabulation Approch
// T.C. = O(N * Target)
// S.C. = O(N * Target)
#define MOD 1000000007 
int solveTab(vector<int>& arr, int k)
{
	int n = arr.size() ;
	vector<vector<int>> dp(n, vector<int>(k+1, 0)) ;

	if(arr[0] == 0) dp[0][0] = 2 ; // 2 cases -pick and not pick
	else dp[0][0] = 1 ;   // 1 case - not pick

	if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1 ; // 1 case -pick

	for(int idx = 1 ; idx<n ; idx++){

		for(int target = 0 ; target <= k ; target++){

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


int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0 ;

    for(auto it: arr){
        totalSum += it ;
    }

    if(totalSum - d < 0 || (totalSum - d) % 2 != 0) return  0 ;

    int k = (totalSum - d) / 2 ;
	
    return solveTab(arr, k) ;
}


