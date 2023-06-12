https://www.interviewbit.com/problems/reverse-link-list-ii/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
pair<ListNode*, ListNode*> reverseLinkedList(ListNode* head, int n){
        
    ListNode* curr = head ;
    ListNode* prev = NULL ;
    ListNode* forward = NULL ;
    
    while(n > 0){
        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;
        n-- ;
    }
    
    return {prev, curr} ;
}
 

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    if(A == NULL || A -> next == NULL)
        return A ;
    
    int m = B , n = C ;
    
    ListNode* curr = A ;
    ListNode* prev = NULL ;
    
    if(m == 1){
        pair<ListNode*, ListNode*> p = reverseLinkedList(curr, n) ;
        A = p.first ;
        curr -> next = p.second ;
        
        return A ;
    }
    
    while(m > 1){
        prev = curr ;
        curr = curr -> next ;
        m-- ;
        n-- ;
    }
    
    pair<ListNode*, ListNode*> p = reverseLinkedList(curr, n) ;
    
    prev -> next = p.first ;
    curr -> next = p.second ;
    
    return A ;
}