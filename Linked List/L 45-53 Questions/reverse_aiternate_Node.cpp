// Reverse alternate nodes in Link List

/*
  reverse alternate nodes and append at the end The input list 
  will have at least one element Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/

struct Node* reverseLL(Node* head) {

    if(head == NULL || head -> next == NULL) {
        return head ;
    }

    Node* prev = NULL ;
    Node* curr = head ;
    Node* forward = NULL ;

    while(curr != NULL) {
        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;
    }

    return prev ;
}

class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        if(odd == NULL) {
            return ;
        }
        
        struct Node* head = odd ;
        struct Node* head1 = head -> next ;
        struct Node* temp = head1 ;
        
        while(temp != NULL && temp -> next != NULL) {
            head -> next = temp -> next ;
            head = temp -> next ;
            temp -> next = head -> next ; //temp -> next -> next ;
            temp = temp -> next ;
        }
        
        head1 = reverseLL(head1) ;
        
        head -> next = head1 ;
        
    }
};