https://www.interviewbit.com/problems/k-reverse-linked-list/



//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A == NULL || A -> next == NULL || B == 1)
        return A ;
        
    int k = B ;
    ListNode* curr = A ;
    ListNode* prev = A ;
    
    while(curr != NULL){
        
        // Reverse the K Nodes
        ListNode* tempCurr = curr ;
        ListNode* tempPrev = NULL ;
        ListNode* tempForward = NULL;
        
        for(int i=0 ; i<k ; i++){
            tempForward = tempCurr -> next ;
            tempCurr -> next = tempPrev ;
            tempPrev = tempCurr ;
            tempCurr = tempForward ;
        }
        
        if(prev != A){
            prev -> next = tempPrev ;
            prev = curr ;
        }else{
            A = tempPrev ;
        }
        
        curr = tempCurr ;
    }
    
    return A ;
}