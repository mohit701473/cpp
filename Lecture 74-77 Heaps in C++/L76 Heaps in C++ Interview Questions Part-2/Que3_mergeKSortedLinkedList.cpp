// Merge K sorted linked lists


// T.C. = O(N*K*log(K))  bcz while loop runs N*K times and inside the while loop push or pop operation of minHeap take log(K) time
// S.C. = O(K) this space is required by the Min Heap 
class Solution{
  public:
  
    class compare{
        public:
        bool operator() (Node* a, Node* b){
            return a -> data > b -> data ;
        }
    };
  
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        // step -> 1  create a Linked List and insert first  element of K LL
        priority_queue<Node *, vector<Node *>, compare > minHeap ;  // Initializing minHeap 
        
        // insertting first elements of K sorted LL into minHeap
        for(int i=0 ; i<K ; i++){
            if(arr[i] != NULL)
                minHeap.push(arr[i]) ;
        }
        
        Node* head = NULL ; // This head will work as the head of the final Merged K sorted linked lists's head
        Node* tail = NULL ; // This tail will work as the head of the final Merged K sorted linked lists's tail
        
        // step -> 2  Now at this step we traverse all the remaining elements of the K LL 
        while(minHeap.size() > 0){
            Node* top = minHeap.top() ;
            minHeap.pop() ;
            
            // inserting an element ans LL 
            if(head == NULL){ 
                head = tail = top ; 
            }
            
            else{
                tail -> next = top ;
                tail = top ;
            }
            
            if(top -> next != NULL)
                minHeap.push(top -> next) ;  // inserting an element into min Heap
        }
        
        return head ;
    }
};