https://www.interviewbit.com/problems/sort-binary-linked-list/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
ListNode* Solution::solve(ListNode* A) {
    if(A == NULL || A -> next == NULL)
        return A ;
        
    ListNode* head = NULL ;
    ListNode* tail = NULL ;
    
    ListNode* curr = A ;
    ListNode* forward = NULL ;
    
    while(curr != NULL){
        forward = curr -> next ;
        
        if(head == NULL){
                head = tail = curr ;
                curr -> next = NULL ;
        }else{
            if(curr -> val == 1){
                // insert at tail 
                tail -> next = curr ;
                tail = curr ;
                curr -> next = NULL ;
            }else {
                // insert at head 
                curr -> next = head ;
                head = curr ;
            }
        }
        curr = forward ;
    }
    
    return head ;
}