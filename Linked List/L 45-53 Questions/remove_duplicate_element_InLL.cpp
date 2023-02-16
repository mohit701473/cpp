//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(head == NULL) {
     return NULL ;
 }
 
 Node* curr = head ;
 
 while(curr != NULL) {

     
     if((curr -> next != NULL) && (curr -> data == curr -> next -> data)) {
         Node* next_next = curr -> next -> next ;
         Node* nodeToDelete = curr -> next ;
         delete(nodeToDelete) ;
         curr -> next = next_next ;
     }
     else{
        curr = curr -> next ;
     }

 }
 
 return head ;

}


// Remove duplicate element from unsorted Linked List 
/*
Their are three approches to solve this question 
(1) Use two while loop 
(2) First sort given list so T.C = O(nlog(n))  & then remove element T.C = O(n)  so comple T.C = O(nlog(n))
(3) Using map(map is a stl(stard template class) in C++) so T.C = O(n)  & S.C = O(n) 
*/