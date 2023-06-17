// GFG -> Expression contains redundant bracket or not
https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1

/*
Ex. -> a+b+c*(e+f)
output -> no redundant bracket
*/


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

/*
Approch => Our approch is two brackets at least have a single operator(+ , - , *, /) and if is not the brackets are redundant

Algo => 
    Step -> 1: traverse entire string i.e apply a for/while loop and when you tarversing the loop check 3 condition
        take ch = s[i]
        1st condition -> if ch == (, + , - , *, / then push ch into stack
        2nd condition -> if ch == ) then check stack top if stack.top() == +, -, *, / then pop() from stack until stack top() != ) and when while loop terminate then if stack is not empty the pop() ")" from stack
        3rd condition -> if ch == ) and stack.top() != +, -, *, / that mean their is a redundant bracket so return 1
*/
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st ;
        
        for(int i=0 ; i<s.length() ; i++){
            char ch = s[i] ;
            
            // 1st condition
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                st.push(ch) ;
            }
            
            // ch == ')'
            else{
                // 2nd condition
                if(ch == ')'){
                    if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/' ){
                        while(st.top() != '('){
                            st.pop() ;
                        }
                        if(!st.empty())
                            st.pop() ;
                    }
                    // 3rd condition
                    else{
                        return 1 ;
                    }
                }
            }
        }
        
        return 0 ;
    }
};