// GFG -> Stack Permutations
https://practice.geeksforgeeks.org/problems/stack-permutations/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


// LeetCode -> 946. Validate Stack Sequences
https://leetcode.com/problems/validate-stack-sequences/description/




// T.C. = O(N)
// S.C. = O(N)
class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        stack<int> s ;
        int j=0 ;
        
        for(int i=0 ; i<N ; i++){
            s.push(A[i]) ;
            
            while(!s.empty() && s.top() == B[j]){
                s.pop() ;
                j++ ;
            }
        }
        
        return s.empty() ;
    }
};