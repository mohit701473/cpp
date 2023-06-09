https://www.interviewbit.com/problems/reverse-alternate-k-nodes/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
ListNode* Solution::solve(ListNode* A, int B) {
    int k = B ;
    
    if(k == 1)
        return A ;
        
    ListNode* curr = A ;
    ListNode* prev = NULL ;
    bool flag = true ;
    
    while(curr != NULL){
        
        if(flag){
            // reverse k nodes 
            ListNode* tempCurr = curr ;
            ListNode* tempPrev = NULL ;
            ListNode* tempForward = NULL ;
            
            for(int i=1 ; i<=k ; i++){
                tempForward = tempCurr -> next ;
                tempCurr -> next = tempPrev ;
                tempPrev = tempCurr ;
                tempCurr = tempForward ;
            }
            
            if(prev == NULL){
                prev = A ;
                A = tempPrev ;
                prev -> next = tempCurr ;
            }else {
                prev -> next = tempPrev ;
                curr -> next = tempCurr ;
            }

            curr = tempCurr ;
            flag = false ;
        }else {
            // skip alternative k nodes
            for(int i=1 ; i<=k ; i++){
                prev = curr ;
                curr = curr -> next ;
            }
                
            flag = true ;
        }
    }
    
    return A ;
}
