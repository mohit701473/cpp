// LeetCode -> 18. 4 Sum
https://leetcode.com/problems/4sum/


// GFG -> https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1


// Approch -> 1: Brute Force Aproch 
// T.C. = O(N^4log(4K))  K => No, of unique quadruplets ;
// S.C. = O(4K) + O(4K)
#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        set<vector<int> > s ;
        
        for(int i=0 ; i<n ; i++){
            ll num1 = nums[i] ;
            for(int j=i+1 ; j<n ; j++){
                ll num2 = nums[j] ;
                for(int k=j+1 ; k<n ; k++){
                    ll num3 = nums[k] ;
                    for(int p=k+1 ; p<n ; p++){
                        ll num4 = nums[p] ;
                        ll sum = num1 + num2 + num3 + num4 ;
                        if(sum == target){
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[p]} ;
                            sort(temp.begin(), temp.end()) ;
                            s.insert(temp) ;
                        }
                    }
                }
            }
        }
        
        vector<vector<int> > ans(s.begin(), s.end()) ;
        
        return ans ;
    }
};



// Approch -> 2:
// T.C. = O(N^3log(K))  k => No. of unique quadruplets
// S.C. = O(k) + O(k) + O(N)
#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        set<vector<int> > s ;
        
        for(int i=0 ; i<n ; i++){
            ll num1 = nums[i] ;
            for(int j=i+1 ; j<n ; j++){
                ll num2 = nums[j] ;
                unordered_set<ll> unSet ;
                for(int k=j+1 ; k<n ; k++){
                    ll num3 = nums[k] ;
                    ll num4 = target - (num1 + num2 + num3) ;
                    if(unSet.find(num4) != unSet.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], int(num4)} ;
                        sort(temp.begin(), temp.end()) ;
                        s.insert(temp) ;
                    }
                    unSet.insert(num3) ;
                }
            }
        }
        
        vector<vector<int> > ans(s.begin(), s.end()) ;
        
        return ans ;
    }
};




// Approch -> 3: Sorting + Two Pointer Approch
// T.C. = O(N^3) +  O(NlogN)
// S.C. = O(No. of unique quadruplets)
#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        sort(nums.begin(), nums.end()) ;
        vector<vector<int> > ans ;

        for(int i=0 ; i<n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue ;
            ll num1 = nums[i] ;
            for(int j=i+1 ; j<n ; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue ;
                ll num2 = nums[j] ;
                int k = j+1 ;
                int r = n-1 ;

                while(k<r){
                    ll num3 = nums[k] ;
                    ll num4 = nums[r] ;

                    ll sum = num1 + num2 + num3 + num4 ;

                    if(sum < target){
                        k++ ;
                    }
                    else if(sum > target){
                        r-- ;
                    }
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[r]} ;
                        ans.push_back(temp) ;
                        k++ ;
                        r-- ;
                        while(k<r && nums[k] == nums[k-1]) k++ ;
                        while(k<r && nums[r] == nums[r+1]) r-- ;
                    }
                }
            }
        }

        return ans ;
    }
};