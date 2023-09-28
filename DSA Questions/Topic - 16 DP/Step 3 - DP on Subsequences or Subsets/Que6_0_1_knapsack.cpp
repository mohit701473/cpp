// Codeing Ninja -> 0 1 Knapsack
https://www.codingninjas.com/studio/problems/0-1-knapsack_920542



// GFG -> 0-1 Knapsack
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1



// Approch -> 1: Using Recursion
// T.C. = O(2^N)
// S.C. = O(N)
int solveRecursive(int idx, int W, vector<int> &weight, vector<int> &value){
	// Base cases
	if(idx == 0){
		if(weight[0] <= W) return value[0] ;
		return 0 ;
	}

	// Explore all possibilities 
	int notTake = solveRecursive(idx-1, W, weight, value) ;

	int take = 0 ;
	if(weight[idx] <= W)
		take = value[idx] + solveRecursive(idx-1, W-weight[idx], weight, value) ;

	return max(notTake, take) ;
	
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveRecursive(n-1, maxWeight, weight, value) ;
}




// Approch -> 2: Memoization + recursion
// T.C. = O(N * maxWeight)
// S.C. = O(N * maxWeight) + O(N)
int solveMem(int idx, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
	// Base cases
	if(idx == 0){
		if(weight[0] <= W) return value[0] ;
		return 0 ;
	}

	if(dp[idx][W] != -1)
		return dp[idx][W] ;

	// Explore all possibilities 
	int notTake = solveMem(idx-1, W, weight, value, dp) ;

	int take = 0 ;
	if(weight[idx] <= W)
		take = value[idx] + solveMem(idx-1, W-weight[idx], weight, value, dp) ;

	dp[idx][W] = max(notTake, take);
	return dp[idx][W] ;
	
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1)) ;
	
	return solveMem(n-1, maxWeight, weight, value, dp) ;
}





// Approch -> 3: Tabulation Approch
// T.C. = O(N * maxWeight)
// S.C. = O(N * maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0)) ;

	// Base cases analysis
	for(int w=weight[0] ; w<=maxWeight ; w++)
		dp[0][w] = value[0] ;
	

	// nested loops
	for(int idx=1 ; idx<n ; idx++){
		
		for(int w=0 ; w<=maxWeight ; w++){

			int notTake = dp[idx-1][w] ; // solveMem(idx-1, W, weight, value, dp) ;

			int take = 0 ;
			if(weight[idx] <= w)
				take = value[idx] + dp[idx-1][w-weight[idx]] ; // solveMem(idx-1, W-weight[idx], weight, value, dp) ;

			dp[idx][w] = max(notTake, take) ;
		}
	}
	
	return dp[n-1][maxWeight] ; // solveMem(n-1, maxWeight, weight, value, dp) ;
}




// Approch -> 4: Sapce Optimization
// T.C. = O(N * maxWight)
// S.C. = O(2 * maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0) , curr(maxWeight+1, 0) ;

	// Base cases analysis
	for(int w=weight[0] ; w<=maxWeight ; w++)
		prev[w] = value[0] ;
	

	// nested loops
	for(int idx=1 ; idx<n ; idx++){
		
		for(int w=0 ; w<=maxWeight ; w++){

			int notTake = prev[w] ; // solveMem(idx-1, W, weight, value, dp) ;

			int take = 0 ;
			if(weight[idx] <= w)
				take = value[idx] + prev[w-weight[idx]] ; // solveMem(idx-1, W-weight[idx], weight, value, dp) ;

			curr[w] = max(notTake, take) ;
		}

		prev = curr ;
	}
	
	return prev[maxWeight] ; // solveMem(n-1, maxWeight, weight, value, dp) ;
}




// Approch -> 5: one row space optimization
// T.C. = O(N * maxWeight)
// S.C. = O(maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0) ;

	// Base cases analysis
	for(int w=weight[0] ; w<=maxWeight ; w++)
		prev[w] = value[0] ;
	

	// nested loops
	for(int idx=1 ; idx<n ; idx++){
		
		for(int w=maxWeight ; w>=0 ; w--){

			int notTake = prev[w] ; // solveMem(idx-1, W, weight, value, dp) ;

			int take = 0 ;
			if(weight[idx] <= w)
				take = value[idx] + prev[w-weight[idx]] ; // solveMem(idx-1, W-weight[idx], weight, value, dp) ;

			prev[w] = max(notTake, take) ;
		}
	}
	
	return prev[maxWeight] ; // solveMem(n-1, maxWeight, weight, value, dp) ;
}