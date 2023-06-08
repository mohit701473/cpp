https://www.interviewbit.com/problems/remove-nth-node-from-list-end/


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
 
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    if(B == 0)
        return A ;
    
    int n = B ;
    int len = getLength(A) ;
    
    int nodePosition = len - n + 1;
    ListNode* temp = A ;
    ListNode* prev = NULL ;
    
    if(nodePosition <= 1){
        A = A -> next ;
        temp -> next = NULL ;
        delete temp ;
        return A ;
    }
    
    
    while(nodePosition > 1){
        prev = temp ;
        temp = temp -> next ;
        nodePosition-- ;
    }
    
    prev -> next = temp -> next ;
    delete temp ;
    return A ;
}
