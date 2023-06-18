https://www.interviewbit.com/problems/partition-list/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
void insertAtTail(ListNode* &head, ListNode* &tail, ListNode* &curr){
    if(head == NULL)
        head = tail = curr ;
    
    else {
        tail -> next = curr ;
        tail = curr ;
    }
    
    curr -> next = NULL ;
}
 
ListNode* Solution::partition(ListNode* A, int B) {
    
    ListNode* head1 = NULL ;
    ListNode* tail1 = NULL ;
    
    ListNode* head2 = NULL ;
    ListNode* tail2 = NULL ;
    
    ListNode* curr = A ;
    ListNode* forward = NULL ;
    
    while(curr != NULL){
        forward = curr -> next ;
        
        if(curr -> val < B)
            insertAtTail(head1, tail1, curr) ;
            
        else
            insertAtTail(head2, tail2, curr) ;
            
        curr = forward ;
    }
    
    if(head1 == NULL)
        return head2 ;
    
    tail1 -> next = head2 ;
    return head1 ;
}






https://practice.geeksforgeeks.org/problems/partition-a-linked-list-around-a-given-value/1

// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
void insertAtTail(struct Node* &head, struct Node* &tail, struct Node* &curr){
        if(head == NULL)
            head = tail = curr ;
        
        else {
            tail -> next = curr ;
            tail = curr ;
        }
        
        curr -> next = NULL ;
    }
    
void insertAtHead(struct Node* &head, struct Node* &tail, struct Node* &curr){
        if(head == NULL){
            head = tail = curr ;
            curr -> next = NULL ;
        }
        
        else {
            curr -> next = head ;
            head = curr ;
        }
}

struct Node* partition(struct Node* head, int x) {
    
        struct Node* head1 = NULL ;
        struct Node* tail1 = NULL ;
        
        struct Node* head2 = NULL ;
        struct Node* tail2 = NULL ;
        
        struct Node* curr = head ;
        struct Node* forward = NULL ;
        
        while(curr != NULL){
            forward = curr -> next ;
            
            if(curr -> data < x)
                insertAtTail(head1, tail1, curr) ;
                
            if(curr -> data > x)
                insertAtTail(head2, tail2, curr) ;
                
            if(curr -> data == x)
                insertAtHead(head2, tail2, curr) ;
                
            curr = forward ;
        }
        
        if(head1 == NULL)
            return head2 ;
        
        tail1 -> next = head2 ;
        return head1 ;
}