https://leetcode.com/problems/valid-parentheses/



// Expected Time Complexity: O(N)
// Expected Auixilliary Space: O(N)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk ;

        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stk.push(s[i]) ;
            }

            else{
                if(stk.empty())
                    return false ;
                    
                char close = stk.top() ;
                if((s[i] == ')' && close == '(') || (s[i] == ']' && close == '[') || (s[i] == '}' && close == '{')) {
                    stk.pop() ;
                }

                else{
                    return false ;
                }
            }
        }

        if(!stk.empty())
            return false ;

        return true ;
    }
};