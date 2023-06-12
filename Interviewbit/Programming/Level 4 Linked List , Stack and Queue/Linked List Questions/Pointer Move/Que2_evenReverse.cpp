https://www.interviewbit.com/problems/even-reverse/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(N)
void insertAtHead(ListNode* &evenHead, int data){
    ListNode* temp = new ListNode(data) ;
    if(evenHead == NULL){
        evenHead = temp ;
        return ;
    }
    
    temp -> next = evenHead ;
    evenHead = temp ;
}
 
ListNode* Solution::solve(ListNode* A) {
    if(A -> next == NULL)
        return A ;
    
    ListNode* evenHead = NULL ;
    ListNode* curr = A -> next ;
    
    while(curr != NULL){
        
        insertAtHead(evenHead, curr -> val) ;\
        
        if(curr -> next != NULL)
            curr = curr -> next -> next ;
            
        else break ;
    }
    
    curr = A -> next ;
    ListNode* temp = evenHead ;
    while(curr != NULL){
        
        curr -> val = temp -> val ;
        
        if(curr -> next != NULL){
            curr = curr -> next -> next ;
            temp = temp -> next ;
        }
        else break ;
    }
    
    return A ;
}





// Approch - 2 
// T.C. = O(N)
// S.C. = O(1)
void getEvenOddList(ListNode* &oddHead, ListNode* &evenHead){
    
    ListNode* odd = oddHead ;
    ListNode* even = evenHead ;
    
    while(even != NULL && even -> next != NULL){
        
        odd -> next = odd -> next -> next ;
        odd = odd -> next ;
        
        even -> next = even -> next -> next ;
        even = even -> next ;
    }
    
    if(even != NULL && even -> next == NULL){
        odd -> next = NULL ;
    }
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

ListNode* mergeEvenOddList(ListNode* odd, ListNode* even){
    ListNode* head = odd ;
    
    ListNode* oddForward = NULL ;
    ListNode* evenForward = NULL ;
    
    while(odd != NULL && even != NULL){
        oddForward = odd -> next ;
        evenForward = even -> next ;
        
        odd -> next = even ;
        even -> next = oddForward ;
        
        odd = oddForward ;
        even = evenForward ;
    }
    
    return head ;
}
 
ListNode* Solution::solve(ListNode* A) {
    if(A -> next == NULL || A -> next -> next == NULL)
        return A ;
        
    ListNode* oddHead = A ;
    ListNode* evenHead = A -> next ;
    
    // step -> 1: seprate even position and odd position node and create two different even odd list
    getEvenOddList(oddHead, evenHead) ;
    
    // step -> 2: reverse even linked list 
    evenHead = reverseLinkedList(evenHead) ;
    
    // step -> 3: merge even odd List
    return mergeEvenOddList(oddHead, evenHead) ;  
}
