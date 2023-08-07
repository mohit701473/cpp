// LeetCode -> 13. Roman to Integer
https://leetcode.com/problems/roman-to-integer/description/




// Approch -> 1;
// T.C. = O(N)
// S.C. = O(1)
class Solution {
    void createMappingOfRomanSymbols(unordered_map<char, int> &mp){
        mp['I'] = 1 ;
        mp['V'] = 5 ;
        mp['X'] = 10 ;
        mp['L'] = 50 ;
        mp['C'] = 100 ;
        mp['D'] = 500 ;
        mp['M'] = 1000 ;
    }
public:
    int romanToInt(string s) {
        int n = s.size() ;
        unordered_map<char, int> mp ; 
        createMappingOfRomanSymbols(mp) ;

        int ans = mp[s[n-1]] ;
        for(int i=n-2 ; i>=0 ; i--){
            if(mp[s[i]] >= mp[s[i+1]]) ans += mp[s[i]] ;
            else ans -= mp[s[i]] ;
        }
        
        return ans ;
    }
};