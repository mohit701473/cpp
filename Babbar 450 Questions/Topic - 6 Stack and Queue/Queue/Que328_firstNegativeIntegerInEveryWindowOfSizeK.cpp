// GFG -> First negative integer in every window of size k
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1


// Approch - 1 using queue + sliding window approch
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(K)
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K){
    
    vector<long long int > ans ;
    queue<long long int> q ;
    
    // step -> 1: insert the indexes of negative integer of first K size sub array into queue
    for(long long int i=0 ; i<K ; i++){
        if(A[i] < 0)
            q.push(i) ;
    }
    
    if(!q.empty()){
        ans.push_back(A[q.front()]) ;
    }else{
        ans.push_back(0) ;
    }
    
    // step -> 2: now process on remaining elements 
    for(int i=K ; i<N ; i++){
        
        // Removal -> if q.top() index's element not comes inside the next K window so pop this index
        if(!q.empty() && q.front() <= i-K) 
            q.pop() ;
            
        // Addition -> if A[i] is a negative integer then insert this index in queue
        if(A[i] < 0)
            q.push(i) ;
            
        // Store ans -> now if negative integer is present in K size window then insert it in ans array
        if(!q.empty()){
            ans.push_back(A[q.front()]) ;
        }else{
            ans.push_back(0) ;
        }
    }
    
    return ans ;
} 




// Approch - 2 using dqueue + sliding window approch
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