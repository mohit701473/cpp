// Next Greater Element

// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(N)
vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        // int len = arr.size() ;
        stack<long long> s ;
        s.push(-1) ;
        
        vector<long long> ans(n, -1) ;
        
        for(int i = n-1 ; i >=0 ; i--) {
        
            if(s.top() > arr[i]) {
                ans[i] = s.top() ;
                s.push(arr[i]) ;
            }
            
            else {
                while(!s.empty() && s.top() <= arr[i]) {
                    s.pop() ;
                }
                
                if(s.empty()) {
                    s.push(-1) ;
                    ans[i] = s.top() ;
                }
                
                ans[i] = s.top() ;
                s.push(arr[i]) ;
            }
        }
        
        return ans ;
    }