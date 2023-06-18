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
Algo -> We take two pointer i & j initially i=j=0 and we also take a map in which key = string character, value = pair(index, bool)

        ch = s[j] (jth character of string)
        We traverse the entire string and we check the following condition
        1st condition -> if ch is not visited then we store the index of it & mark visited = true
        2nd condition -> if ch is visited then we update our window by cahnging the position of i such that if i < index of ch + 1
                        (i.e i < visited[ch].first + 1) then we upadate i bcz when we don't apply this condition then in the case of "abba" ans is 
                        wrong bcz 
        and every time we upadte the length
        
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), len=0, i=0, j=0 ;
        unordered_map<char, pair<int, bool> > visited ;

        while(j<n){
            char ch = s[j] ;

            // condition -> 1st
            if(!visited[ch].second){
                visited[ch].second = true ;
                visited[ch].first = j ;
                j++ ;
            }
            
            // // condition -> 2nd
            else{

                // upadte the i
                if(visited[ch].first + 1 > i)
                    i = visited[ch].first + 1 ;
                visited.erase(ch) ;
            }

            // update the length
            len = max(len, j-i) ;
        }

        return len ;
    }
};