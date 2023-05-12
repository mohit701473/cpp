
// S.C. = O(k) 

// method-1 long method
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    void swap(int &a, int &b){
        int temp = a ;
        a = b ;
        b = temp ;
        
    }
    
    void heapify(int arr[], int i, int size){
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
    
    void insert(int arr[], int i, int size){
        int parent = (i-1) / 2 ;
        
        while(i>=0){
            int parent = (i-1) / 2 ;
            if(arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]) ;
                i = parent ;
            }
            
            else break ;
        }
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        
        int size = k ; // this is the size of the heap array
        
        // step -> 1  Convert first K element into MAX heap
        for(int i=size/2-1 ; i>=0 ; i--){
            // to convert into MAX heap Call heapify function
            heapify(arr, i, size) ;  
        }
        
        
        // step -> 2  for remaining elements if element < heap.top() then do two things 1st heap.pop() & 2nd heap.push(element)
        for(int i=k ; i<=r ; i++){
            if(arr[i] < arr[0]) {
                
                // 1st -> heap.pop()  that means delete top element form heap
                swap(arr[0], arr[size-1]) ;  // here we can also do this arr[0] = arr[size-1]  but by this our data at index 0 will be losted so we don't do this  
                size-- ;  // deletion of element form heap has reduce the size of teh heap
                heapify(arr, 0, size) ;
                
                // 2nd -> heap.push(arr[i])  that mean insert arr[i] into heap
                size++ ;
                swap(arr[i], arr[size-1]) ;
                insert(arr, size-1, size) ;
            }
        }
        
        return arr[0] ;
    }
};


// method-2 short method
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq ;
        
        // step -> 1 
        for(int i=0 ; i<k ; i++)
            pq.push(arr[i]) ;
           
        // step -> 2  
        for(int i=k ; i<=r ; i++){
            if(arr[i] < pq.top()){
                pq.pop() ;
                pq.push(arr[i]) ;
            }
        }
        
        return pq.top();
    }
};