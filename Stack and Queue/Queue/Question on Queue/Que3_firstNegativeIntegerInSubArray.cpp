// First negative integer in every window of size k (gfg)


// Approch 1
// T.C. = O((N-K)*K)
// S.C. = O(K)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
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