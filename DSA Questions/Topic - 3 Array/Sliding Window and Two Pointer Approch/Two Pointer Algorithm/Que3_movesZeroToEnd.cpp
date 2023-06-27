



// Approch -> 1 using another array
// T.C. = O(N)
// S.C. = O(N)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size() ;
        vector<int> numsCopy ;
        int zeroCount = 0 ;

        for(int i=0 ; i<n ; i++){
            if(nums[i] != 0)
                numsCopy.push_back(nums[i]) ;
            else zeroCount++ ;
        }

        int i=0 ;
        while(i<numsCopy.size()){
            nums[i] = numsCopy[i] ;
            i++ ;
        }

        while(zeroCount > 0){
            nums[i++] = 0 ;
            zeroCount-- ;
        }
    }
};



// Approch -> 2: Two Pointer Approch
/*
    non zero value ko aage move krte jao
*/
// T.C. = O(N)
// S.C. = O(1) 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        if(nums.size()==1) return;
        
        int l=0, r=0;
        while(r<nums.size()){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
                
            }
            r++;
        }
    }
};