


// Approch -> 1 Use another LL + Itrative way
// T.C. = O(N)   N => No. of Nodes in Linked List
// S.C. = O(N)   N => No. of Nodes in Linked List
class Solution {

    void insertAtHead(ListNode* &head, int data){
        ListNode* temp = new ListNode(data) ;
        if(head == NULL){
            head = temp ;
            return ;
        }

        temp -> next = head ;
        head = temp ;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head ;

        ListNode* head1 = NULL ;
        ListNode* temp = head ;

        while(temp != NULL){
            insertAtHead(head1, temp -> val) ;
            temp = temp -> next ;
        }


        return head1 ;
    }
};



// Approch - 2 Space Optimization + Itrative way
// T.C. = O(N) 
// S.C. = O(1)
class Solution {

public:

    ListNode* reverseList(ListNode* head) {

        if(head == NULL)
            return head ;

        ListNode* curr = head ;
        ListNode* prev = NULL ;
        ListNode* forward = NULL ;

        while(curr != NULL){
            forward = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = forward ;
        }

        head = prev ;
        
        return head ;
    }
};



// Approch - 2  Recursive solution
// T.C. = O(N) 
// S.C. = O(N)  bcz auxilary stack is use in recursion
class Solution {
    void reverseRecursive(ListNode* &curr, ListNode* &prev, ListNode* &forward, ListNode* &head){

        if(curr == NULL){
            head = prev ;
            return ;
        }

        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;

        reverseRecursive(curr, prev, forward, head) ;
    }
public: 
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head ;

        ListNode* curr = head ;
        ListNode* prev = NULL ;
        ListNode* forward = NULL ;

        reverseRecursive(curr, prev, forward, head) ;

        return head ;
    }
};