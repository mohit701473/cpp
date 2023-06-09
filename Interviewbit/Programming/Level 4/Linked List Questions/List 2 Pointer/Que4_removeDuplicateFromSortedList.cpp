https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A -> next == NULL)
        return A ;
        
    ListNode* head = A ;
    ListNode* tail = A ;
    
    while(tail != NULL && tail -> next != NULL){
        ListNode* temp = tail -> next ;
        
        while(temp != NULL && tail -> val == temp -> val){
            temp = temp -> next ;
        }
        
        tail -> next = temp ;
        tail = temp ;
    }
    
    return head ;
}
