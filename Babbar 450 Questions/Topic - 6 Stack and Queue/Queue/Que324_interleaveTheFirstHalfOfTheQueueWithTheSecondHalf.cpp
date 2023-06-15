// Code Studio -> Interleave The First Half Of The Queue With The Second Half
https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=0



// Approch - 1 using additional vector
// T.C. = O(N)
// S.C. = O(N)
void interLeaveQueue(queue < int > & q) {
    vector<int> v ;

    while(!q.empty()){
        v.push_back(q.front()) ;
        q.pop() ;
    }
    
    int n = v.size() ;
    for(int i=0 ; i<n/2 ; i++){
        q.push(v[i]) ;
        q.push(v[i+n/2]) ;
    }
}