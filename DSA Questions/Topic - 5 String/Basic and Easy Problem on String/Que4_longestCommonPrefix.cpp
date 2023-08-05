


// Approch -> 1: string
// T.C. = O(strs[0]*N) or O(N^2)
// S.C. = O(N)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "" ;
        
        for(int i = 0 ; i < strs[0].size() ; i++){
            char ch = strs[0][i] ;
            for(int j = 1 ; j < strs.size() ; j++){
                if(strs[j][i] != ch) return ans ;
            }
            ans += ch ;
        }

        return ans ;
    }
};