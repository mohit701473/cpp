// LeetCode -> 875. Koko Eating Bananas
https://leetcode.com/problems/koko-eating-bananas/description/


// Approch -> 1: Brute Force Approch
// T.C. = O(max(a[]) * N), where max(a[]) is the maximum element in the array
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

    double findRequireTime(vector<int>& piles, int k){
        double totalHours = 0 ;
        for(int i=0 ; i<piles.size() ; i++){
            double val = ( (double)piles[i] / (double)k) ;
            totalHours += ceil(val) ;
        }

        return totalHours ;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = getMax(piles) ;

        int k = 1 ;
        while(k<=maxi){
            double requireTime = findRequireTime(piles, k) ;
            if(requireTime <= h){
                return k ;
            }
            k++ ;
        }
        return -1 ;
    }
};




// Approch -> 1: Binary Search
// T.C. = O(log(max(a[])) * N), where max(a[]) is the maximum element in the array
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

    double findRequireTime(vector<int>& piles, int k){
        double totalHours = 0 ;
        for(int i=0 ; i<piles.size() ; i++){
            double val = ( (double)piles[i] / (double)k) ;
            totalHours += ceil(val) ;
        }

        return totalHours ;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = getMax(piles) , k ;

        while(low<=high){
            int mid = (low+high)/2 ;
            double requireTime = findRequireTime(piles, mid) ;
            if(requireTime <= h){
                k = mid ;
                high = mid - 1 ;
            }else low = mid + 1 ;
        }

        return k ;
    }
};