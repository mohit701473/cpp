// Leet Code -> 234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/description/

/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1 
// T.C. = O(N) ;
// S.C. = O(1) ;
class Solution {
    
    int getLength(ListNode* head){
        int count = 0 ;
        ListNode* curr = head ;
        while(curr != NULL){
            count++ ;
            curr = curr -> next ;
        }
        return count ;
    }

    ListNode* getMiddleNode(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head ;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }
        
        return slow ;
    }

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

    bool checkPalindrome(ListNode* head, ListNode* middle){
 
        while(middle != NULL){
            if(head -> val != middle -> val)
                return false ;

            middle = middle -> next ;
            head = head -> next ;
        }
        return true ;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL)
            return true ;

        int len = getLength(head) ;

        ListNode* middle = getMiddleNode(head) ;

        if(len % 2 == 0){ // even length Linked List
            middle = reverseList(middle) ;
            return checkPalindrome(head, middle) ;
        }

        // odd length LL
        middle = reverseList(middle -> next) ;
        return checkPalindrome(head, middle) ;
    }
};