
int countNodes(Node* head){
    int cnt = 0 ;
    Node* temp = head ;
    while(temp != NULL){
        temp = temp -> right ;
        cnt++ ;
    }

    return cnt ;
}

Node* sortedLLToBST(Node* &head, int n){ // n = no. of Nodes in LL
    // Base case
    if(n <=0 || root == NULL)
        return NULL ;

    // left part bna lo mtlb n/2 node h ukna left sub tree bna lo
    Node* left = sortedLLToBST(head, n/2) ;

    Node* root = head ;

    root -> left = left ;

    heda = head -> next ;

    root -> right = sortedLLToBST(head, n-n/2-1)  ;

    return root ;
}