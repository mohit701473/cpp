https://www.interviewbit.com/problems/sort-list/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------

// Approch - 1  
// T.C. = O(Nlog(N)) 
// S.C. = O(1)) 
ListNode* getMiddleOfList(ListNode* head){
        
    ListNode* slow = head ;
    ListNode* fast = head -> next ;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    
    return slow ;
}  


void insertAtTail(ListNode* &head, ListNode* &tail, ListNode* curr){
    if(head == NULL){
        head = tail = curr ;
        return ;
    }

    tail -> next = curr ;
    tail = curr ;
}


ListNode* merge(ListNode* head1, ListNode* head2){
    if(head1 == NULL && head2 == NULL)
        return NULL ;

    if(head1 == NULL)
        return head2 ;

    if(head2 == NULL)
        return head1 ;

    ListNode* head = NULL ;
    ListNode* tail = NULL ;

    while(head1 != NULL && head2 != NULL){

        if(head1 -> val < head2 -> val){
            insertAtTail(head, tail, head1) ;
            head1 = head1 -> next ;
        }

        else{
            insertAtTail(head, tail, head2) ;
            head2 = head2 -> next ;
        }
    }
    
    if(head1 != NULL)
        tail -> next = head1 ;
        
    if(head2 != NULL)
        tail -> next = head2 ;

    return head ;
}

 
ListNode* mergeSort(ListNode* head){
    if(head == NULL || head -> next == NULL)
        return head ;
        
    // step -> 1: Break Linked List into two half, after finding mid
    ListNode* mid = getMiddleOfList(head) ;
        
    ListNode* left = head ;
    ListNode* right = mid -> next ;
    mid -> next = NULL ;
    
    // step -> 2: recursive sort two LL
    left = mergeSort(left) ;
    right = mergeSort(right) ;
      
    // step -> 3: merge left and right half and return 
    return merge(left, right) ;

}
 
 
ListNode* Solution::sortList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL)
        return A ;
        
    return mergeSort(A) ;
}
