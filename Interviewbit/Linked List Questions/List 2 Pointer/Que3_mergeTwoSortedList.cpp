https://www.interviewbit.com/problems/merge-two-sorted-lists/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------

// Approch - 1  
// T.C. = O(N) 
// S.C. = O(1)) 
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    if(A == NULL && B == NULL)
            return NULL ;

        if(A == NULL)
            return B ;

        if(B == NULL)
            return A ;

        ListNode* head = NULL ;
        ListNode* tail = NULL ;

        while(A != NULL && B != NULL){

            if(A -> val < B -> val){
                if(head == NULL){
                    head = tail = A ;
                }
                else{
                    tail -> next = A ;
                    tail = A ;
                }

                A = A -> next ;
            }

            else{
                if(head == NULL){
                    head = tail = B ;
                }
                else{
                    tail -> next = B ;
                    tail = B ;
                }

                B = B -> next ;
            }
        }

        while(A != NULL){
            tail -> next = A ;
            tail = A ;
            A = A -> next ;
        }

        while(B != NULL){
            tail -> next = B ;
            tail = B ;
            B = B -> next ;
        }

        return head ;
}
