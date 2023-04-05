// Interleave The First Half Of The Queue With The Second Half
// use stack for auxilary spaceS

// Approch 1 
// T.C. = O(n)
// S.C. = O(n)

void interLeaveQueue(queue < int > & q) {
    int n = q.size() ;
    int arr[n] ;

    for(int i=0 ; i<n ; i++){
        arr[i] = q.front() ;
        q.pop() ;
    }

    for (int i = 0; i < n / 2; i++) {
        q.push(arr[i]) ;
        q.push(arr[i+n/2]) ;
    } 

    if(n%2 != 0){
        q.push(arr[n/2]) ;
    }

}

