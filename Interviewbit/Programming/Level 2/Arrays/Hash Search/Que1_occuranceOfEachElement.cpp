https://www.interviewbit.com/problems/occurence-of-each-number/




//------------------------------------------------------------   Solution    ----------------------------------------------------------------------

// Approch - 1  
// T.C. = O(Nlog(N)) 
// S.C. = O(N) 
vector<int> Solution::findOccurences(vector<int> &A) {
    
    map<int, int> m ;
    
    for(int i=0 ; i<A.size() ; i++)
        m[A[i]]++ ;
    
    vector<int> ans ;
    
    for(auto it: m)
        ans.push_back(it.second) ;
        
    return ans ;
}