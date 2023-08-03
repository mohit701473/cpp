// LeetCode -> 1021. Remove Outermost Parentheses
https://leetcode.com/problems/remove-outermost-parentheses/description/



// Approch -> 1: String + Stack
// T.C. = O(N) 
// S.C. = O(2N) -> temp + ans string
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "" ;
        stack<char> st ;
        string temp = "" ;
        int i = 0 ;
        while(i<s.size()){
            if(s[i] == '('){
                if(st.size() >= 1) temp += '(' ;
                st.push('(') ;
            }
            else{
                st.pop() ;
                if(!st.empty()){
                    temp += ')' ;
                }
                else{
                    ans += temp ;
                    temp = "" ;
                }
            }
            i++ ;
        }
        return ans ;
    }
};