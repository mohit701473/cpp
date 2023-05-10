
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