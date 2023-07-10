


// Approch -> 1: Brute Force Approch
// T.C. = O(Nlog(N)) + O(N*10^9)
// S.C. = O(1)
class Solution {
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end()) ;
        int minDistance = 1, maxDistance = stalls[n-1] - stalls[0] ;
        
        while(minDistance <= maxDistance){
            int cows = 1, lastPlaced = stalls[0] ;
            for(int i=1 ; i<n ; i++){
                if(stalls[i]  - lastPlaced >= minDistance){
                    cows++ ;
                    lastPlaced = stalls[i] ;
                }
                if(cows == k) break ;
            }
            if(cows < k) return minDistance-1 ;
            minDistance++ ;
        }
        
        return -1 ;
    }
};





// Approch -> 1: Binary Search
// T.C. = O(Nlog(N)) + O(N*log(10^9))
// S.C. = O(1)
class Solution {
    
    bool isPossibleMinDistance(vector<int> &stalls, int n, int k, int minDistance){
        int cows = 1, lastPlaced = stalls[0] ;
        for(int i=1 ; i<n ; i++){
            if(stalls[i]  - lastPlaced >= minDistance){
                cows++ ;
                lastPlaced = stalls[i] ;
            }
            if(cows == k) return true ;
        }
        return false ;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end()) ;
        int low = 1, high = stalls[n-1] - stalls[0] ;
        int ans = -1 ;
        while(low <= high){
            int mid = low +(high-low)/2 ;
            
            if(isPossibleMinDistance(stalls,n, k, mid)){
                ans = mid ;
                low = mid + 1 ;
            }else high = mid - 1 ;
        }
        
        return ans ;
    }
};