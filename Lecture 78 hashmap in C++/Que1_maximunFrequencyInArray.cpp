// Que1
/*
Given an array Arr of size N, the array contains numbers in range from 0 to K-1 where K is a positive integer and K <= N. Find the maximum repeating number in this array. If there are two or more maximum repeating numbers return the element having least index.
*/ 

// T.C. = O(nlog(n))
class Solution{
public:	
	// Returns maximum repeating element in arr[0..n-1].
	// The array elements are in range from 0 to k-1
	int maxRepeating(int *arr, int n, int k) {
	    
	    int maxFreq = 0 ;
	    int maxAns = 0 ;
	    
	    map<int, int> count ;
	 
	    for(int i=0; i<n ; i++){
	        count[arr[i]]++ ;
	        maxFreq = max(maxFreq, count[arr[i]]) ;
	    }
	    
	    for(int i=0 ; i<n ; i++){
	        if(maxFreq == count[arr[i]]) {
	            maxAns = arr[i] ;
	            break ;
	        }
	    }
	    
	    return maxAns ;
	}

};


// Que2
/*
Given an array Arr of size N, the array contains numbers in range from 0 to K-1 where K is a positive integer and K <= N. Find the maximum repeating number in this array. If there are two or more maximum repeating numbers return the element having least value.
*/ 

// T.C. = O(nlog(n))
class Solution{
public:	
	// Returns maximum repeating element in arr[0..n-1].
	// The array elements are in range from 0 to k-1
	int maxRepeating(int *arr, int n, int k) {
	    
	    int maxFreq = 0 ;
	    int maxAns = 0 ;
	    
	    map<int, int> count ;
	 
	    for(int i=0; i<n ; i++){
	        count[arr[i]]++ ;
	        maxFreq = max(maxFreq, count[arr[i]]) ;
	    }
	    
	    for(auto i: count){
	        if(maxFreq == i.second) {
	            maxAns = i.first ;
	            break ;
	        }
	    }
	    
	    return maxAns ;
	}

};

// T.C. = O(n)
class Solution{
public:	
	// Returns maximum repeating element in arr[0..n-1].
	// The array elements are in range from 0 to k-1
	int maxRepeating(int *arr, int n, int k) {
	    
	    int maxFreq = 0 ;
	    int maxAns = INT_MAX ;
	    
	    unordered_map<int, int> count ;
	 
	    for(int i=0; i<n ; i++){
	        count[arr[i]]++ ;
	        maxFreq = max(maxFreq, count[arr[i]]) ;
	    }
	    
	    for(auto i: count){
	        if(maxFreq == i.second && i.first < maxAns) {
	            maxAns = i.first ;
	        }
	    }
	    
	    return maxAns ;
	}

};