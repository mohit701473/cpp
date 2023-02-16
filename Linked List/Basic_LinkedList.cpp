#include<iostream>
using namespace std ;

class Node {

    public :
    int data ;
    Node *next ;

    //constructor
    Node (int data ){
        this -> data  = data ;
        this -> next = NULL ;
    }


    //destructor
    ~Node() {
        int value = this -> data ; // this is not needed
        //memory free 
        if(this -> next != NULL){
            delete next ;
            this -> next = NULL ;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};

void insertAtHead (Node* &head , int d) 

/* Yha pr hum ne pass by referance (&head) use kiya h Q ki hum 
copy nhi banana chahte and jo humari linked list h 
usi m changes krna chahte h */

{
    /*fist we create new node bcz jis node ko insert 
    krna h use phle use create krte h */ 

    /* Second step m jo node create ki h uske next ko 
    head pr point kr vate h jo pahle NULL ko point 
    kr rha tha */ 

    /* Third step m head ko temp pr point kr vate h*/

    Node * temp = new Node(d) ;

    temp -> next = head ;

    head = temp ;
}


void insertAtTail( Node* &tail , int d )
{
    Node *temp = new Node(d) ;
    tail -> next = temp ;
    tail = tail -> next ;
}


void insertAtPosition(Node* &head , Node* &tail, int position , int d)
{
    if ( position == 1 ){
        insertAtHead (head ,d)  ;
        return ;
    }
    /* uper vala case is liye consider kiya Q ki jb position = 1 hogi to bina is case 
    ke yah function 1st position pr given node insert nhi kr payega Q ki niche humne jo temp banaya h 
    vo 1st node ko point kr rha h to last m jo 3 condition h un se given node 2nd position pr chala jayega */

    Node* temp = head ;
    int count = 1 ;

    while ( count < position-1 ){ //agar hume nth positoin pr jana h to (n-1) bar travers karna padega 
        temp = temp -> next ;
        count++ ;
    }

    // inserting at last position 
    if (temp -> next == NULL ){
        insertAtTail(tail, d) ;
        return ;
    }

    //create a node for data d 
    Node* nodeToInsert = new Node(d) ;
    nodeToInsert -> next =  temp -> next ;
    temp -> next = nodeToInsert ;
    
}

void print (Node* &head)
{
    /* Here wec create a temp node which is pointing to 
    the head or our 1st node */ 
    Node *temp = head ;

    while( temp != NULL ){
        cout<< temp -> data <<" ";
        temp = temp -> next ; /* By this hum temp ko aage bda 
        rahe h taki ko agli node ko point kre */
    }
    cout<<endl;
}

/* deleteNode function se ki given position node ko hum delete kr sakte 
  h but given value node ko delete krne ke liye function khud se likhna h */
void deleteNode( int position, Node* &head)
{
    //deletint first node
    if(position == 1){
        Node* temp = head ;
        head = head -> next ;
        //now we have to free memory of the deleting node
        /* humne ne memory ko heap m allocate kiya tha to destructor 
        se memory manualy free krvani hogi so we have to write a destructor 
        function inside the class */

        temp -> next = NULL ;
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

        previous -> next = current -> next ;
        current -> next = NULL ;
        delete current ;
    }
}

int main()
{
    //create a new node 
    Node *node1 = new Node(10) ;
    cout<<endl;
    cout<< node1 -> data <<endl;
    
    //head pointing to node1 
    Node* head = node1 ;
    Node* tail = node1 ;

    // insertAtHead(head ,12) ;

    // print(head) ;

    // insertAtHead(head ,15) ;

    // print(head) ;

    // cout<<endl;

    insertAtTail(tail ,12) ;

    print(head) ;

    insertAtTail(tail ,15) ;

    print(head) ;

    cout<<endl ;

    insertAtPosition(head , tail, 4, 22) ;
    print(head) ;
    
    cout<<"Head : "<<head -> data <<endl ;
    cout<<"Tail : "<<tail -> data <<endl ;

    deleteNode( 4, head) ;
    print(head) ;
     cout<<"Head : "<<head -> data <<endl ;
    cout<<"Tail : "<<tail -> data <<endl ;
}