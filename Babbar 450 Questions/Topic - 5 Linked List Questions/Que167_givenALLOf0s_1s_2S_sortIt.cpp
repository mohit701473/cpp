// GFG  ->  Given a linked list of 0s, 1s and 2s, sort it.
https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------

// Approch - 1  
// T.C. = O(N) 
// S.C. = O(1) 
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zeroHead = new Node(-1) ;
        Node* ZeroTail = zeroHead ;
        
        Node* oneHead = new Node(-1) ;
        Node* oneTail = oneHead ;
        
        Node* twoHead = new Node(-1) ;
        Node* twoTail = twoHead ;
        
        Node* curr = head ;
        Node* forward = NULL ;
        
        while(curr != NULL){
            forward = curr -> next ;
            
            if(curr -> data == 0){
                ZeroTail -> next = curr ;
                ZeroTail = curr ;
                curr -> next = NULL ;
            }
            
            else {
                if(curr -> data == 1){
                    oneTail -> next = curr ;
                    oneTail = curr ;
                    curr -> next = NULL ;
                }
                
                else {
                    twoTail -> next = curr ;
                    twoTail = curr ;
                    curr -> next = NULL ;
                }
            }
            
            curr = forward ;
        }
        
        
        if(oneHead -> next != NULL){
            ZeroTail -> next = oneHead -> next ;
            oneTail -> next = twoHead -> next ;
        }
        
        else{
            ZeroTail -> next = twoHead -> next ;
        }
        
        head = zeroHead -> next ;
        
        delete(zeroHead) ;
        delete(oneHead) ;
        delete(twoHead) ;
        
        return head ;
    }
};