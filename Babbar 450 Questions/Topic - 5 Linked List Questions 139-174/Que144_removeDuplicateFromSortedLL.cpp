// Leet Code -> 83. Remove Duplicates from Sorted


// Approch 1 
// T.C. = O(N)
// S.C. = O(1) 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head ;

        ListNode* curr = head ;

        while(curr -> next != NULL){
            ListNode* temp = curr -> next ;
            if(curr -> val == temp -> val){
                curr -> next = temp -> next ;
                temp -> next = NULL ;
                delete temp ;
            }

            else curr = curr -> next ;
        }

        return head ;
    }
};