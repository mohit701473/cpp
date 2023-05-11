

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