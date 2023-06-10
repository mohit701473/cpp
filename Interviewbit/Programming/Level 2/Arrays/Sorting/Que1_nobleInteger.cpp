https://www.interviewbit.com/courses/programming/arrays


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------

// Approch - 1  
// T.C. = O(N) 
// S.C. = O(1) 
int Solution::solve(vector<int> &A) {
    
    sort(A.begin(), A.end()) ;
    
    int size = A.size() ;
    for(int i=0 ; i<size ; i++){
        int element = A[i] ;
        
        if(element == (size-1-i) && i+1< size && element != A[i+1])
            return 1 ;
    }
    if(A[size -1] == 0)
        return 1 ;
    return -1 ;
}
