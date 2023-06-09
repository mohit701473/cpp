// Swap List Nodes in pairs
https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/*
Example Input
 Input 1: 
 A = 1 -> 2 -> 3 -> 4

 Input 2: 
 A = 7 -> 2 -> 1

Example Output
 Output 1: 
 2 -> 1 -> 4 -> 3

 Output 2: 
 2 -> 7 -> 1
*/

//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
ListNode* Solution::swapPairs(ListNode* A) {
    
    if(A == NULL || A -> next == NULL)
        return A ;
        
    ListNode* curr = A ;
    ListNode* prev = A ;
    A = NULL ;
    
    while(curr != NULL && curr -> next != NULL){
        
        ListNode* tempcurr = curr ;
        ListNode* tempprev = NULL ;
        ListNode* tempforward = NULL ;
        
        for(int i=0 ; i<2 ; i++){
            tempforward = tempcurr -> next ;
            tempcurr -> next = tempprev ;
            tempprev = tempcurr ;
            tempcurr = tempforward ;
        }
        
        if(A == NULL){
            A = tempprev ;
        }
        
        if(tempprev != A){
            prev -> next = tempprev ;
            prev = curr ;
        }
        
        curr = tempcurr ;
    }
    
    if(curr != NULL && curr -> next == NULL)
        prev -> next = curr ;
    
    return A ;
}
