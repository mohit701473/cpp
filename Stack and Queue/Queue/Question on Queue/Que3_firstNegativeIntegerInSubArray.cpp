// First negative integer in every window of size k (gfg)


// Approch 1
// T.C. = O((N-K)*K)
// S.C. = O(K)
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
                                                 
        vector<long long> v ;
        
        for(long long int i=0 ; i<N-K+1 ; i++){
            bool isNegative = false ;
            for(long long int j= i ; j<i+K ; j++){
                if(A[j] < 0){
                    v.push_back(A[j]) ;
                    isNegative = true ;
                    break ;
                }
            }
            if(!isNegative){
                v.push_back(0) ;
            }
        }
          return v ;                                       
 }


// Approch 2 using doubley ended queue
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(K)

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
                                                 
        deque<long long int> dq ;
        vector<long long> ans ;
        
        // process first K element 
        for(int i=0 ; i<K ; i++){
            if(A[i]<0){
                dq.push_back(i) ;
            }
        }
        
        if(dq.size()>0){
            ans.push_back(A[dq.front()]) ;
        }
        
        else{
            ans.push_back(0) ;
        }
        
        // process remaining element 
        for(int i=K ; i<N ; i++){
            
            // Removal 
            if(!dq.empty() && i - dq.front() >= K){
                dq.pop_front() ;
            }
            
            // Addition
            if(A[i]<0){
                dq.push_back(i) ;
            }
            
            // Store ans 
            if(dq.size()>0){
                ans.push_back(A[dq.front()]) ;
            }
            
            else{
                ans.push_back(0) ;
            }
        }
        
        return ans ;                                        
 }

