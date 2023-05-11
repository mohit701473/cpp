

// By this we convert a BST into sordet Doubley Linked List and if it is a binary Tree then it is a simple Doubley Linked List only
void convertBSTIntoDoubleyLL(Node* root, Node* head){
    // Base case
    if(root == NULL)
        return NULL ;

    convertBSTIntoDoubleyLL(root -> right, head) ;

    root -> right = head ;

    if(head != NULL)  // head == NULL means that there is no sub tree in the right part of the root
        head -> left = root ;

    head = root ;

    convertBSTIntoDoubleyLL(root -> left, head) ;
}


// Merge two sorted LL
Node* mergeLL(Node* head1, Node* head2){
    Node* head = NULL ;
    Node* tail = NULL ;

    while(head1 != NULL && head2 != NULL){
        if(head1 -> data < head2 -> data){
            if(head == NULL){
                head = head1 ;
                tail = head1 ;
                head1 = head1 -> right
            }

            else{
                tail -> right = head1 ;
                head1 -> left = tail ;
                tail = head1 ;
                head1 = head1 -> right ;
            }
        }

        else{
            if(head == NULL){
                head = head2 ;
                tail = head2 ;
                head2 = head2 -> right ;
            }

            else{
                tail -> right = head2 ;
                head2 -> left = tail ;
                tail = head2 ;
                head2 = head2 -> right ;
            }
        }
    }

    while(head1 != NULL){
        tail -> right = head1 ;
        head1 -> left = tail ;
        tail = head1 ;
        head1 = head1 -> right ;
    }

    while(head2 != NULL){
        tail -> right = head2 ;
        head2 -> left = tail ;
        tail = head2 ;
        head2 = head2 -> right ;
    }
}


// Count the no. of Nodes in LL
int countNodes(Node* head){
    int cnt = 0 ;
    Node* temp = head ;
    while(temp != NULL){
        temp = temp -> right ;
        cnt++ ;
    }

    return cnt ;
}

// Convert sortde LL into BST
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


Node* mergeBST(Node* root1, Node* root2){

    // step -> 1 convert BST into sorted Doubley LL in-place i.e. no extra memory is used
    Node* head1 = NULL ;
    convertBSTIntoDoubleyLL(root1, head1) ;
    head1 -> left = NULL ;

    Node* head2 = NULL ;
    convertBSTIntoDoubleyLL(root2, head2) ;
    head2 -> left = NULL ;

    // step -> 2 merge two sorted LL
    Node* head = mergeLL(head1, head2) ;

    // step -> 3 Convert sortde LL into BST
    return sortedLLToBST(head, countNodes(head)) ;
}


