// GFG
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1



// Approch - 1 Brute Force approch using two for loop
// T.C. = O(N^2) 
// S.C. = O(1)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //int ans ;
        
        for(int i=1 ; i<n ; i++){
            
            if(M[0][i] == 1){
                
                bool flag = true ;
                // column check
                for(int j=0 ; j<n ; j++){
                    if(M[j][i] == 0 && i != j){
                        flag = false ;
                        break ;
                    }
                }
                
                if(flag){
                    // row check
                    for(int j=0 ; j<n ; j++){
                        if(M[i][j] == 1){
                            flag = false ;
                            break ;
                        }
                    }
                }
                
                if(flag)
                    return i ;
            }
        }
        
        // check for 0th person
        bool flag = true ;
        for(int i=1 ; i<n ; i++){
            if(M[0][i] != 0 || M[i][0] != 1){
                flag = false ;
                break ;
            }
        }
        
        if(flag) return 0 ;
        
        return -1 ;
    }
};




// Approch - 2 Using Stack
// T.C. = O(N)
// S.C. = O(N)
class Solution 
{
    bool knows(vector<vector<int> >& M, int A, int B){
        if(M[A][B] == 1)
            return true ;
        
        return false ;
    }
    
    public:

    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s ;
        
        // step -> 1: put all the person inside the stack
        for(int i=0 ; i<n ; i++){
            s.push(i) ;
        }
        
        // step -> 2: take out two peron from stack 
        while(s.size() > 1){
            int A = s.top() ;
            s.pop() ;
            
            int B = s.top() ;
            s.pop() ;
            
            if(knows(M, A, B)){ // knows(M, A, B)  A konws B 
                s.push(B) ;
            }else{
                s.push(A) ;
            }
        }
        
        // step -> 3: One element remain in stack i.e. potential celebrity
        int potentialCelebrity = s.top() ;
        
        for(int i=0 ; i<n ;  i++){
            // to verify for this candidate row check and col check
            if(M[potentialCelebrity][i] != 0 || (M[i][potentialCelebrity] != 1 && potentialCelebrity != i) )
                return -1 ;
        }
        
        return potentialCelebrity ;
    }
};

