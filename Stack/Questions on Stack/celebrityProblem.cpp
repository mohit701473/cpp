// The Celebrity Problem


// Approch 1st
// This is the brut force approch
// Expected T.C. = O(n^3) but in gfg this will work in O(n^2)  bcz the use fo break statement 
// Expected S.C. = O(1)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int celebrity_index = -1 ;
        
        for(int i=0 ; i<n ; i++){
             
            for(int j=0 ; j<n ; j++){
                
                if(M[i][j] == 1){
                    celebrity_index = j ;
                   // cout<<"celebrity_index :"<<j<<endl;
                    
                    for(int k=0 ; k<n ; k++){
                        if((M[k][j] == 0 && k != j) || M[j][k] == 1){
                            celebrity_index = -1 ;
                          //  cout<<"celebrity_index :"<< celebrity_index<<endl;
                            break ;
                        }
                    }
                }
                
                if(celebrity_index != -1) 
                    return celebrity_index ;
            }
        }
        
        return celebrity_index ;
        
    }
};


// Approch 2nd
// T.C. = O(n) 
// S.C. = O(n)  bcz we use stck
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        stack<int> s ;
        // Push all person in stack
        for(int i=0 ; i<n ; i++)
            s.push(i) ;
            
        while(s.size() > 1){
            int person_a = s.top() ;
            s.pop() ;
            
            int person_b = s.top() ;
            s.pop() ;
            
            if(M[person_a][person_b] == 0 && M[person_b][person_a] == 1)  // person_b konws person_a
                s.push(person_a) ;
                
            if(M[person_b][person_a] == 0 && M[person_a][person_b] == 1)  // person_a knows person_b
                s.push(person_b) ;
        }
            
        int celebrity_index = -1 ;
        
        if(!s.empty()){
            celebrity_index = s.top() ;
        }
        
        else{
            return -1 ;
        }
        
        for(int i=0 ; i<n ; i++){
            if((M[celebrity_index][i] == 1 || M[i][celebrity_index] == 0) && celebrity_index != i){
                celebrity_index = -1  ;
                break ;
            }
        }
        
        return celebrity_index ;
        
    }
};

