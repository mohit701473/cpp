// Next Smaller Element

// Apporach 1 : Using loop 
// T.C. = O(n^2) 
// S.C. = O(n) bcz we create an ans vector
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    int len = arr.size() ;
    vector<int> ans(len, -1) ;
    
    for(int i=0 ; i<len ; i++) {
        int val = arr[i] ;
        for(int j=i ; j<len ;j++) {
            if(arr[j] < val) {
                ans[i] = arr[j] ;
                break ;
            }
        }
    }
    
    return ans ;
}


// Apporach 2 : using stack
// T.C. = O(n) 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    int len = arr.size() ;
    stack<int> s ;
    s.push(-1) ;
    
    vector<int> ans(len, -1) ;
    
    for(int i = len-1 ; i >=0 ; i--) {
    
        if(s.top() < arr[i]) {
            ans[i] = s.top() ;
            s.push(arr[i]) ;
        }
        
        else {
            while(s.top() >= arr[i]) {
                s.pop() ;
            }
            ans[i] = s.top() ;
            s.push(arr[i]) ;
        }
    }
    
    return ans ;
}


