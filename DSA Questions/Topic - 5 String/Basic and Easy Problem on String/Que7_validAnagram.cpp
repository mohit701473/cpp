// LeetCode -> 242. Valid Anagram
https://leetcode.com/problems/valid-anagram/description/


// Approch -> 1: Sorting 
// T.C. = O(2Nlog(N) + N)
// S.C. = O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false ;
        sort(s.begin(), s.end()) ;
        sort(t.begin(), t.end()) ;
        if(s == t) return true ;
        return false ;
    }
};


// Approch -> 2: Hashing 
// T.C. = O(2N)
// S.C. = O(26)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false ;

        unordered_map<char, int> freq ;
        for(int i=0 ; i<s.size() ; i++) freq[s[i]]++ ;

        int i=0 ;
        while(i<s.size()){
            char ch = t[i] ;
            if(freq.find(ch) == freq.end()) return false ;
            freq[ch]-- ;
            if(freq[ch] < 0) return false ;
            i++ ;
        }

        return true ;
    }
};