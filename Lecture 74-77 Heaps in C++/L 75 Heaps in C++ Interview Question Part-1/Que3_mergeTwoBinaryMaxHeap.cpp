
// Approch 1
// T.C. = O(m+n) 
// S.C. = O(m+n) 
class Solution{
    
    void swap(int &a, int &b){
        int temp = a ;
        a = b ;
        b = temp ;
        
    }
    
    void heapify(vector<int> &arr , int i, int size){
        int largest = i ;
        int left = 2*i + 1 ;
        int right = 2*i + 2 ;
        
        if(left < size && arr[left] > arr[largest])
            largest = left ;
            
        if(right < size && arr[right] > arr[largest])
            largest = right ;
            
        if(largest != i){
            swap(arr[i], arr[largest]) ;
            heapify(arr, largest, size) ;
        }
    }
    
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans ;
        for(int i=0 ; i<n ; i++){
            ans.push_back(a[i]) ;
        }
        
        for(int i=0 ; i<m ; i++){
            ans.push_back(b[i]) ;
        }
        
        int size = m+n ;
        for(int i=(size/2)-1 ; i>=0 ; i--){
            heapify(ans, i, size) ; 
        }
        
        return ans ;
    }
};