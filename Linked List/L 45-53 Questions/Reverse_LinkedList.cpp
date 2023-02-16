#include<bits/stdc++.h>
using namespace std ;

class Node{

    public:
    int data ;
    Node* next ;

    Node(int d) {
        this -> data = d ;
        this -> next = NULL ;
    }
};


void insertAtHead(Node* &head , int d) {
    Node* temp = new Node(d) ;

    if(head == NULL) {
        head = temp ;
    }

    else {
        temp -> next = head ;
        head = temp ;
    }
}


void insertAtTail(Node* &head , Node* &tail , int d) {
    Node* temp = new Node(d) ;

    if(head == NULL && tail == NULL) {
        head = temp ;
        tail = temp ;
    }

    else {
        tail -> next = temp ;
        tail = temp ;
    }
}


Node* reverseLL(Node* head) {

    if(head == NULL || head -> next == NULL) {
        return head ;
    }

    Node* prev = NULL ;
    Node* curr = head ;
    Node* forward = NULL ;

    while(curr != NULL) {
        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;
    }

    return prev ;
}


void print(Node* head) {
    if(head == NULL) {
        cout<<"List is empty"<<endl;
        return ;
    }


    Node* temp = head ;
    while(temp != NULL) {
        cout<< temp -> data <<" " ;
        temp = temp -> next ;
    }
}



int main() {

    Node* head = NULL ;
    Node* tail = NULL ;

    int n ;
    cout<<"Enter the no. of node"<<endl ;
    cin>>n ; 

    cout<<"enter the data"<<endl;
    for(int i = 1 ; i <= n ; i++) {
        int data ;
        // cout<<"enter the data"<<endl;
        cin>>data ;
        insertAtTail(head , tail , data) ;
        // insertAtHead(head , data) ;
    }

    print(head) ;
    head = reverseLL(head) ;
    cout<<"reverse list is"<<endl ;
    print(head) ;
    

}