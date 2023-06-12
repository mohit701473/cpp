https://www.interviewbit.com/problems/palindrome-list/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
ListNode* getMidNode(ListNode* head){
    ListNode* slow = head ;
    ListNode* fast = head ;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    
    if(fast != NULL) 
        return slow -> next ;
    
    return slow ;
}
 
ListNode* reverseLinkedList(ListNode* head){
    if(head == NULL || head -> next == NULL)
        return head ;
        
    ListNode* curr = head ;
    ListNode* prev = NULL ;
    ListNode* forward = NULL ;
    
    while(curr != NULL){
        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;
    }
    
    return prev ;
}
 
int Solution::lPalin(ListNode* A) {
    if(A == NULL || A -> next == NULL)
        return 1 ;
        
    ListNode* mid = getMidNode(A) ;
    mid = reverseLinkedList(mid) ;
    
    ListNode* curr1 = A ;
    ListNode* curr2 = mid ;
    
    while(curr2 != NULL){
        if(curr1 -> val != curr2 -> val)
            return 0 ;
            
        curr1 = curr1 -> next ;
        curr2 = curr2 -> next ;
    }
    
    return 1 ;
}
