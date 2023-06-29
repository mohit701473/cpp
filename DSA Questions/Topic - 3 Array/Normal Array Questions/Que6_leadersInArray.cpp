// GFG -> Leaders in an array
https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1


// Approch -> 1:
// T.C. = O(N)
// S.C. = O(N) to store the ans 
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        
        int rightMax = -1;
        vector<int> ans ;
        
        for(int i=n-1 ; i>=0 ; i--){
            
            if(a[i] >= rightMax){
                ans.push_back(a[i]) ;
                rightMax = a[i] ;
            }
        }
        
        reverse(ans.begin(), ans.end()) ;
        
        return ans ;
    }
};