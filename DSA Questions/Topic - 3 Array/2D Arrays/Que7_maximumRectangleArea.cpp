// GFG -> Max rectangle
https://practice.geeksforgeeks.org/problems/max-rectangle/1




// Max rectangle gfg 

// Approch 1: Similear to largest histogram area + previous smaller & next smaller element concept
// Expected Time Complexity : O(n*m)
// Expected Auixiliary Space : O(m)
class Solution{
  public:
  
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }


    int largestRectangleArea(vector<int>& heights) {
         int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }

  
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        vector<vector<int>> mat ;
        int max_area = 0 ;
        
        
        for(int i=0 ; i<n ; i++){
            vector<int> temp ;
            for(int j=0 ; j<m ; j++){
                temp.push_back(M[i][j]) ;
                
            }
            mat.push_back(temp) ;
        }
        
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ; j++){
                if(i != 0){
                    if(mat[i][j] == 0)
                        mat[i][j] = 0 ;
                        
                    else
                        mat[i][j] = mat[i][j] + mat[i-1][j] ;
                }
            }
        }
        
        
        for(int i=0 ; i<n ; i++){
            int new_area = largestRectangleArea(mat[i]) ;
            if(new_area > max_area)
                max_area = new_area ;
        }
        
        return max_area ;
        
    }
};


// Approch 2
// Time Limit Exced
class Solution{
  public:
  
    int largestRectangleArea(vector<int> &heights) {
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

  
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        vector<vector<int>> mat ;
        int max_area = 0 ;
        
        
        for(int i=0 ; i<n ; i++){
            vector<int> temp ;
            for(int j=0 ; j<m ; j++){
                temp.push_back(M[i][j]) ;
                
            }
            mat.push_back(temp) ;
        }
        
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ; j++){
                if(i != 0){
                    if(mat[i][j] == 0)
                        mat[i][j] = 0 ;
                        
                    else
                        mat[i][j] = mat[i][j] + mat[i-1][j] ;
                }
            }
        }
        
        
        for(int i=0 ; i<n ; i++){
            int new_area = largestRectangleArea(mat[i]) ;
            if(new_area > max_area)
                max_area = new_area ;
        }
        
        return max_area ;
        
    }
};

