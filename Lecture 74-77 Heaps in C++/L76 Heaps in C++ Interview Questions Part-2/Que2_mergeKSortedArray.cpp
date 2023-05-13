// Merge k Sorted Arrays

// T.C. = O(N*KlogK)
// S.C. = O(N*K)
class Solution
{
    public:
    class Node{
        public:
        int data ;
        int i ;  // row no. of an element in 2D matrix vector<vector<int>> arr
        int j ; //  column no. of an element in 2D matrix vector<vector<int>> arr
        
        // constructor
        Node(int data, int row, int col){
            this -> data = data ;
            this -> i = row ;
            this -> j = col ;
        }
    };
    
    class compare{
        public:
        bool operator() (Node* a, Node* b){
            return a -> data > b -> data ;
        }
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node* , vector<Node*> , compare> minHeap ; // Creating a coustom Min Heap data structure
        
        // step -> 1 Insert the first element of all the K aarays into minHeap
        for(int i=0 ; i<K ; i++){  // T.C. = O(K)
            Node* temp = new Node(arr[i][0], i, 0) ;
            minHeap.push(temp) ;
        }
        
        vector<int> ans ;
        
        // step -> 2 insert minHeap.to() into ans array until we are not traverse all the element in given 2D vector
        // now remainig element to be traversed = N*K - K [ N*K = total element & K elments are above traversed] but is similira to the N*K
        // T.C. = O(N*KlogK)
        while(!minHeap.empty()){ // by this we traverse all the elements
            
            Node* temp = minHeap.top() ;
            
            ans.push_back(temp -> data) ;
            minHeap.pop() ;
            
            // Now hum ne jis array se ye element liya h uska next element minHeap m dalna h if element present in that array
            int i = temp -> i ;
            int j = temp -> j ;
            
            if(j+1 < arr[i].size()){ // j+1 < arr[i].size()  eska mtlb h ki ith array m next element present hai
                
                // now element is present so insert it into minHeap
                Node* next = new Node(arr[i][j+1], i, j+1) ;
                minHeap.push(next) ;
            }
            
        }
        
        return ans ;
    }
    
};