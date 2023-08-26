// GFG -> Subset Sum Problem
https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1



// Approch -> 1: Using Recursion
// T.C. = O(2^N)
// S.C. = O(N)
class Solution{   
    
    bool solveRecursive(int idx, int target, vector<int> &arr){
        // Base Cases
        if(target == 0) return true ;
        
        if(idx == 0) return (arr[idx] == target) ;
        
        // Explore all possibilites of that index
        bool notTake = solveRecursive(idx-1, target, arr) ;
        
        bool take = false ;
        if(arr[idx] <= target)
            take = solveRecursive(idx-1, target-arr[idx], arr) ;
        
        return take || notTake ;
    }
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int lastIdx = arr.size() - 1 ;
        return solveRecursive(lastIdx, sum, arr) ;
    }
};





// Approch -> 2: Memoization + recursion
// T.C. = O(N * Target)
// S.C. = O(N * Target) + O(N)
class Solution{   
    
    bool solveRecursive(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
        // Base Cases
        if(target == 0) return true ;
        
        if(idx == 0) return (arr[idx] == target) ;
        
        // step -> 3:
        if(dp[idx][target] != -1){
            return dp[idx][target] ;
        }
        
        // Explore all possibilites of that index
        bool notTake = solveRecursive(idx-1, target, arr, dp) ;
        
        bool take = false ;
        if(arr[idx] <= target)
            take = solveRecursive(idx-1, target-arr[idx], arr, dp) ;
        
        // step -> 2: store the result of subproblem
        dp[idx][target] = (take || notTake) == true ? 1 : 0 ;
        
        return dp[idx][target] ;
    }
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size() ;
        
        // step -> 1: Declear a dp data structure
        vector<vector<int>> dp(n, vector<int>(sum+1, -1)) ;
        
        return solveRecursive(n-1, sum, arr, dp) ;
    }
};





// Approch -> 3: Tabulation Approch
// T.C. = O(N * Target)
// S.C. = O(N * Target)
class Solution{   
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size() ;
        
        // step -> 1: Declear a dp data structure
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false)) ;
        
        // Step -> 2: Base case analyses
        for(int i=0 ; i<n ; i++) dp[i][0] = true ;
        
        dp[0][arr[0]] = true ;
        
        // step -> 3: nested loop
        for(int idx = 1 ; idx<n ; idx++){
            
            for(int target = 1 ; target<=sum ; target++){
                
                // copy paste the recurance from memoization solution
                
                bool notTake = dp[idx-1][target] ;
        
                bool take = false ;
                if(arr[idx] <= target)
                    take = dp[idx-1][target-arr[idx]] ;
                
                dp[idx][target] = take || notTake ;
                
            }
        }
        
        return dp[n-1][sum] ;
    }
};




// Approch -> 4: Sapce Optimization
// T.C. = O(N * Target)
// S.C. = O(Target)
class Solution{   
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size() ;
        
        vector<bool> prev(sum+1, false) , curr(sum+1, false) ;
        
        prev[0] = curr[0] = true ;
        prev[arr[0]] = true ;
        
        
        for(int idx = 1 ; idx<n ; idx++){
            
            for(int target = 1 ; target<=sum ; target++){
                
                
                bool notTake = prev[target] ;
        
                bool take = false ;
                if(arr[idx] <= target)
                    take = prev[target-arr[idx]] ;
                
                curr[target] = take || notTake ;
                
            }
            
            prev = curr ;
        }
        
        return prev[sum] ;
    }
};

