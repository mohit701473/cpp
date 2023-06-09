https://www.interviewbit.com/problems/generate-all-parentheses/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  map + itration
// T.C. = O(N)  N => Length of the string
// S.C. = O(N)
int Solution::isValid(string A) {
    stack<char> st ;
    // st.push('#') ;
    //int i=0 ;
    for(int i=0 ; i<A.length() ; i++){
        char ch = A[i] ;
        
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch) ;
        }
        
        else {
            if(!st.empty() && ((ch == ')' && st.top() == '(') || (ch == ']' && st.top() == '[') || (ch == '}' && st.top() == '{')) ){
                st.pop() ;
            }
            else return 0 ;
        }
    }
    
    if(!st.empty()) return 0 ;
    return 1 ;
}
