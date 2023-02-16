#include<iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* prev ;
    Node* next ;

    // Create a constructor
    Node(int d){
        this -> data = d ;
        this -> prev = NULL ;
        this -> next = NULL ;
    }

    // Distructor for deleting the node
    ~Node() {
        int val = this -> data ;
        if(next != NULL){
            delete next ;
            next = NULL ;
        }
        cout << "memory free for node with data "<<val <<endl;
    }
};


// Function for printing the linked list
void print(Node* head , Node* tail){
    Node* temp = head ;
    while (temp != NULL)
    {
        cout << temp -> data <<" " ;
        temp = temp -> next ;
    }
    cout<<endl;
    cout<<"head :"<<head -> data<<endl;
    cout<<"tail :"<<tail -> data<<endl;
    cout<<endl;

}


// Function for get the length of the doublyv linked list
int getLength(Node* head){
    Node* temp = head ;
    int len = 0 ;
    while (temp != NULL)
    {
        len++ ;
        temp = temp -> next ;
    }
    cout<<endl;

    return len ;
}


// Insert the new node at head
void insertAtHead(Node* &head , Node* & tail , int d) {
    // Jub insertAtHead(Node* &head , int d) m &head nhi lagate h to ky effect hota h 

    // Empty list
    if(head == NULL){
        Node* temp = new Node(d) ;
        head = temp ;
        tail = temp ;
    }

    else{
        Node* temp = new Node(d) ;
    temp -> next = head ;
    head -> prev = temp ;
    head = temp ;
    //print(head)
    }
   
}


// Insert new node at tail
void insertAtTail(Node* &tail , Node* &head , int d) {
    if(tail == NULL){
        Node* temp = new Node(d) ;
        tail = temp ;
        tail = temp ;
        head = temp ;
    }

    else{
        Node* temp = new Node(d) ;
        tail -> next = temp ;
        temp -> prev = tail ;
        tail = temp  ;
    }
}


// Insert a new node at any position
void insertAtPosition(Node* &head , Node* &tail , int position , int d){
    if(position == 1){
        insertAtHead(head , tail , d) ;
    }

    Node* temp = head ;
    int count = 1 ;

    while ( count < position-1 ){ //agar hume nth positoin pr jana h to (n-1) bar travers karna padega 
        temp = temp -> next ;
        count++ ;
    }

    // inserting at last position 
    if (temp -> next == NULL ){
        insertAtTail(tail, head ,d) ;
        return ;
    }

    //create a node for data d 
    Node* nodeToInsert = new Node(d) ;
    nodeToInsert -> next =  temp -> next ;
    temp -> next -> prev = nodeToInsert ; 
    temp -> next = nodeToInsert ;
    nodeToInsert -> prev = temp ;
}


/* deleteNode function se ki given position node ko hum delete kr sakte 
  h but given value node ko delete krne ke liye function khud se likhna h */
void deleteNode( int position, Node* &head)
{
    //deletint first node
    if(position == 1){
        Node* temp = head ;
        temp -> next -> prev = NULL;
        head = temp -> next ;
        temp -> next = NULL ;
        //now we have to free memory of the deleting node
        /* humne ne memory ko heap m allocate kiya tha to destructor 
        se memory manualy free krvani hogi so we have to write a destructor 
        function inside the class */

        delete temp ;

    }
    else{
        //deleting any node for given position 
        Node* current = head ;
        Node* previous = NULL ;

        int count = 1 ;
        while(count < position){
            previous = current ;
            current = current -> next ;
            count++ ;
        }

        current -> prev = NULL ;
        previous -> next = current -> next ;
        current -> next = NULL ;
        delete current ;
    }
}


int main()
{
    // Node* node1 = new Node(10) ;
    // Node* head = node1 ;
    // Node* tail = node1 ;

    // Jub starting m koi node nhi mtlb head & tail dono NULL ho to h to insertAtHead & insertAttail vale functions m modification krna padega
    Node* head = NULL ;
    Node* tail = NULL ;
    insertAtHead(head, tail ,  11) ;
    print(head,tail) ;

    insertAtHead(head, tail ,13) ;
    print(head,tail) ;

    insertAtHead(head, tail , 17) ;
    print(head,tail) ;

    insertAtHead(head, tail ,8) ;
    print(head,tail) ;

    insertAtTail(tail ,head , 25) ;
    print(head,tail) ;

    insertAtPosition(head , tail , 3 , 100) ;
    print(head,tail) ;

    deleteNode(1 , head) ;
    print(head,tail) ;

    deleteNode(2, head) ;
    print(head,tail) ;

    deleteNode(3, head) ;
    print(head,tail) ;
    // H.W. last node ko delete kr ne ke bad tail ko kese correct position pr laye
}