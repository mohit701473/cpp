// Largest rectangle in a histogram

// T.C. = O(n^2) 
// S.C. = O(1)
// Apporach 1 :  brute force algorithm
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int area = 0 ;
     int n = heights.size() ;
     
     for(int i = 0 ; i < n ; i++) {
         
         int left = i , right = i , l = 0 , r = 1 ;
         
         while(left >= 0 && heights[i] <= heights[left]){
            if(left < i){
                l++ ;
             }
             left-- ;
         }
         
         while(right < n && heights[i] <= heights[right]){
             if(right > i){
                r++ ;
             }
             right++ ;
         }
         
         area = max(area , (heights[i] * (l+r))) ;
     }
     
     return area ;
}



private:
    
    vector<long long> nextSmallerElemenet(long long arr[] , int n){
        
        stack<int> s ;
        s.push(-1) ;
        
        vector<long long> ans(n) ;
        
        for(int i = n-1 ; i >=0 ; i--) {
        
            long long  curr = arr[i] ;
            
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop() ;
            }
            
            ans[i] = s.top() ;
            s.push(i) ;
    }
    return ans ;
}

vector<long long> prevSmallerElemenet(long long arr[] , int n){
    
    stack<int> s ;
        s.push(-1) ;
        
        vector<long long> ans(n) ;
        
        for(int i = 0 ; i < n ; i--) {
        
            long long  curr = arr[i] ;
            
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop() ;
            }
            
            ans[i] = s.top() ;
            s.push(i) ;
    }
    return ans ;
    
}
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // extern vector<long long> prevSmallerElemenet(long long arr[] , int n) ;
        // extern vector<long long> nextSmallerElemenet(long long arr[] , int n) ;
    
        vector<long long> next(n) ;
        next = nextSmallerElemenet(arr , n) ;
        
        vector<long long> prev(n) ; 
        prev = prevSmallerElemenet(arr , n) ;
        
        long long area = -1 ;
        for(int i=0; i<n; i++){
            long long l = arr[i] ;
        
            if(next[i] == -1){
                next[i] = n;
            }
            
            long long b = next[i] - prev[i] - 1;
            
            long long newArea = l*b;
            area = max(area , newArea) ;
        }
        
        return area ;
    }