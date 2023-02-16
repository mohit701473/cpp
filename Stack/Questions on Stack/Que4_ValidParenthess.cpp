// Valid Parenthess

// T.C. = O(n) 
// S.C. = O(n)
bool isValidParenthesis(string expression)
{
   stack<char> st ;
    
    for(int i=0 ; i<expression.length() ; i++) {
        char ch = expression[i] ;
         // ch is a open brackets then push into stack
        if(ch == '(' || ch =='[' || ch =='{') {
            st.push(ch) ;
        }
        
        // if close brackets then check with stack top element 
        else {
            
            // for checking 1st check that stack is empty or not bzc if stack is empty this give segmentation fault 
            if(!st.empty()) {
                if( (ch==')' && st.top() =='(')  ||
                     (ch==']' && st.top() =='[') ||
                         (ch=='}' && st.top() =='{') ){
                      st.pop() ;
                }
                else{ 
                    return false ;
                }
            }
            else{ 
                return false ;
            }
        }
    }
    
    if(st.empty()) 
        return true ;
    else
        return false ;
}