// GFG -> Help Classmates
https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1



// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int> ans(n, -1) ;
        stack<int> s ;
        
        for(int i=n-1 ;i>=0 ; i--){
            if(!s.empty() && s.top() < arr[i]){
                ans[i] = s.top() ;
            }
            else{
                while(!s.empty() && s.top() >= arr[i]){
                    s.pop() ;
                }
                if(!s.empty()){
                    ans[i] = s.top() ;
                }
            }
            s.push(arr[i]) ;
        }
        
        return ans ;
    } 
};



// LeetCode -> 1475. Final Prices With a Special Discount in a Shop
https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size() ;
        vector<int> ans(n) ;
        stack<int> s ;

        for(int i=n-1 ; i>=0 ; i--){
            int itemPrice = prices[i] ;
            if(!s.empty() && s.top() <= prices[i]){
                prices[i] = prices[i] - s.top() ;
            }
            else{
                while(!s.empty() && s.top() > prices[i]){
                    s.pop() ;
                }
                if(!s.empty()){
                    prices[i] = prices[i] - s.top() ;
                }
            }

            s.push(itemPrice) ;
        }

        return prices ;
    }
};