// LeetCode -> 32. Longest Valid Parentheses
https://leetcode.com/problems/longest-valid-parentheses/description/




// Approch -> 1: Using Two Stack
// T.C. = O(N)
// S.C. = O(2N)
/*
Algo => We take two stack 1st charStack & 2nd indexStack
        charStack store the open brackets and indexStack store the index of the open brackets & index of the closed bracket when charSatk is empty

        We traverse entire string and while traversing the string every time check three conditions 
        1st condition -> if open bracket then push it into charSatck and also push its index into indexStack
        2nd condition -> if closed bracket then check if charStack is not empty the pop from charStack & indexStack and update the len
        3rd condition -> if closed bracket and charStack is empty then only push the index into the indexStack
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0 ;
        stack<char> charStack ;
        stack<int> indexStack ;
        indexStack.push(-1) ;
        
        for(int i=0 ; i<s.length() ; i++){
            char ch = s[i] ;
            
            // 1st condition
            if(ch == '('){
                charStack.push(ch) ;
                indexStack.push(i) ;
            }
            
            // closed bracket
            else{
                // 2nd condition
                if(!charStack.empty()){
                    charStack.pop() ;
                    indexStack.pop() ;
                    // update the len
                    len = max(len, i-indexStack.top()) ;
                }
                
                // 3rd condition
                else indexStack.push(i) ;
            }

        }
        return len ;
    }
};






// Approch -> 2: Using One Stack
// T.C. = O(N)
// S.C. = O(N)
class Solution {
  public:
    int findMaxLen(string s) {
        
        int len = 0 ;
        stack<int> indexStack ;
        indexStack.push(-1) ;
        
        for(int i=0 ; i<s.length() ; i++){
            char ch = s[i] ;
            
            if(ch == '('){
                // charStack.push(ch) ;
                indexStack.push(i) ;
            }
            
            else{
                indexStack.pop() ;
                
                if(indexStack.empty())
                    indexStack.push(i) ;
                else
                    len = max(len, i-indexStack.top()) ;
            }
        }
        return len ;
    }
};





// Approch -> 3: Two Pointer Approch
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0, n = s.size();
 
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                ans = max(ans, 2 * right);
            else if(right > left)
                left = right = 0;
        }
    
        left = right = 0;
    
        for(int i = n - 1; i >= 0; --i){
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                ans = max(ans, 2 * right);
            else if(left > right)
                left = right = 0;
        }
    
        return ans;
    }
};