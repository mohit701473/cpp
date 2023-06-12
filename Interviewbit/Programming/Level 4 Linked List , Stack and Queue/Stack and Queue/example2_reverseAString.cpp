https://www.interviewbit.com/problems/reverse-string/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  map + itration
// T.C. = O(N)  N => Length of the string
// S.C. = O(N)
string Solution::reverseString(string A) {
    stack<char> st ;
    
    for(int i=0 ; i<A.length() ; i++)
        st.push(A[i]) ;
        
    for(int i=0 ; i<A.length() ; i++){
        A[i] = st.top() ;
        st.pop() ;
    }
    
    return A ;
}
