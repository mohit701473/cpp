// LeetCode -> 15. 3 Sum
https://leetcode.com/problems/3sum/



// Approch -> 1: Brute force approch
// T.C. = (N^3 * log(K))  k => No. of unique triplates in
// S.C. = O(2*K)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size() ;
        set< vector<int> > s ; // this will store unique triplets 

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                for(int k=j+1 ; k<n ; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]} ;
                        sort( temp.begin(), temp.end() ) ;
                        s.insert(temp) ;
                    }
                }
            }
        }

        vector<vector<int>> ans(s.begin(), s.end()) ;
        return ans ;
    }
};



// Approch -> 2: Similear to approch 1 but reduce the time to find third elment(nums[k]) 
// T.C. = (N^2 * log(K))  k => No. of unique triplates in
// S.C. = O(2*K + N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size() ;
        set< vector<int> > s ; // this will store unique triplets 

        for(int i=0 ; i<n ; i++){
            unordered_set<int> us ;
            for(int j=i+1 ; j<n ; j++){
                int key = 0 - (nums[i] + nums[j]) ;
                if(us.find(key) != us.end()){
                    vector<int> temp = {nums[i], nums[j], key} ;
                    sort(temp.begin(), temp.end()) ;
                    s.insert(temp) ;
                }
                us.insert(nums[j]) ;
            }
        }

        vector<vector<int>> ans(s.begin(), s.end()) ;
        return ans ;
    }
};




// Approch -> 3: Sorting + Two Pointer Approch
// T.C. = O(Nlog(N)) + O(N^2)
// S.C. = O(no. of triples)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size() ;
        sort(nums.begin(), nums.end()) ;
        vector<vector<int>> ans ;

        for(int i=0 ; i<n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue ;
            
            int j = i+1 ;
            int k = n-1 ;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k] ;
                if(sum < 0){
                    j++ ;
                }
                else if(sum > 0){
                    k-- ;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]} ;
                    ans.push_back(temp) ;
                    j++ ;
                    k-- ;

                    while(j<k && nums[j] == nums[j-1]) j++ ;
                    while(j<k && nums[k] == nums[k+1]) k-- ;
                }
            }
        }

        return ans ;
    }
};