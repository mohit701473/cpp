// GFG -> Max Sum without Adjacents
https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

// Code Studio -> Maximum sum of non-adjacent elements
https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf




/*
Que. -> 1: Why we can't apply greedy approch here ?
ans. -> we can't use greedy approch heare bcz jb hum next optimal solution ki tarf badte hai greedy approch se to 
        is beech hum bhut se ese solution ko miss kr denge jo hume global optimal solution dete ho.
*/  




// Approch -> 1: Recursive Approch
/*
intuition -> Adjacent ko nhi lena ho to hum 2 step ya 3 step aage ja skte hai. That mean agr hum i-th idx par hai 
             to hum (i+2)nd index vali value ya (idx+3)rd index vali value ko anpe ans m include kr skte hai and
             esi trah hum final maximum sum nikal skte hai

             main point is taht yha hum do tarike se recursive function ko start kr skte hai.
             1st is 0-th index se => solve(0, arr, n)
             2nd is 1-st index se => solve(1, arr , n)

             solve(idx, arr, n) -> yah function idx index ko lete huve us se aage tk jitni array ki length h vah tk
             ka maximum sum without non adj. nikal kr deta hai.
             suppose idx = 6, n=9 to solve(idx, arr, n) yah function 6-th index ko lete huve i.e starting index is 
             6 h to 6 se 8-th index tk ka maximum sum without non adj. nikal kr deta hai.

*/
// T.C. = O(2^N)
// S.C. = O(N)
class Solution{
    
    int solve(int idx, int* arr, int n){
        if(idx >= n)
            return 0 ;
            
        int left = solve(idx+2 , arr , n) + arr[idx] ;
        int right = solve(idx+3 , arr , n) + arr[idx] ;
        
        return max(left, right) ;
    }
    
public:	

	int findMaxSum(int *arr, int n) {
	    return max(solve(0, arr, n) , solve(1, arr , n)) ;
	}
};




// Approch -> 2: Recusion + Memoization
// T.C. = O(N)
// S.C. = O(N) + O(N) {Dp array + recursive call satck}
class Solution{
    
    int solve(int idx, int* arr, int n, vector<int> &dp){
        if(idx >= n)
            return 0 ;
            
        // step -> 3: if the result of subproblem is already computed then directly return its result 
        if(dp[idx] != -1)
            return dp[idx] ;
            
        int left = solve(idx+2 , arr , n, dp) + arr[idx] ;
        int right = solve(idx+3 , arr , n, dp) + arr[idx] ;
        
        
        // step -> 2: store the subproblem result into dp array
        dp[idx] = max(left, right) ;
        return dp[idx] ;
    }
    
public:	

	int findMaxSum(int *arr, int n) {
	    // step -> 1: Declear a DP Array
	    vector<int> dp(n, -1) ;

        // also i can reduce this two recursive function call into one 
	    return max(solve(0, arr, n, dp) , solve(1, arr , n, dp)) ;
	}
};



// Approch -> 3: Tabulation Method
// T.C. = O(N)
// S.C. = O(N)
class Solution{
public:	

	int findMaxSum(int *arr, int n) {

	    // step -> 1: Declear a DP Array
	    vector<int> dp(n) ;

        // yanha dp array ki koi bhi index pr value yah batati h ki 0-th index se lekar us index tk mai maximum 
        // sum without non adj kitna hai
        // Ex. -> dp[1] = max(arr[0], arr[1]) ; yanha maximum es liye liya q ki ki jb idx = 1 hai to hum 0th index se
        // lekar 1st index tk ka maimum sum without non adj kitna hai nikar rhe hai
	    
	    // step -> 2: analyze the base cases
	    dp[0] = arr[0] ;
	    dp[1] = max(arr[0], arr[1]) ;
	    dp[2] = max(dp[1], arr[0] + arr[2]) ;
	    
	    // step -> 3: apply loop to get final answer
	    for(int idx = 3 ; idx<n ; idx++){
	        int left = dp[idx-2] + arr[idx] ;
	        int right = dp[idx-3] + arr[idx] ;
	        
            // Yanha hum ne esa es liye kiya q ki ho skta hai ki dp[idx-1] > maxi ho i.e. es idx tk ka maimum sum 
            // without non adj. bina ese include kiye aarha ho
	        int maxi = max(left, right) ;
	        dp[idx] = max(dp[idx-1], maxi) ;
	    }
	    return dp[n-1] ;
	}
};



// Approch -> 4: Space Optimization
// T.C. = O(N)
// S.C. = O(1)
class Solution{
public:	

	int findMaxSum(int *arr, int n) {
	    
	    if(n==1) return arr[0] ;
	    if(n==2) return max(arr[0], arr[1]) ;
	    
	    int threeStepPrevios = arr[0] ; // dp[0] = arr[0] ;
	    int twoStepPrevious = max(arr[0], arr[1]) ; // dp[1] = max(arr[0], arr[1]) ;
	    int oneStepPrevious = max(twoStepPrevious, arr[0]+arr[2]) ; // dp[2] = max(dp[1], arr[0] + arr[2]) ;
	    
	    for(int idx = 3 ; idx<n ; idx++){
	        int left = twoStepPrevious + arr[idx] ; // dp[idx-2] + arr[idx] ;
	        int right = threeStepPrevios + arr[idx] ;  // dp[idx-3] + arr[idx] ;
	        
	        int maxi = max(left, right) ;
	        
	        // updating the values of variables
	        threeStepPrevios = twoStepPrevious ;
	        twoStepPrevious = oneStepPrevious ;
	        oneStepPrevious = max(oneStepPrevious, maxi) ; // dp[idx] = max(dp[idx-1], maxi) ;
	    }
	    return oneStepPrevious ; // dp[n-1] ;
	}
};

