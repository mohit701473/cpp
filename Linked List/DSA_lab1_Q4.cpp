// Reverse the linked list 

#include<iostream>
using namespace std ;

class Node
{
    public:
    int data ;
    Node* next ;

    Node(int d){
        //cout<<"constructor called"<<endl;
        this -> data = d ;
        this -> next = NULL ;
    }
};



void insertAtHead(Node* &head , int d){

    if(head == NULL){
        Node* temp = new Node(d) ;
        head = temp ;
    }

    else{
        Node* temp = new Node(d) ;
        temp -> next = head ;
        head = temp ;
    }
}



void print(Node* &head){
    if(head == NULL){
        cout<<"list is empty";
        return ;
    }

    else{
        Node* temp = head ;
        cout<<"list is"<<endl ;
        while(temp != NULL){
            cout<< temp -> data<<" ";
            temp = temp -> next ;
        }
    }
}

void reverseLinkedList(Node* &head){

    if(head == NULL){
        cout<<"list is empty"<<endl;
        return ;
    }

    else{
        
    }
}


int main()
{
    //Node* newNode = new Node(1) ;
    Node* head = NULL ;

    insertAtHead(head , 5) ;
    insertAtHead(head , 4) ;
    insertAtHead(head , 3) ;
    insertAtHead(head , 2) ;
    insertAtHead(head , 1) ;

    print(head) ;



}