// LeetCode -> 160. Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no 
intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Follow up: Could you write a solution that runs in O(m + n) time and use only O(1) memory?
*/



//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  map + itration
// T.C. = O(max(m,n))  n => size of 1st LL & m => size of 2nd LL
// S.C. = O(n) 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> visited ;

        ListNode* curr1 = headA ;
        ListNode* curr2 = headB ;
        ListNode* intersection = NULL ;

        while(curr1 != NULL){
            visited[curr1] = true ;
            curr1 = curr1 -> next ;
        }

        while(curr2 != NULL){

            if(visited[curr2]){
                intersection = curr2 ;
                break ;
            }

            curr2 = curr2 -> next ;
        }

        return intersection ;
    }
};






// Approach - 2 by finding the length of the lists.
// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(1)
https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
int lengthOfLL(Node* head){
    if(head == NULL)
        return 0 ;
        
    int count = 0 ;
    while(head != NULL){
        count++ ;
        head = head -> next ;
    }
    
    return count ;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Step -> 1 find the length of both Linked List 
    int n = lengthOfLL(head1) ;
    int m = lengthOfLL(head2) ;
    
    // Step -> 2 Jis Linked List ki length badi h use abs(n-m) traverse kr lo
    Node* curr1 = head1 ;
    Node* curr2 = head2 ;
    
    if(n>m){
        int i=1 ;
        while(i<=n-m && curr1 != NULL){
            i++ ;
            curr1 = curr1 -> next ;
        }
    }
    
    else {
        int i=1 ;
        while(i<=m-n && curr2 != NULL){
            i++ ;
            curr2 = curr2 -> next ;
        }
    }
    
    // Step -> 3 Now size of the remaing traversing part is same in both LL 
    while(curr1 != NULL && curr2 != NULL){
        if(curr1 == curr2)
            return curr1 -> data ;
        
        curr1 = curr1 -> next ;
        curr2 = curr2 -> next ;
    }
    
    return -1 ;
}
