// GFG -> Intersection of two sorted Linked lists
https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

/*
Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked 
list should be made with its own memory the original lists should not be changed.
Note: The linked list elements are not necessarily distinct.

Example 1:
Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.


Example 2:
Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40
*/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  map + itration
// T.C. = O(n+m)  n => size of 1st LL & m => size of 2nd LL
// S.C. = O(n+m+k)  k => total no. of common nodes 
Node* findIntersection(Node* head1, Node* head2)
{
    unordered_map<int, int> visitCount ;
    unordered_map<int, int> insertCount ;
    
    Node* head = NULL ;
    Node* tail = NULL ;
    
    Node* curr1 = head1 ;
    while(curr1 != NULL){
        visitCount[curr1 -> data]++ ;
        curr1 = curr1 -> next ;
    }
    
    Node* curr2 = head2 ;
    while(curr2 != NULL){
        if(visitCount[curr2 -> data] != 0 && visitCount[curr2-> data] != insertCount[curr2 -> data]){ 
            
            Node* temp = new Node(curr2 -> data) ;
            if(head == NULL)
                head = tail = temp ;
                
            else {
                tail -> next = temp ;
                tail = temp ;
            }
            insertCount[curr2 -> data]++ ;
        }
        curr2 = curr2 -> next ;
    }
    
    return head ;
}



// Approch - 2 use the point of the sorted LL
// T.C. = O(max(m,n))
// S.C. = O(k)   k =>  no. of common nodes in worst case k => min(m,n)
Node* findIntersection(Node* head1, Node* head2)
{
    Node* head = NULL ;
    Node* tail = NULL ;
    
    Node* curr1 = head1 ;
    Node* curr2 = head2 ;
    
    while(curr1 != NULL && curr2 != NULL){
        
        if(curr1 -> data == curr2 -> data){
            Node* temp = new Node(curr2 -> data) ;
            if(head == NULL)
                head = tail = temp ;
                
            else {
                tail -> next = temp ;
                tail = temp ;
            }
            curr1 = curr1 -> next ;
            curr2 = curr2 -> next ;
        }
        
        else {
            // Jis ki value choti h use aage bdaa do
            
            if(curr1 -> data < curr2 -> data) // curr1 chhota h 
                curr1 = curr1 -> next ;
                
            else curr2 = curr2 -> next ;  // curr2 chhota h
        }
    }
    return head ;
}