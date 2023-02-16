//

bool isCircularList(Node* head) {

    // Caes.1 empty list
    if(head == NULL) {
        return true ;
    }

    // Caes.2 no. of Node >= 1
    Node* temp = head -> next ;
    while(temp != NULL && temp != head) {
        temp = temp -> next ;
    }

    // if list is circular
    if(temp == head){
        return true ;
    }

    // if list is singly 
    return false ;

    // T.C = O(n) bcz we are traversing every node 
    // S.C = O(1) bcz it is a itrative solution and constant sapce is used
}