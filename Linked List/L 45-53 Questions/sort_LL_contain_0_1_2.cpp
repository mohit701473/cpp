// Sort Linked List by data replacing
Node* segregate(Node *head) {
        
        // Add code here
        
        if(head == NULL){
            return NULL ;
        }
        
       
        Node* temp = head ;
        int zero_count = 0 ;
        int one_count = 0 ;
        int two_count = 0 ;
        
        while(temp != NULL) {
             
            if(temp -> data == 0) {
                zero_count++ ;
            }
            
            if(temp -> data == 1) {
                one_count++ ;
            }
            
            if(temp -> data == 2) {
                two_count++ ;
            }
            
            temp = temp -> next ;
        }
        
        
         Node* curr = head ;
        
        while(curr != NULL) {
            
            if(zero_count > 0) {
                curr -> data = 0 ;
                // temp = temp -> next ;
                zero_count-- ;
            }
            
            else {
                if(one_count > 0){
                    curr -> data = 1 ;
                    // temp = temp -> next ;
                    one_count-- ;
                }
                
                else if (two_count > 0){
                    curr -> data = 2 ;
                    // temp = temp -> next ;
                    two_count-- ;
                }
            }
            
            curr = curr -> next ;
        }
        
        return head ;
    }

// Sort Linked List which contain only 0s , 1s & 2s without data replacing
// for this we have to create three different LL corsponding to 0 , 1 & 2 and finaly we have to merge them 
void insertAtTail(Node* &tail , int d) {
        Node* temp = new Node(d) ;
        tail -> next = temp ;
        tail = temp ;
    }
    
    Node* segregate(Node *head) {
        
        // Add code here
        
        /* Here we use dummy Node at the starting of the 0 , 1 & 2 LL bzc it reduce our if else 
        condition when we want to merge these three sorted LL */
        Node* zeroHead = new Node(-1) ;
        Node* zeroTail = zeroHead ;
        
        Node* oneHead = new Node(-1) ;
        Node* oneTail = oneHead ;
        
        Node* twoHead = new Node(-1) ;
        Node* twoTail = twoHead ;
        
        Node* curr = head ;
        
        while(curr != NULL) {
            int val = curr -> data ;
            
            if(val == 0) {
                insertAtTail(zeroTail , val) ;
                curr = curr -> next ;
            }
            
            else if(val == 1){
                insertAtTail(oneTail , val) ;
                curr = curr -> next ;
            }
            
            else if(val == 2){
                insertAtTail(twoTail , val) ;
                curr = curr -> next ;
            }
        }
        
        // Merge these LL 
        if(oneHead -> next != NULL) {
            zeroTail -> next = oneHead -> next ;
            oneTail -> next = twoHead -> next ;
        }
        
        else{
            zeroTail -> next = twoHead -> next ;
        }
        
        head = zeroHead -> next ;
        
        delete zeroHead ;
        delete oneHead ;
        delete twohead ;
        
        return head ;
    }