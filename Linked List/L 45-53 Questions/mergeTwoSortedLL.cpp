//Function to merge two sorted linked list by creating a new LL
Node* sortedMerge(Node* head1, Node* head2)  
{     
    // code here
    
    if(head1 == NULL && head2 == NULL) {
        return NULL ;
    }

    Node* head3 = NULL ;
    Node* tail3 = NULL ;
    Node* temp1 = head1 ;
    Node* temp2 = head2 ;

    while(temp1 != NULL && temp2 != NULL) {
        
        if(temp1 -> data < temp2 -> data){
            
            Node* temp = new Node(temp1 -> data) ;
            if(head3 == NULL && tail3 == NULL) {
                head3 = temp ;
                tail3 = temp ;
            }
        
            else {
                tail3 -> next = temp ;
                tail3 = temp ;
            }
            
            temp1 = temp1 -> next ;
        }

        else {
            
            Node* temp = new Node(temp2 -> data) ;
            if(head3 == NULL && tail3 == NULL) {
                head3 = temp ;
                tail3 = temp ;
            }
        
            else {
                tail3 -> next = temp ;
                tail3 = temp ;
            }
            
            temp2 = temp2 -> next ;
        }
    }

    if(temp1 == NULL) {
        while(temp2 != NULL) {
            
            Node* temp = new Node(temp2 -> data) ;
            if(head3 == NULL && tail3 == NULL) {
                head3 = temp ;
                tail3 = temp ;
            }
        
            else {
                tail3 -> next = temp ;
                tail3 = temp ;
            }
            
            temp2 = temp2 -> next ;
        }
    }

    if(temp2 == NULL) {
        while(temp1 != NULL) {
            
            Node* temp = new Node(temp1 -> data) ;
            if(head3 == NULL && tail3 == NULL) {
                head3 = temp ;
                tail3 = temp ;
            }
        
            else {
                tail3 -> next = temp ;
                tail3 = temp ;
            }
            
            temp1 = temp1 -> next ;
        }
    }

    return head3 ;
 
}  


// function to merge two sorted LL replacing pointer only
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code 
    
    if(head1 == NULL && head2 == NULL) {
        return NULL ;
    }
    
    if(head1 == NULL && head2 != NULL) {
        return head2 ;
    }
    
    if(head1 != NULL && head2 == NULL) {
        return head1 ;
    }
    
    
    Node* temp1 = head1 ;
    Node* temp2 = head2 ;
    Node* prev = NULL ;
    Node* forward = NULL ;
    
    while(temp1 != NULL && temp2 != NULL) {
        
        if(temp2 -> data < temp1 -> data) {
            forward = temp2 -> next ;
            if(prev != NULL) {
                prev -> next = temp2 ;
                temp2 -> next = temp1 ;
                prev = temp2 ;
                temp2 = forward ;
            }
            
            else {
                temp2 -> next = head1 ;
                head1 = temp2 ;
                prev = temp2 ;
                temp2 = forward ;
            }
        }
        
        else {
            prev = temp1 ;
            temp1 = temp1 -> next ;
        }
    }
    
    if(temp1 == NULL && temp2 != NULL) {
        prev -> next = temp2 ;
        return head1 ;
    }
    
    
    if(temp2 == NULL && temp1 != NULL) {
        return head1 ;
    }
    
}


//Function to merge two sorted linked list by creating a new LL
void insertAtTail(Node* &head , Node* &tail , int d) {
    Node* temp = new Node(d) ;
    if(head == NULL && tail == NULL) {
        head = temp ;
        tail = temp ;
    }

    else {
        teil -> next = temp ;
        tail = temp ;
    }
}

Node* mergeTwoSortedLL(Node* head1 , Node* head2) {

    if(head1 == NULL && head2 == NULL) {
        return NULL ;
    }

    Node* head3 = NULL ;
    Node* tail3 = NULL ;
    Node* temp1 = head1 ;
    Node* temp2 = head2 ;

    while(head1 != NULL || head2 != NULL) {
        
        if(temp1 -> data < temp2 -> data){
            inesrtAtTail(head3 , tail3 , temp1 -> data) ;
            temp1 = temp1 -> next ;
        }

        else {
            inesrtAtTail(head3 , tail3 , temp2 -> data) ;
            temp2 = temp2 -> next ;
        }
    }

    if(temp1 == NULL) {
        while(temp2 != NULL) {
            inesrtAtTail(head3 , tail3 , temp2 -> data) ;
            temp2 = temp1 -> next ;
        }
    }

    if(temp2 == NULL) {
        while(temp1 != NULL) {
            inesrtAtTail(head3 , tail3 , temp1 -> data) ;
            temp1 = temp1 -> next ;
        }
    }

    return head3 ;
}