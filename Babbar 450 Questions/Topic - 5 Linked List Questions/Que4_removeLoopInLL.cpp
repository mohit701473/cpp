// GFG ->  Remove loop in Linked List

// Approch - 1 usine Map
// T.C. = O(N) 
// S.C. = O(N)
class Solution
{
    public:
   
    void removeLoop(Node* head)
    {
        if(head == NULL || head -> next == NULL)
            return ;
            
        unordered_map<Node*, bool> m ;
        Node* temp = head ;
        Node* prev = NULL ;
        
        while(temp != NULL){
            if(m[temp] != false){
                prev -> next = NULL ;
                return ;
            }
            
            m[temp] = true ;
            prev = temp ;
            temp = temp -> next ;
        }
            
        return ;
    }
};




// Approch - 2
// T.C. = O(N) 
// S.C. = O(1)
class Solution
{
    public:
    
    Node* floydCycleDetection(Node* head)
    {
        
        if(head == NULL || head -> next == NULL) {
            return NULL ;
        }
        
        Node* slow = head ;
        Node* fast = head ;
        
        do {
            slow = slow -> next ;
            fast = fast -> next -> next ;
            
            if(fast == NULL || fast -> next == NULL) {
                return NULL ;
            }
        }while(slow != fast) ;
        
        return slow ;
    }
    
    
    void removeLoop(Node* head)
    {
        if(head == NULL || head -> next == NULL) {
            return ;
        }
        // just remove the loop without losing any nodes
  
        Node* curr = head ;
        Node* prev = NULL ;
        Node* temp = floydCycleDetection(head) ;
        
        if(temp == NULL) {
            return ;
        }
        
        if(curr != temp) {
            while(curr != temp) {
                curr = curr -> next ;
                prev = temp ;
                temp = temp -> next ;
            }
            
            prev -> next = NULL ;
        }
        
        else {
            do {
                prev = temp ;
                temp = temp -> next ;
            }while(temp != curr) ;
            
            prev -> next = NULL ;
        }
        
        return ;
    }
};





// Approch - 3
// T.C. = O(N) 
// S.C. = O(1)
class Solution
{
    public:
    
    Node* floydCycleDetection(Node* head)
    {
        
        if(head == NULL || head -> next == NULL) {
            return NULL ;
        }
        
        Node* slow = head ;
        Node* fast = head ;
        
        do {
            slow = slow -> next ;
            fast = fast -> next -> next ;
            
            if(fast == NULL || fast -> next == NULL) {
                return NULL ;
            }
        }while(slow != fast) ;
        
        return slow ;
    }
    
    
    Node* getStartingNodeOfLoop(Node* head){
        
        if(head == NULL || head -> next == NULL)
            return NULL ;

        Node* slow = head ;
        Node* fast = floydCycleDetection(head) ;

        if(fast == NULL)    return NULL ;

        while(slow != fast){
            slow = slow -> next ;
            fast = fast -> next ;
        }

        return slow ;
    }
    
    
    void removeLoop(Node* head)
    {
        if(head == NULL || head -> next == NULL) {
            return ;
        }
        
        Node* startingNode = getStartingNodeOfLoop(head) ;
        Node* temp = startingNode ;
        
        if(startingNode == NULL) return ;
        
        do{
            temp = temp -> next ;
        }while(temp -> next != startingNode) ;
        
        temp -> next = NULL ;
        
    }
};

