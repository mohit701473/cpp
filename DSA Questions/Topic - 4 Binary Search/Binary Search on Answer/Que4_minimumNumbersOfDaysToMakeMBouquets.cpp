// LeetCode -> 1482. Minimum Number of Days to Make m Bouquets
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/


// Approch -> 1: Brute Force Approch
/*
Approch -> We konw that ans(no. of mindays) lies in the range of 1 to maxium value in bloomDay array
           step -> 1: first find the maximum in the bloomDay array 
           step -> 2: run a while loop from 1 to maxi 
           step -> 3: agr bloomDay[i] == day to i.e. flower bloomed so blommed flower ke track ke liye bloomDay[i] = 0 kr diya
           step -> 4: jo jo flower bloom ho chuke h unka count kr tte h and do count such that flower shoud be adjacent and if count == k to bouquet
                      ban jaye ga so m-- kr diya
           step ->5: if m==0 i.e. all bouquets are created so return that day
*/
// T.C. = O(N) + O( max(bloomDay[]) * (N + N*k) )
// S.C. = O(1)
class Solution {
    
    int getMax(vector<int>& piles){
        int n = piles.size() ;
        int maxi = INT_MIN ;
        for(int i=0 ; i<n ; i++){
            maxi = max(maxi, piles[i]) ;
        }

        return maxi ;
    }
    
  public:
    int solve(int m, int k, vector<int> &bloomDay){
        int n = bloomDay.size() ;
        if(m*k > n) return -1 ;
        int maxi = getMax(bloomDay) ;

        int day = 1 ;
        while(day <= maxi){
            for(int i=0 ; i<n ; i++){
                if(bloomDay[i] == day) bloomDay[i] = 0 ;
            }

            for(int i=0 ; i<n ; i++){
                if(bloomDay[i] != 0) continue;
                else{
                    int stIdx = i, endIdx = i ;
                    while(endIdx < n && bloomDay[endIdx] == 0 && endIdx - stIdx < k) endIdx++ ;
                    if(endIdx - stIdx == k){
                        m-- ;
                        for(int i=stIdx ; i<endIdx ; i++) bloomDay[i] = -1 ;
                    }
                }
            }
            if(m==0) return day ;
            day++ ;
        }

        return day ;
    }
};








// Approch -> 1: Binary Search On Answer
/*
Approch -> We konw that ans(no. of mindays) lies in the range of 1 to maxium value in bloomDay array
           step -> 1: first find the maximum in the bloomDay array 
           step -> 2: run a while loop from 1 to maxi 
           step -> 3: agr bloomDay[i] == day to i.e. flower bloomed so blommed flower ke track ke liye bloomDay[i] = 0 kr diya
           step -> 4: jo jo flower bloom ho chuke h unka count kr tte h and do count such that flower shoud be adjacent and if count == k to bouquet
                      ban jaye ga so m-- kr diya
           step ->5: if m==0 i.e. all bouquets are created so return that day
*/
// T.C. = O(N) + O(log(max-min) * N) where max & min are the maximum and minimum elements from the bloomDay array
// S.C. = O(1)
class Solution {
    pair<int, int>  getMinMax(vector<int>& bloomDay){
        int n = bloomDay.size() ;
        int maxi = INT_MIN, mini = INT_MAX ;
        for(int i=0 ; i<n ; i++){
            maxi = max(maxi, bloomDay[i]) ;
            mini = min(mini, bloomDay[i]) ;
        }

        return {mini, maxi} ;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size() ;
        long long val = m * 1ll * k * 1ll;
        if(val > n) return -1 ;
        pair<int, int> p = getMinMax(bloomDay) ;
        int ans, low = p.first, high = p.second, requireDays = -1 ;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            int bouquetCnt = 0, adjacentCnt = 0, i=0;
            while(i<n){
                if(bloomDay[i] <= mid){
                    adjacentCnt++ ;
                    i++ ;
                }
                else{
                    adjacentCnt = 0 ;
                    while(i<n && bloomDay[i] > mid) i++ ;
                }
                if(adjacentCnt == k){
                    bouquetCnt++ ;
                    adjacentCnt = 0 ;
                }
            }

            if(bouquetCnt >= m){
                ans = mid ;
                high = mid -1 ;
            }else low = mid +1 ;
        }

        return ans ;
    }
};