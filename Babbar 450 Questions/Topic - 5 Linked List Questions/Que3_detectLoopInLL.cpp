// Leet Code  141. Linked List Cycle


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL || head -> next == NULL)
            return false ;
        
        ListNode* slow = head ;
        ListNode* fast = head -> next ;

        while(slow != fast){

            slow = slow -> next ;

            if(fast == NULL || fast -> next == NULL)
                return false ;
            
            else  fast = fast -> next -> next ;
        }

        if(slow == fast)
                return true ;

        return false ;
    }
};