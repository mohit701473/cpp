// LeetCode -> 128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/




// Approch -> 1: Brute Force Approch
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {

    bool linearSearch(vector<int>& nums, int n, int key){
        for(int i=0 ; i<n ; i++){
            if(nums[i] == key)
                return true ;
        }

        return false ;
    }

public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0 ;

        int maxSequence = 1, n = nums.size() ;

        for(int i=0 ; i<n ; i++){
            int x = nums[i] ;
            int count = 1 ;

            while(linearSearch(nums,n ,x+1)){
                x++ ;
                count++ ;
            }

            maxSequence = max(maxSequence, count) ;
        }

        return maxSequence ;
        
    }
};







// Aproch -> 2: Sort the array and track the last smaller element 
// T.C. = O(Nlog(N)) + O(N)
// S.C. = O(1)
class Solution {

public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0 ;

        int maxSequence = 1, n = nums.size() ;
        int lastSmaller = INT_MIN ;

        sort(nums.begin(), nums.end()) ;

        int count = 0 ;
        for(int i=0 ; i<n ; i++){
            if(nums[i] -1 == lastSmaller){
                count++ ;
                //lastSmaller = nums[i] ;
            }else if(nums[i] != lastSmaller){
                count = 1 ;
                //lastSmaller = nums[i] ;
            }

            lastSmaller = nums[i] ;
            maxSequence = max(maxSequence, count) ;
        }

        return maxSequence ;
    }
};












// Approch -> 3: Using Hash Map 
// T.C. = O(3N)  =>  The while loop will run completly N time 
// S.C. = O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0 ;

        unordered_map<int, bool> containStartingKey ;
        
        // step -> 1: insert all array element in map and mark ture 
        for(auto it: nums){
            containStartingKey[it] = true ;
        }

        // step -> 2: ese element jo kis bhi Consecutive Sequence ke starting elemnet nhi ho skte uhne false mark kr do
        for(auto it: nums){
            if( containStartingKey.find(it -1) != containStartingKey.end() ){
                containStartingKey[it] = false ;
            }
        }


        // step -> 3: containStartingKey map m jo true mark h vo hi sirf kisi Consecutive Sequence ke starting points honge so only true makred 
        // element ke liye hi process kro
        int maxSequenceLen = 0 ;
        int startingPointOfMaxSequence = INT_MIN ;
        for(auto it: nums){
            if(containStartingKey[it]){
                int len = 1 ;
                int tsp = it ;

                while( containStartingKey.find(it+len) != containStartingKey.end() ){
                    len++ ;
                }

                if(len > maxSequenceLen){
                    maxSequenceLen = len ;
                    startingPointOfMaxSequence = tsp ;
                }
            }
        } 

        return maxSequenceLen ;
    }
};