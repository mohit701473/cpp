// LeetCode -> 1. Two Sum
https://leetcode.com/problems/two-sum/description/



// Approch -> 1: Brute Force Approch
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans ;

        for(int i=0 ; i<nums.size() ; i++){
            int num1 = nums[i] ;
            int key = target-num1 ;

            for(int j=0 ; j<nums.size() ; j++){
                if(i != j && nums[j] == key){
                    ans.push_back(i) ;
                    ans.push_back(j) ;
                    return ans ;
                }
            }
        }

        return ans ;
    }
};




// Approch -> 2: Using Hash Map
// T.C. = O(N) But in very worst case when lots of collision occure then hash map take O(N) time & T.C. = O(N^2)
// S.C. = O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans ;
        int n = nums.size() ;
        unordered_map<int, int> ump ;

        for(int i=0 ; i<n ; i++){
            ump[nums[i]] = i ;
        }

        for(int i=0 ; i<n ; i++){
            int num1 = nums[i] ;
            int key = target - num1 ;

            if( ( ump.find(key) != ump.end() ) && ump.at(key) != i ){
                ans.push_back(i) ;
                ans.push_back(ump[key]) ;
                break ;
            }
        }

        return ans ;
    }
};