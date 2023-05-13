// K-th Largest Sum Contiguous Subarray


// Approch - 1
// T.C. = O(N^2log(N))
// S.C. = O(N^2)
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        vector<int> sumStore ;
        for(int i=0 ; i<N ; i++){
            
            int sum = 0 ;
            for(int j=i ; j<N ; j++){
                
                sum += Arr[j] ;
                sumStore.push_back(sum) ;
            }
        }
        
        sort(sumStore.begin(), sumStore.end()) ;
        
        return sumStore[sumStore.size() - K] ;
    }
};


// Approch - 2 using priority queue
// T.C. = O(N^2log(K))
// S.C. = O(K)
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int, vector<int>, greater<int> > pq ; // Initializing Min Heap
        
        for(int i=0 ; i<N ; i++){
            
            int sum = 0 ;
            for(int j=i ; j<N ; j++){
                sum += Arr[j] ;
                
                if(pq.size() < K){
                    // Insert sum into min heap
                    pq.push(sum) ;
                }
                else{
                    if(sum > pq.top()){
                        pq.pop() ;
                        pq.push(sum) ;
                    }
                }
            }
        }
        
        return pq.top() ;
    }
};