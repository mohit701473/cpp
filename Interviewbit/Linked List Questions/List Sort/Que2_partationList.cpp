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