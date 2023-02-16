// Add two numbers represented by linked lists

// T.C. = O(M+N) 
// S.C. = O(max(M,N))

class Solution
{
    struct Node* reverseLL(struct Node* head) {

        if(head == NULL || head -> next == NULL) {
            return head ;
        }
    
        struct Node* prev = NULL ;
        struct Node* curr = head ;
        struct Node* forward = NULL ;
    
        while(curr != NULL) {
            forward = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = forward ;
        }
    
        return prev ;
    }
    
    
    void insertAtTail(struct Node* &head , struct Node* &tail , int d) {
        struct Node* temp = new Node(d) ;
    
        if(head == NULL && tail == NULL) {
            head = temp ;
            tail = temp ;
        }
    
        else {
            tail -> next = temp ;
            tail = temp ;
        }
    }
    
    struct Node* add(struct Node* first , struct Node* second) {
        int carry = 0 ;
        struct Node* ansHead = NULL ;
        struct Node* ansTail = NULL ;
        while(first != NULL || second != NULL || carry != 0){
            
            int val1 = 0 ;
            if(first != NULL) 
                val1 = first -> data ;
                
            int val2 = 0 ;
            if(second != NULL)
                val2 = second -> data ;
            
            int sum = carry + val1 + val2 ;
            carry = sum / 10 ;
            int digit = sum % 10 ;
            
            insertAtTail(ansHead , ansTail , digit) ;
            
            if(first != NULL) 
                first = first -> next ;
                
            if(second != NULL) 
                second = second -> next ;
                
        }
        
        return ansHead ;
        
    }
    
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverseLL(first) ;
        second = reverseLL(second) ;
        
        struct Node* ans = add(first , second) ;
        
        ans = reverseLL(ans) ;
        return ans ;
        
    }
};


// Erro to store val bcz int can't store pow function value bcz it excced the int value
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0 , num2 = 0 , i = 0 , j = 0 , sum ;
        ListNode* temp1 = l1 ;
        ListNode* temp2 = l2 ;

        

        while(temp1 != NULL) {
            num1 = (temp1 -> val) * pow(10 , i) + num1 ;
            i++ ;
            temp1 = temp1 -> next ;
        }

        while(temp2 != NULL) {
            num2 = (temp2 -> val) * pow(10 , j) + num2 ;
            j++ ;
            temp2 = temp2 -> next ;
        }

        sum = num1 + num2 ;
        ListNode* head = NULL;
        ListNode* tail = NULL ;

        if(sum == 0) {
            ListNode* temp = new ListNode(0) ;
            head = temp ;
            return head ;
        }
 
        while(sum != 0) {
            int r = sum % 10 ;
            ListNode* temp = new ListNode(r) ;
            sum = sum / 10 ;
            if(head == NULL && tail == NULL) {
                head = temp ;
                tail = temp ;
            }

            else {
                tail -> next = temp ;
                tail = temp ;
            }
        }

        // while( head != NULL && head -> val == 0) {
        //     head = head -> next ;
        // }

        return head ;
    }
};

