https://www.interviewbit.com/courses/programming/linked-lists



//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  Reversing the Linked List
// T.C. = O(max(l1.size(), l2.size()))
// S.C. = O(1) 
int getLengthOfList(ListNode* head){
    int count = 0 ;
    ListNode* curr = head ;
    
    while(curr != NULL){
        count++ ;
        curr = curr -> next ;
    }
    
    return count ;
}

 
int Solution::solve(ListNode* A, int B) {
    int k = B ;
    
    // step -> 1: find the length of the List
    int len = getLengthOfList(A) ;
    
    // step -> 2: find the position of the Node from the starting Node of List
    int position = len/2 + 1 - k ;
    
    if(position < 1)
        return -1 ;
    
    ListNode* curr = A ;
    
    // step -> 3: find the Node
    while(position > 1){
        curr = curr -> next ;
        position-- ;
    }
    return curr -> val ;
}
