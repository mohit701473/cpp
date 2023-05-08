// Flatten binary tree to linked list

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)
 
void flatten(Node *root)
    {
        Node* curr = root ;
        while(curr != NULL){
            if(curr -> left){
                Node* pred = curr -> left ;
                while(pred -> right)
                    pred = pred -> right ;
                    
                pred -> right = curr -> right ;
                curr -> right = curr -> left ;
                curr -> left = NULL ;
            }
            
            curr = curr -> right ;
        }
    }