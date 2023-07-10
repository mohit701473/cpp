// LeetCode -> 1011. Capacity To Ship Packages Within D Days
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/


// Approch -> 1: Brute Force Approch
// T.C. = O(N) + O(K*N) where k = maxi - sum, maxi = maximum element in array & sum = sum of array elements 
// S.C. = O(1)
class Solution {
    
    pair<int, int> getMaxAndSumOfArray(vector<int>& weights){
        int n = weights.size() ;
        int maxi = INT_MIN, sum = 0 ;
        for(auto it: weights){
            maxi = max(maxi, it) ;
            sum += it ;
        }

        return {maxi, sum} ;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        pair<int, int> p = getMaxAndSumOfArray(weights) ;
        int maxi = p.first, sum = p.second ;
        int capacity = maxi ;

        while(capacity <= sum){
            int dayCount = 0, weight = 0 ;
            for(int i=0 ; i<weights.size() ; i++){
                weight += weights[i] ;
                if(weight > capacity){
                    dayCount++ ;
                    weight = weights[i] ;
                }
            }
            dayCount++ ;
            if(dayCount <= days) return capacity ;
            capacity++ ;
        }
        return capacity ;
    }
};




// Approch -> 2: Binary Search
// T.C. = O(N) + O(Nlog(K)) where k = maxi - sum, maxi = maximum element in array & sum = sum of array elements
// S.C. = O(1)
class Solution {
    
    pair<int, int> getMaxAndSumOfArray(vector<int>& weights){
        int n = weights.size() ;
        int maxi = INT_MIN, sum = 0 ;
        for(auto it: weights){
            maxi = max(maxi, it) ;
            sum += it ;
        }

        return {maxi, sum} ;
    }

    bool isValidCapacity(vector<int>& weights, int mid, int days){
        int dayCount = 0, weight = 0 ;
            for(int i=0 ; i<weights.size() ; i++){
                weight += weights[i] ;
                if(weight > mid){
                    dayCount++ ;
                    weight = weights[i] ;
                }
            }
            dayCount++ ;
            if(dayCount <= days) return true ;
            return false ;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        pair<int, int> p = getMaxAndSumOfArray(weights) ;
        int low = p.first, high = p.second ; // low = maximum element in array & high = sum of array elements
        int capacity = 0 ;

        while(low <= high){
            int mid = low + (high-low)/2 ;

            if(isValidCapacity(weights, mid, days)){
                capacity = mid ;
                high = mid-1 ;
            }else low = mid+1 ;
            
        }
        return capacity ;
    }
};