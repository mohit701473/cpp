https://www.interviewbit.com/problems/balanced-parantheses/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  map + itration
// T.C. = O(N)  N => Length of the string
// S.C. = O(N)
int Solution::solve(string A) {
    stack<char> st ;
    
    for(int i=0 ; i<A.size() ; i++){
        char ch = A[i] ;
        
        if(ch == '(')
            st.push(ch) ;
            
        else{
            if(!st.empty())
                st.pop() ;
                
            else return 0 ;
        }
    }
    
    if(!st.empty())
        return 0 ;
        
    return 1 ;
}
