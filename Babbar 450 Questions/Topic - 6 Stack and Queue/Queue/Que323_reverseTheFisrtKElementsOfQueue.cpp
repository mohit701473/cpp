// GFG -> Reverse First K elements of Queue
https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1



// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(K)
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s ;
    int size = q.size() ;
    
    for(int i=0 ; i<k ; i++){
        s.push(q.front()) ;
        q.pop() ;
    }
    
    while(!s.empty()){
        q.push(s.top()) ;
        s.pop() ;
    }
    
    for(int i=1 ; i<=size-k ; i++){
        q.push(q.front()) ;
        q.pop() ;
    }
    
    return q ;
}