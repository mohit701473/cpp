

//------------------------------------------------------------   Solution    ----------------------------------------------------------------------

https://www.interviewbit.com/problems/reorder-list/

// Approch - 1
// T.C. = O(N)
// S.C. = O(1)

ListNode* getMiddleOfList(ListNode* head){
    ListNode* slow = head ;
    ListNode* fast = head -> next ;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    
    return slow ;
} 

ListNode* reverseLinkedList(ListNode* head){
    if(head == NULL || head -> next == NULL)
        return head ;
        
    ListNode* curr = head ;
    ListNode* prev = NULL ;
    ListNode* forward = NULL ;
    
    while(curr != NULL){
        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;
    }
    
    return prev ;
}

ListNode* mergedList(ListNode* l1, ListNode* l2){
    ListNode* head = l1 ;
    
    ListNode* forward1 = NULL ;
    ListNode* forward2 = NULL ;
    
    while(l1 != NULL && l2 != NULL){
        forward1 = l1 -> next ;
        forward2 = l2 -> next ;
        
        l1 -> next = l2 ;
        l2 -> next = forward1 ;
        
        l1 = forward1 ;
        l2 = forward2 ;
    }
    
    return head ;
}

ListNode* Solution::reorderList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL)
        return A ;
        
    // step -> 1: find middle of Linked List
    ListNode* mid = getMiddleOfList(A) ;
    
    // step -> 2 : separate list into two list 
    ListNode* l1 = A ;
    ListNode* l2 = mid -> next ;
    mid -> next = NULL ;
    
    l2 = reverseLinkedList(l2) ;
    
    // step -> 3: merge these two list
    return mergedList ;
}



https://leetcode.com/problems/reorder-list/description/

// Approch - 2
// T.C. = O(N^2)
// S.C. = O(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head -> next == NULL)
            return ;

        ListNode* curr = head ;

        while(curr -> next != NULL){
            ListNode* temp = curr -> next ;
            ListNode* prev = NULL ;

            while(temp -> next != NULL){
                prev = temp ;
                temp = temp -> next ;
            }

            if(prev != NULL){
                temp -> next = curr -> next ;
                curr -> next = temp ;
                curr = temp -> next ;
                prev -> next = NULL ;
            }

            else break ;
        }

    }
};