https://www.interviewbit.com/problems/list-cycle/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
pair<bool, ListNode*> checkCycle(ListNode* head){
    ListNode* slow = head ;
    ListNode* fast = head ;
    
    do{
        slow = slow -> next ;
        fast = fast -> next -> next ;
        if(slow == fast)
            return {true, slow} ;
    }while(fast != NULL && fast -> next != NULL) ;
    
    return {false, NULL} ;
} 

ListNode* beginningNodeOfCycle(ListNode* slow, ListNode* fast){
    
    while(slow != fast){
        slow = slow -> next ;
        fast = fast -> next ;
    }
    
    return slow ;
}

ListNode* Solution::detectCycle(ListNode* A) {
    
    pair<bool, ListNode*> isCycle = checkCycle(A) ;
    
    if(!isCycle.first)
        return NULL ;
        
    ListNode* slow = A ;
    ListNode* fast = isCycle.second ;
    
    return beginningNodeOfCycle(slow, fast) ; 
}
 