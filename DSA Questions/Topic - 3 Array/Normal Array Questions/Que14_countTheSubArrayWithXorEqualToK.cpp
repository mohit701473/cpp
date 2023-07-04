// InterviewBit -> Subarray with given XOR
https://www.interviewbit.com/problems/subarray-with-given-xor/



// Approch -> 1: Brute Force Approch 
// T.C. = O(N^2)
// S.C. = O(1)
int Solution::solve(vector<int> &A, int B) {

    int count = 0, n = A.size() ;
    
    for(int i=0 ; i<n ; i++){
        int xr = 0 ;
        for(int j=i ; j<n ; j++){
            xr ^= A[j] ;
            if(xr == B) count++ ;
        }
    }
    
    return count ;
}



// Approch -> 2: Using Hash Map
// T.C. = O(N)
// S.C. = O(N)
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size(), count = 0, xr = 0, K = B ;
    unordered_map<int, int> prevXor ;
    prevXor[0]++ ;
    
    for(int i=0 ; i<n ; i++){
        xr ^= A[i] ;
        
        int x = xr^K ;
        if(prevXor.find(x) != prevXor.end()) count += prevXor[x] ;
        
        prevXor[xr]++ ;
    }
    
    return count ;
}
