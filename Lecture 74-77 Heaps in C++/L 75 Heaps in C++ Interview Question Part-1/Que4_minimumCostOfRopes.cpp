// Minimum Cost of ropes

// Expected Time Complexity : O(nlogn)
// Expected Auxilliary Space : O(n)
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long> > minHeap ;
        
        for(long long i=0 ; i<n ; i++)
            minHeap.push(arr[i]) ;
            
        long long ans = 0 ;
        while(minHeap.size() > 1){
            long long a = minHeap.top() ;
            minHeap.pop() ;
            
            long long b = minHeap.top() ;
            minHeap.pop() ;
            
            long long sum = a+b ;
            
            ans += sum ;
            
            minHeap.push(sum) ;
            
        }
        
        return ans ;
    }
};