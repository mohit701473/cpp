https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A == NULL || A -> next == NULL)
            return A ;

        ListNode* curr = A ;
        ListNode* prev = NULL ;
        ListNode* newHead = NULL ;

        while(curr != NULL && curr -> next != NULL){
            ListNode* temp = curr -> next ;
            
            if(curr -> val == temp -> val){

                while(temp != NULL && temp -> val == curr -> val)
                    temp = temp -> next ;

                if(prev != NULL)
                    prev -> next = temp ;

                curr = temp ;
            }

            else{
                if(newHead == NULL)
                    newHead = curr ;
                prev = curr ;
                curr = temp ;
            }
        }

        if(curr != NULL && newHead == NULL)
            newHead = curr ;

        return newHead ;
}