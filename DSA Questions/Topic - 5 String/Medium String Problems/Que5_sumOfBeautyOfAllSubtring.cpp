// LeetCode -> 1781. Sum of Beauty of All Substrings
https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/





// Approch -> 1: Brute Force Approch
// T.C. = O(N^3)
// S.C. = O(26)
class Solution {

    int getSubStringBeautySum(string &str){
        unordered_map<char,int> mp ;
        int maxFreq = INT_MIN, minFreq = INT_MAX ;
        //char ch ;
        for(int i=0 ; i<str.size() ; i++) mp[str[i]]++ ;

        for(int i=0 ; i<str.size() ; i++){
            maxFreq = max(maxFreq, mp[str[i]]) ;
            minFreq = min(minFreq, mp[str[i]]) ;
        }

        return maxFreq - minFreq ;
    }

public:
    int beautySum(string s) {
        int sum = 0, n = s.size() ;

        for(int i=0 ; i<n ; i++){
            string str = "" ;
            for(int j=i ; j<n ; j++){
                str += s[j] ;
                sum += getSubStringBeautySum(str) ;
            }
        }

        return sum ;
    }
};




// Approch -> 1: Two Pointer or Sliding Window Approch
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {

    int beauty(vector<int> &freq){
        int maxFreq = INT_MIN, minFreq = INT_MAX ;

        for(int i=0 ; i<26 ; i++){
            if(freq[i] != 0){
                maxFreq = max(maxFreq, freq[i]) ;
                minFreq = min(minFreq, freq[i]) ;
            }
        }

        return maxFreq - minFreq ;
    }

public:
    int beautySum(string s) {
        int ans = 0 , n = s.size() ;
        if(n < 3) return 0 ;

        for(int size = 3 ; size <= n ; size++){ // size is the size of the substring
            int i = 0 , j = size ;
            vector<int> freq(26,0) ;

            // count the frequency of first j-i+1 elements
            for(int k=i ; k<j ; k++){
                freq[s[k] - 'a']++ ;
            }

            ans += beauty(freq) ;
            //cout<< ans << " " ;

            while(j < n){
                freq[s[j] - 'a']++ ;
                freq[s[i] - 'a']-- ;
                ans += beauty(freq) ;
               // cout<< ans << " " ;
                j++, i++ ;
            }
            cout<<endl;
        }

        return ans ;
    }
};