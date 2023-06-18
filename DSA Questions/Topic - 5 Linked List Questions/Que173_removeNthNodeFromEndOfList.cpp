// Leet Code -> 19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Follow up: Could you do this in one pass?
*/

//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1 
// T.C. = O(N) ;
// S.C. = O(1) ;
class Solution {

    ListNode* reverseList(ListNode* head) {

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


    int getLength(ListNode* head){
        int count = 0 ;
        ListNode* curr = head ;
        while(curr != NULL){
            count++ ;
            curr = curr -> next ;
        }
        return count ;
    }

    // function to get nth node from end of the List
    ListNode* getNthFromEnd(ListNode *head, int n)
    {
        int len = getLength(head) ;
        head = reverseList(head) ;
            
        if(n == 1)
            return head ;
        
        ListNode* temp = head ;
        int count = 1 ;
        while(count < n){
            count++ ;
            temp = temp -> next ;
        }
        
        return temp ;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head) ;
        head = reverseList(head) ;
        
        ListNode* temp = head ;
        ListNode* prev = NULL ;
        int count = 1 ;

        while(count < n){
            count++ ;
            prev = temp ;
            temp = temp -> next ;
        }

        // remove nth node
        if(prev != NULL){
            prev -> next = temp -> next ;
            temp -> next = NULL ;
            delete temp ;
        }

        else {
            head = temp -> next ;
            temp -> next = NULL ;
            delete temp ;
        }

        return reverseList(head) ;
    }
};



// Approch - 2 Solve in one pass(follow up)
// T.C. = O(N)
// S.C. = O(N) recursive stack space 
class Solution {
    void solve(ListNode* curr, ListNode* prev, int &n){
        if(curr == NULL)
            return ;

        prev = curr ;
        curr = curr -> next ;
        solve(curr, prev, n) ;

        if(curr != NULL){
            n-- ;
            if(n == 0){
                prev -> next = curr -> next ;
                curr -> next = NULL ;
                delete curr ;
            }
        }
        
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head ;
        ListNode* prev = NULL ;
        solve(curr, prev, n) ;

        if(n==1){
            head = curr -> next ;
            curr -> next = NULL ;
            delete curr ;
        }

        return head ;
    }
};
