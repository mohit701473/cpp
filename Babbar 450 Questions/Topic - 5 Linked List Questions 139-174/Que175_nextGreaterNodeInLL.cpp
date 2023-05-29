// Leet Code -> 1019. Next Greater Node In Linked List
https://leetcode.com/problems/next-greater-node-in-linked-list/description/



//------------------------------------------------------------   Solution    ----------------------------------------------------------------------


// Approch - 1  
// T.C. = O(N^2)
// S.C. = O(N) 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> ans ;
        ListNode* curr = head ;
        
        while(curr != NULL){
            ListNode* temp = curr -> next ;
            bool flag = true ;
            while(temp != NULL){
                if(temp -> val > curr -> val){
                    ans.push_back(temp -> val) ;
                    flag = false ;
                    break ;
                }

                temp = temp -> next ;
            }

            if(flag)
                ans.push_back(0) ;

            curr = curr -> next ;
        }

        return ans ;
    }
};