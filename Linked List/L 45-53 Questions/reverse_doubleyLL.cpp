#include<iostream>
using namespace std ;

class Node {

    public:
    int data ;
    Node* next ;
    Node* prev ;

    Node(int d) {
        this -> data = d ;
        this -> next = NULL ;
        this -> prev = NULL ;
    }
};


void insertAtTail(Node* &head , Node* &tail , int d) {

    Node* temp = new Node(d) ;
    if(head == NULL && tail == NULL) {
        head = tail = temp ;
        return ;
    }

    tail -> next = temp ;
    temp -> prev = tail ;
    tail = temp ;

    return ;
}


void print(Node* head ) {

    if(head == NULL) {
        cout<<"List is empty"<<endl;
        return ;
    }

    Node* temp = head ;
    cout<<"list is"<<endl ;
    while(temp != NULL) {
        cout<<temp -> data <<" " ;
        temp = temp -> next ;
    }

    return ; 
}


Node* reverseList(Node* head) {

    // If lits is empty
    if(head == NULL) {
        return head ;
    }


    Node* temp = head ;
    Node* forward = NULL ;
    Node* new_head = NULL ;

    while(temp != NULL) {
        // Store the hdead of the reversed list
        if(temp -> next == NULL) {
            new_head = temp ;
        }

        // Logic for reversing Doubley Linked List
        forward = temp -> next ;
        temp -> next = temp -> prev ;
        temp -> prev = forward ;
        temp = forward ;
    }

    return new_head ;

    // T.C(Time Complexcity) = O(n)  bcz we traverse every Node only ones ;
    // S.C(Space Complexcity) = O(1) bsz it take constant space bcz solution is itrative
}


int main() 
{
    Node* head = NULL ;
    Node* tail = NULL ;

    // print(head) ;

    int n ;
    cout<<"enter the no. of Nodes"<<endl ;
    cin>>n ;

    cout<<"enter the data"<<endl ;
    for(int i = 1 ; i <= n ; i++) {
        int data ;
        cin>>data ;
        insertAtTail(head , tail , data) ;
    }

    print(head) ;

    head = reverseList(head) ;

    cout<<endl ;
    print(head) ;
}