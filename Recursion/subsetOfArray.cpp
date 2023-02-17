// LeetCode  Que: 78. Subsets

class Solution {
public:

    void getSubset(vector<int> &nums, vector<int> output, int index,  vector<vector<int>> &ans) {

        int size = nums.size() ;

        if(index == size){
            ans.push_back(output) ;
            return ;
        }

        // Exclude 
        getSubset(nums, output, index+1, ans) ;

        // Include
        int element = nums[index] ;
        output.push_back(element) ;
        getSubset(nums, output, index+1, ans) ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        int index = 0 ;
        vector<vector<int>> ans ;
        vector<int> output ;

        getSubset(nums, output, index, ans) ;

        return ans ;
    }
};