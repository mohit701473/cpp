https://www.interviewbit.com/problems/rotate-list/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)

int getLength(ListNode* head){
    int count = 0 ;
    ListNode* curr = head ;
    while(curr != NULL){
        count++ ;
        curr = curr -> next ;
    }
    return count ;
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

pair<ListNode*, ListNode*> getKethNodeFromEndOfLL(ListNode* &head, int K){
    
    int len = getLength(head) ;
        
    if(K > len)
        K = K % len ;
        
    if(K == len || K == 0)
        return {head, NULL} ;
        
    head = reverseLinkedList(head) ;
    
    int i = 1 ;
    ListNode* KthNode = head ;
    ListNode* temp = head -> next ; // k+1 th KthNode
    
    while(i<K && KthNode -> next != NULL){
        KthNode = temp ;
        temp = KthNode -> next ;
        i++ ;
    }
    
    head = reverseLinkedList(head) ;
    return {KthNode, temp} ;
}

ListNode* Solution::rotateRight(ListNode* A, int B) {
    pair<ListNode* , ListNode*> p = getKethNodeFromEndOfLL(A, B) ;
    
    if(p.second == NULL)
        return p.first ;
    
    ListNode* temp = A ;
    
    while(temp -> next != NULL){
        temp = temp -> next ;
    }
    
    temp -> next = A ;
    p.second -> next = NULL ;
    A = p.first ;

    return A ;
}
