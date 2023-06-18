https://www.interviewbit.com/problems/reverse-alternate-k-nodes/


//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1
// T.C. = O(N)
// S.C. = O(1)
ListNode* Solution::solve(ListNode* A, int B) {
    int k = B ;
    
    if(k == 1)
        return A ;
        
    ListNode* curr = A ;
    ListNode* prev = NULL ;
    bool flag = true ;
    
    while(curr != NULL){
        
        if(flag){
            // reverse k nodes 
            ListNode* tempCurr = curr ;
            ListNode* tempPrev = NULL ;
            ListNode* tempForward = NULL ;
            
            for(int i=1 ; i<=k ; i++){
                tempForward = tempCurr -> next ;
                tempCurr -> next = tempPrev ;
                tempPrev = tempCurr ;
                tempCurr = tempForward ;
            }
            
            if(prev == NULL){
                prev = A ;
                A = tempPrev ;
                prev -> next = tempCurr ;
            }else {
                prev -> next = tempPrev ;
                curr -> next = tempCurr ;
            }

            curr = tempCurr ;
            flag = false ;
        }else {
            // skip alternative k nodes
            for(int i=1 ; i<=k ; i++){
                prev = curr ;
                curr = curr -> next ;
            }
                
            flag = true ;
        }
    }
    
    return A ;
}



https://leetcode.com/problems/reverse-nodes-in-k-group/

// Approch - 1
// T.C. = O(N)
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