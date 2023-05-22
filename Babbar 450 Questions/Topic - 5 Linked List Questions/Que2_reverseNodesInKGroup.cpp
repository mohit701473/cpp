// LeetCode -> 25. Reverse Nodes in k-Group



// Approch - 1
// T.C. = O(N)  => O(N) + O(N/k * k)
// S.C. = O(N)
class Solution {

    int sizeOfLL(ListNode* head){

        int count=0 ;
        ListNode* temp = head ;
        while(temp != NULL){
            temp = temp -> next ;
            count++ ;
        }

        return count ;
    }

    void insertAtHead(ListNode* &head, ListNode* &tail, int val){

        ListNode* temp = new ListNode(val) ;
        if(head == NULL){
            head = tail = temp ;
            return ;
        }


        temp -> next = head ;
        head = temp ;
        
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL)
            return head ;

        ListNode* curr = head ;
        ListNode* newHead = NULL ;
        ListNode* newTail = NULL ;

        int n = sizeOfLL(head) ;  // T.C. = O(N)
        int i=0 ;
    
        while(i < n/k && curr != NULL){ // T.C. = O(n/k)
            ListNode* tempHead = NULL ;
            ListNode* tempTail = NULL ;

            for(int j=1 ; j<=k ; j++){  // T.C. = O(k)
                insertAtHead(tempHead, tempTail, curr -> val) ;
                curr = curr -> next ;
            }

            if(newHead == NULL){
                newHead = tempHead ;
                newTail = tempTail ;
            }

            else{
                newTail -> next = tempHead ;
                newTail = tempTail ;
            }

            i++ ;
        }

        if(n%k != 0)
            newTail -> next = curr ;

        return newHead ;
        
    }
};




// Approch - 2
// T.C. = O(N)  => O(N) + O(N/k * k)
// S.C. = O(1)
class Solution {

    int sizeOfLL(ListNode* head){

        int count=0 ;
        ListNode* temp = head ;
        while(temp != NULL){
            temp = temp -> next ;
            count++ ;
        }

        return count ;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL)
            return head ;

        ListNode* curr = head ;
        ListNode* newHead = NULL ;
        ListNode* newTail = NULL ;

        int n = sizeOfLL(head) ;
        int i=0 ;
    
        while(i < n/k && curr != NULL){
            ListNode* prev = NULL ;
            ListNode* forward = NULL ;
            ListNode* tempTail = curr ;

            for(int j=1 ; j<=k ; j++){
                forward = curr -> next ;
                curr -> next = prev ;
                prev = curr ;
                curr = forward ;
            }

            if(newHead == NULL){
                newHead = prev ;
                newTail = tempTail ;
            }

            else{
                newTail -> next = prev ;
                newTail = tempTail ;
            }

            i++ ;
        }

        if(n%k != 0)
            newTail -> next = curr ;

        return newHead ;
        
    }
};


