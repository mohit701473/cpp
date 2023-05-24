// GFG => Remove duplicates from an unsorted linked list
https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple 
nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4
Example 2:

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.
*/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1 using map
// T.C. = O(N)
// S.C. = O(N)
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if(head == NULL || head -> next == NULL)
            return head;
            
        unordered_map<int, bool> m ;
        
        Node* curr = head ;
        Node* prev = NULL ;
        
        while(curr != NULL){
           
            if(m[curr -> data] == true){
                Node* temp = curr ;
                prev -> next = curr -> next ;
                curr = curr -> next ;
                temp -> next = NULL ;
                delete temp ;
            }
           
            else{
                m[curr -> data] = true ;
                prev = curr ;
                curr = curr -> next ;
            }
        
        }
        
        return head ;
    }
};