// LeetCode -> 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/





// Approch -> 1: Using Two for loop + Map
// T.C. = O(N^2)
// S.C. = O(N) 
/*
Algo -> 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), len=0 ;
        unordered_map<char, bool> visited ;

        for(int i=0 ; i<n ; i++){
            int j=i ;
            while(j<n){
                if(!visited[s[j]]){
                    visited[s[j]] = true ;
                    j++ ;
                }
                else break ;
            }
            len = max(len, j-i) ;
            visited.clear() ;
        }

        return len ;
    }
};





// Approch -> 1: Two Pointer Approch + Map
// T.C. = O(N)
// S.C. = O(N) 
/*
Algo -> 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), len=0, i=0, j=0 ;
        unordered_map<char, pair<int, bool> > visited ;

        while(j<n){
            char ch = s[j] ;
            if(!visited[ch].second){
                visited[ch].second = true ;
                visited[ch].first = j ;
                j++ ;
            }else{
                if(visited[ch].first + 1 > i)
                    i = visited[ch].first + 1 ;
                visited.erase(ch) ;
            }

            len = max(len, j-i) ;
        }

        return len ;
    }
};