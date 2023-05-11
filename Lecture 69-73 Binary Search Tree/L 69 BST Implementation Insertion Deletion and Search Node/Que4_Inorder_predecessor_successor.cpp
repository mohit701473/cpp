
// T.C. = O(height)
// S.C. = O(1)  
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    pre = NULL ;
    suc = NULL ;
    
    if(root == NULL)
        return ;
        
    Node* temp = root ;
    
    while(temp != NULL){
        if(temp -> key > key){
            suc = temp ;
            temp = temp -> left ;
        }
        
        else{
            temp = temp -> right ;
        }
    }
    
    temp = root ;
    while(temp != NULL){
        if(temp -> key < key){
            pre = temp ;
            temp = temp -> right ;
        }
        
        else{
            temp = temp -> left ;
        }
    }
    
    return ;

}