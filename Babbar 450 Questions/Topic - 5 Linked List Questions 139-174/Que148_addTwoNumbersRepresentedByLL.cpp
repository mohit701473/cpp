// LeetCode -> 445. Add Two Numbers II
https://leetcode.com/problems/add-two-numbers-ii/description/

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes 
contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]


Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]


Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
 
Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
*/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  Reversing the Linked List
// T.C. = O(max(l1.size(), l2.size()))
// S.C. = O(1) 
class Solution {

    int sizeOfLL(ListNode* head){
        int count = 0 ;
        while(head != NULL){
            count++ ;
            head = head -> next ; 
        }

        return count ;
    }

    ListNode* reverseLL(ListNode* head){
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

    void solve(ListNode* &head1, ListNode* &head2){ // length of head1 LL >= length of head2 LL
        ListNode* curr1 = head1 ;
        ListNode* curr2 = head2 ;
        
        while(curr2 != NULL){ // bcz lenght of head1 LL >= length of head2 LL so curr2 reach first to NULL
            int num1 = curr1 -> val ;
            int num2 = curr2 -> val ; 
            if(num1 + num2 > 9){
                curr1 -> val = num1+num2 - 10 ;
                if(curr1 -> next != NULL)
                    curr1 -> next -> val += 1 ; 
                else{
                    ListNode* temp = new ListNode(1) ;
                    curr1 -> next = temp ;
                }
            }

            else curr1 -> val = num1+num2 ;

            curr1 = curr1 -> next ;
            curr2 = curr2 -> next ;
        }

        while(curr1 != NULL && curr1 -> val > 9){
            curr1 -> val -= 10 ;
            if(curr1 -> next != NULL)
                curr1 -> next -> val += 1 ; 
            else{
                ListNode* temp = new ListNode(1) ;
                curr1 -> next = temp ;
            }
            curr1 = curr1 -> next ;
        }

    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2 ;

        if(l2 == NULL)
            return l1 ;

        if(l1 == NULL && l2 == NULL)
            return NULL ;
    
        int n1 = sizeOfLL(l1) ;
        int n2 = sizeOfLL(l2) ;

        l1 = reverseLL(l1) ;
        l2 = reverseLL(l2) ;

        if(n1 >= n2){ // store result in l1
            solve(l1, l2) ;
            return reverseLL(l1) ;
        }
        
        solve(l2, l1) ; // store result in l2
        return reverseLL(l2) ;
    }
};


