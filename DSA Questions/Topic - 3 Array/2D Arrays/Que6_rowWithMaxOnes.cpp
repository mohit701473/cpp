// GFG -> Row with max 1s
https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1



// Approch -> 1: Brute Force Approch 
/*
Check every row one by one and count ones in every row and update the ans accordingly
*/
// T.C. = O(N*M)
// S.C. = O(1)
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1 , maxOnes = 0 ;
	    
	    for(int i=0 ; i<n ; i++){
	        int oneCount = 0 ;
	        // Count ones in every row
	        for(int j=0 ; j<m ; j++){
	            if(arr[i][j] == 1) oneCount++ ;
	        }

            // update the ans 
	        if(oneCount > maxOnes){
	            maxOnes = oneCount ;
	            ans = i ;
	        }
	    }
	    
	    return ans ;
	}

};






// Approch -> 1: Binary Search
/*
Given that every row of matrix is sorted so we can apply binary search. By the BS we find the 1st one in every row
such that just before this one their should be a zero
*/
// T.C. = O(Nlog(M))
// S.C. = O(1)
class Solution{
    
    int getOnesColumnInRow(vector<vector<int> > arr, int i, int m){
        
        int s = 0 , e = m-1 ;
        // Apply BS on i-th row to find 1st ones column
        while(s<=e){
            int mid = s + (e-s)/2 ;
            
            if((mid == 0 && arr[i][0] == 1 )|| (arr[i][mid-1] == 0 && arr[i][mid] == 1)){
                return mid ;
            }
            else if(arr[i][mid] == 1 && arr[i][mid-1] == 1){
                e = mid - 1 ; 
            }
            else s = mid + 1;
        }
        
        return -1 ;
    }
    
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1 , onesCol = INT_MAX ;
	    
	    for(int i=0 ; i<n ; i++){
	        
	        int col = getOnesColumnInRow(arr, i, m) ;
            // comare teh column and update the ans
	        if(col != -1 && col < onesCol){
	            onesCol = col ;
	            ans = i ;
	        }
	    }
	    
	    return ans ;
	}

};




// Approch -> 3: Most Optimized Approch
/*
Approach to follow:
To solve in O(N + M) start from the top right corner of the matrix and keep 
Track of the index of the row which has maximum 1s. 
Go left if you encounter 1
Go down if you encounter 0
Stop when you reach the last row or first column. 
*/
// T.C. = O(N+M)
// S.C. = O(1)
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    
	    int i=0,j=m-1,ans=-1;
	    
	    while(i<n && j>=0){
	        
	        if(arr[i][j]==1){
			   ans=i;
	            j--;
	        }
	        
	        if(arr[i][j]==0){
	            i++;
	        }
	   }
	    return ans;
	}

};