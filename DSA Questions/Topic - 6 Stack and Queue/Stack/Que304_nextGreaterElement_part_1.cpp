// GFG
https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(N)
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack<long long> s ;
        s.push(-1) ;
        
        vector<long long> ans(n, -1) ;
        
        for(int i = n-1 ; i >=0 ; i--) {
        
            if(s.top() > arr[i]){
                ans[i] = s.top() ;
                s.push(arr[i]) ;
            }
            else{
                while(s.size() != 1 && s.top() <= arr[i]) {
                    s.pop() ;
                }
                
                ans[i] = s.top() ;
                s.push(arr[i]) ;
            }
        }
        
        return ans ;
    }
};

