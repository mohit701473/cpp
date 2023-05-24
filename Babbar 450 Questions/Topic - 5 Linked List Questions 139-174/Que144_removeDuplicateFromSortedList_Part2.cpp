// LeetCode Que.82 Remove Duplicates from Sorted List II
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
*/




//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(N)
class Solution {

    void insertAtTail(ListNode* &head, ListNode* &tail, int data){
        ListNode* temp = new ListNode(data) ;

        if(head == NULL){
            head = tail = temp ;
            return ;
        }

        tail -> next = temp ;
        tail = temp ;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head ;

        ListNode* newHead = NULL ;
        ListNode* newTail = NULL ;
        ListNode* curr = head ;

        while(curr != NULL){
            ListNode* temp = curr -> next ;

            if(temp == NULL|| curr -> val != temp -> val){
                insertAtTail(newHead, newTail, curr -> val) ;
            }

            else{
                while( temp != NULL && curr -> val == temp -> val ){
                    temp = temp -> next ;
                }
            }

            curr = temp ;
        }

        return newHead ;
    }
};




// Approch - 2
// T.C. = O(N)
// S.C. = O(1)
class Solution {

public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head ;

        ListNode* curr = head ;
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
};