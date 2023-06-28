// LeetCode -> 75. Sort Colors
https://leetcode.com/problems/sort-colors/description/



// Approch -> 1: Count Sort
// T.C. = O(2N)
// S.C. = O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector<int> count(3,0) ;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0)
                count[0]++ ;

            else{
                if(nums[i] == 1)
                    count[1]++ ;
                
                else count[2]++ ;
            }
        }

        int index = 0 ;
        for(int i=0 ; i<count[0] ; i++){
            nums[index++] = 0 ;
        }

        for(int i=0 ; i<count[1] ; i++){
            nums[index++] = 1 ;
        }

        for(int i=0 ; i<count[2] ; i++){
            nums[index++] = 2 ;
        }
    }
};




// Approch -> 2: Two/Three Pointer Approch
// Algo -> Ditch National Flag Algorithm
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low=0, mid=0, heigh=nums.size()-1 ;

        while(mid<=heigh){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]) ;
                mid++ ;
                low++ ;
            }else if(nums[mid] == 1){
                mid++ ;
            }else{ // nums[mid] == 2
                swap(nums[mid], nums[heigh]) ;
                heigh -- ;
            }
        }
    }
};