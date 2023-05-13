// Smallest range in K lists


// Expected Time Complexity : O(n * k *log k)
// Expected Auxilliary Space  : O(k)
class Solution{
    public:
    
    
    class Node{
        public:
        int data ;
        int i ;  // this will point to the row of the data 
        int j ;  // this will point ot the col of the data
        
        // constructor
        Node(int data, int row, int col){
            this -> data = data ;
            this -> i = row ;
            this -> j = col ;
        }
    };
    
    class compare{
        public:
        bool operator() (Node* a, Node* b) {
            return a -> data > b -> data ;
        }
    };
    
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        // step -> 1
        int mini = INT_MAX, maxi = INT_MIN ;
        
        // step -> 2 creating a minHeap(pq) and inserting the first elements of all the K sorted List while inserting these K elment we trak the mximum element into maxi 
        priority_queue<Node*, vector<Node*> , compare> pq ;
        
        for(int i=0 ; i< k ; i++){
            // insert into minHeap
            Node* temp = new Node(KSortedArray[i][0], i, 0) ;
            pq.push(temp) ;
            
            mini = min(mini, KSortedArray[i][0]) ;
            maxi = max(maxi, KSortedArray[i][0]) ;
            
        }
        
        
        pair<int, int> ans ;
        ans.first = mini ;
        ans.second = maxi ;
        
        // step -> 3 
        while(!pq.empty()){
            
            Node* min = pq.top() ;
            pq.pop() ;
            
            mini = min -> data ;
            
            // Update ans 
            if(maxi - mini < ans.second - ans.first){
                ans.first = mini ;
                ans.second = maxi ;
            }
            
            // update maxi & insert the next element of the mini into heap if exist
            if((min -> j) + 1 < n){  // min -> j + 1 gives the next column
                
                int row = min -> i ;
                int col = (min -> j) + 1 ;
                
                // update maxi
                maxi = max(maxi, KSortedArray[row][col]) ;
                
                // update heap 
                Node* temp = new Node(KSortedArray[row][col], row, col) ;
                pq.push(temp) ;
            }
            
            else break ;
        }
         
        return ans ;
    }
};

