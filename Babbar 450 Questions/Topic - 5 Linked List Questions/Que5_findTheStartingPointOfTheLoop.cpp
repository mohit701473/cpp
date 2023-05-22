

// Approch - 1
// T.C. = O(N)
// S.C. = O(N)
class Solution {

    ListNode* floydCycleDetection(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head ;

        do{
            slow = slow -> next ;

            if(fast == NULL || fast -> next == NULL)
                return NULL ;

            fast = fast -> next -> next ;
        }while(slow != fast) ;

        return fast ;
    }

public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return NULL ;

        ListNode* slow = head ;
        ListNode* fast = floydCycleDetection(head) ;

        if(fast == NULL)    return NULL ;

        while(slow != fast){
            slow = slow -> next ;
            fast = fast -> next ;
        }

        return slow ;
    }
};