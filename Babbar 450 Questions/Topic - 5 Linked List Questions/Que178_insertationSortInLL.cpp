https://www.interviewbit.com/problems/insertion-sort-list/

https://leetcode.com/problems/insertion-sort-list/submissions/966484313/

//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N^2)
// S.C. = O(1)
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A == NULL || A -> next == NULL)
        return A ;
        
    ListNode* curr = A ;
    
    while(curr != NULL){
        bool flag = true ;
        
        ListNode* temp = curr -> next ;
        ListNode* tempCurr = A ;
        ListNode* tempPrev = NULL ;
        while(tempCurr != temp && temp != NULL){
            if(tempCurr -> val > temp -> val){
                if(tempPrev == NULL){
                    A = temp ;
                    curr -> next = temp -> next ;
                    temp -> next = tempCurr ;
                }else{
                    tempPrev -> next = temp ;
                    curr -> next = temp -> next ;
                    temp -> next = tempCurr ;
                }
                flag = false ;
                break ;
            }
            
            tempPrev = tempCurr ;
            tempCurr = tempCurr -> next ;
        }
        
        if(flag)
            curr = curr -> next ;
    }
    
    return A ;
}
