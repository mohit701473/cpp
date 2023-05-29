// Leet Code ->  148. Sort List
https://leetcode.com/problems/sort-list/description/




//------------------------------------------------------------   Solution    ----------------------------------------------------------------------

// Approch - 1  
// T.C. = O(Nlog(N)) 
// S.C. = O(log(N)) 
class Solution {

    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head -> next ;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }
        
        return slow ;
    }


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


    ListNode* mergeSort(ListNode* head){
        
        if(head == NULL || head -> next == NULL)
            return head ;

        // Break Linked List into two half, after finding mid
        ListNode* mid = getMiddle(head) ;

        ListNode* left = head ;
        ListNode* right = mid -> next ;
        mid -> next = NULL ;

        // recursive sort two LL
        left = mergeSort(left) ;
        right = mergeSort(right) ;

        // merge left and right half
        ListNode* result = merge(left, right) ;

        return result ;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head ;

        return mergeSort(head) ;
    }
};