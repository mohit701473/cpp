// Leet Code -> 21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/description/




//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  
// T.C. = O(N+M) 
// S.C. = O(1) 
class Solution {

    ListNode* merge(ListNode* head1, ListNode* head2){
        if(head1 == NULL && head2 == NULL)
            return NULL ;

        if(head1 == NULL)
            return head2 ;

        if(head2 == NULL)
            return head1 ;

        ListNode* head = NULL ;
        ListNode* tail = NULL ;

        while(head1 != NULL && head2 != NULL){

            if(head1 -> val < head2 -> val){
                if(head == NULL){
                    head = tail = head1 ;
                }
                else{
                    tail -> next = head1 ;
                    tail = head1 ;
                }

                head1 = head1 -> next ;
            }

            else{
                if(head == NULL){
                    head = tail = head2 ;
                }
                else{
                    tail -> next = head2 ;
                    tail = head2 ;
                }

                head2 = head2 -> next ;
            }
        }

        while(head1 != NULL){
            tail -> next = head1 ;
            tail = head1 ;
            head1 = head1 -> next ;
        }

        while(head2 != NULL){
            tail -> next = head2 ;
            tail = head2 ;
            head2 = head2 -> next ;
        }

        return head ;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        return merge(list1, list2) ;
    }
};