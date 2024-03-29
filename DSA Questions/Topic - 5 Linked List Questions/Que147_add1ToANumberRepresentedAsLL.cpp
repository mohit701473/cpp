// GFG ->  Add 1 to a number represented as linked list
https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
*/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1 using recursion
// T.C. = O(N)
// S.C. = O(N) recursive stack space
class Solution
{
    public:
    
    int solve(Node* curr){
        if(curr -> next == NULL){
            if(curr -> data + 1 > 9){
                curr -> data = 0 ;
                return 1 ;
            }
            
            else{
                curr -> data += 1 ;
                return 0 ;
            }
        }
        
        int p = solve(curr -> next) ;
        
        if(p == 1){
            if(curr -> data + 1 > 9){
                curr -> data = 0 ;
                return 1 ;
            }
            
            else{
                curr -> data += 1 ;
                return 0 ;
            }
        }
        
        return 0 ;
    }
    
    Node* addOne(Node *head) 
    {
        int ans = solve(head) ;
        if(ans == 1){
            Node* temp = new Node(1) ;
            temp -> next = head ;
            head = temp ;
        }
        
        return head ;
    }
};



// Approch - 1 reverse LL + Itration
// T.C. = O(N)
// S.C. = O(1) 
class Solution
{
    public:
    
    Node* reverseLL(Node* head){
        if(head == NULL)
            return head ;

        Node* curr = head ;
        Node* prev = NULL ;
        Node* forward = NULL ;

        while(curr != NULL){
            forward = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = forward ;
        }

        head = prev ;
        
        return head ;
    }
    
    Node* addOne(Node *head) 
    {
        head = reverseLL(head) ;
        
        Node* curr = head ;
        
        if(curr -> data + 1 == 10){
            curr -> data = 10  ;
            
            while(curr -> next != NULL){
                
                if(curr -> data == 10){
                    curr -> data = 0 ;
                    curr -> next -> data += 1 ;
                }
                else break ;
                
                curr = curr -> next ;
            }
            
            if(curr -> next == NULL && curr -> data == 10){
                    curr -> data = 0 ;
                    Node* temp = new Node(1) ;
                    curr -> next = temp ;
                }
            
        }
        
        else curr -> data += 1 ;
        
        return reverseLL(head) ;
    }
};