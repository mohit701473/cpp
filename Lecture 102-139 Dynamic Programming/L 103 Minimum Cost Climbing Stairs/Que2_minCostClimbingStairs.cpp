

// Approch - 1 using recursion
// T.C. = O(2^N)
// S.C. = O(2^N)
class Solution {
  public:
  
    int solve(vector<int> &cost, int N){
        
        if(N==0 || N==1)
            return cost[N] ;
            
        int ans = cost[N] + min(solve(cost, N-1), solve(cost, N-2)) ;
        
        return ans ;
    }
    
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        
        int ans = min(solve(cost, N-1), solve(cost, N-2)) ;
        
        return ans ;
    }
};


// Approch - 2 Top-Down Approch(Recursion + Memoziation)
// T.C. = O(N)
// S.C. = O(N)
class Solution {
  public:
  
    int solve(vector<int> &cost, int N, vector<int> &minCost){
        //Base case
        if(N==0 || N==1)
            return cost[N] ;
        
        // step -> 3 after the base case kya dp array already answer hold krta h ya nhi 
        if(minCost[N] != -1) // that mean dp array already ans hold krta h
            return minCost[N] ;
            

        // step -> 2 store the ans of recursive relation into dp array and return dp[n]
        minCost[N] = cost[N] + min(solve(cost, N-1, minCost), solve(cost, N-2, minCost)) ;
        return minCost[N] ;

    }
    
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        
        // step -> 1 create a dp array
        vector<int> minCost(N, -1) ;
        int ans = min(solve(cost, N-1, minCost), solve(cost, N-2, minCost)) ;
        
        return ans ;
    }
};

// optimization in approch 2 insted of two recursive call we use only one which is solve(N-2, cost, minCost)
class Solution {
  public:
 
    int solve(vector<int> &cost, int N, vector<int> &minCost){
        //Base case
        if(N==0 || N==1)
            return cost[N] ;
        
        // step -> 3 after the base case kya dp array already answer hold krta h ya nhi 
        if(minCost[N] != -1) // that mean dp array already ans hold krta h
            return minCost[N] ;
            

        // step -> 2 store the ans of recursive relation into dp array and return dp[n]
        minCost[N] = cost[N] + min(solve(cost, N-1, minCost), solve(cost, N-2, minCost)) ;
        return minCost[N] ;

    }
    
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        
        // step -> 1 create a dp array
        vector<int> minCost(N, -1) ;
        minCost[0] = cost[0] ;
        minCost[1] = cost[1] ;
        
        solve(cost, N-2, minCost) ;
        
        minCost[N-1] = cost[N-1] + min(minCost[N-2], minCost[N-3]) ;
        
        int ans = min(minCost[N-1], minCost[N-2]) ;
        
        return ans ;
    }
};



// Approch - 3 Bottom-Up(Tabulation Method)
// T.C.= O(N) 
// S.C.= O(N)
class Solution {
  public:
    
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        
        // step -> 1 creation of dp array
        vector<int> minCost(N, -1) ;
        
        // step -> 2 base case analysis and fill these into dp array
        minCost[0] = cost[0] ;
        minCost[1] = cost[1] ;
        
        // step -> 3 for remaining cases use while 
        int i=2 ; 
        while(i<N){
            minCost[i] = cost[i] + min(minCost[i-1], minCost[i-2]) ;
            i++ ;
        }
        
        int ans = min(minCost[N-1], minCost[N-2]) ;
        
        return ans;
    }
};



// Approch - 4 space optimization
// T.C.= O(N) 
// S.C.= O(1)
class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        
        int minCost1 = cost[0] ;
        int minCost2 = cost[1] ;
        
        int curr = 0;
        
        int i=2 ; 
        while(i<N){
            curr = cost[i] + min(minCost1, minCost2) ;
            minCost1 = minCost2 ;
            minCost2 = curr ;
            
            i++ ;
        }
        
        int ans = min(minCost1, minCost2) ;
        
        return ans;
    }
};

