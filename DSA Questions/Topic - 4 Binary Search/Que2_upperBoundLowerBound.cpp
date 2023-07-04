// GFG -> Ceil The Floor
https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1


// Approch -> 1: Linear Search 
// T.C. = O(N)
// S.C. = O(1)
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int floor = -1, ceil = -1 ;
    int miniFloor = INT_MAX, miniCeil = INT_MAX ;
    
    for(int i=0 ; i<n ; i++){
        if(arr[i] == x ) return {x,x} ;
        
        else if(arr[i] < x && x - arr[i] < miniFloor){
            miniFloor = x - arr[i] ;
            floor = arr[i] ;
        }
        
        else if(arr[i] > x && arr[i] - x < miniCeil){
            miniCeil = arr[i] - x ;
            ceil = arr[i] ;
        }
    }
    
    return {floor, ceil} ;
}



// GFG -> Floor in a Sorted Array
https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1


// Approch -> 1: Binary Search
// T.C. = O(log(N))
// S.C. = O(1)
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        int idx = -1, mini = INT_MAX ;
        
        int s = 0 , e = n-1 ;

        while(s<=e){
            int mid = (s+e)/2 ;
            
            if(v[mid] <= x && x-v[mid] < mini){
                mini = x-v[mid] ;
                idx = mid ;
                s = mid +1 ;
            }
            else if(v[mid] > x) e = mid - 1;
            else s = mid + 1 ; // x-v[mid] > mini ;
        }

        return idx ;
        
    }
};