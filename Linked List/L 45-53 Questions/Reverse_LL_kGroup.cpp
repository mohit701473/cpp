//Reverse a Linked List in groups of given size

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


Node* reverseLL_kGroup(Node* head , int k) {


    if(head == NULL || head -> next == NULL){
        return head ;
    }

    int i = 1 ;
    
    Node* prev = NULL ;
    Node* curr = head ;
    Node* forward = NULL ;

    // step.1  reverse first k nodes
    while( (i <= k) && (curr != NULL) ) { 
        /* while( !((i <= k) ^ (curr != NULL)) ) */
        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;
        i++ ;
    }

    // step.2 recursion dekh lega 
    head -> next = reverseLL_kGroup(curr , k) ;
    // if(forward != NULL){
    //     head -> next = reverseLL_kGroup(curr , k) ;
    // }


    cout<<endl<<"recursion function called"<<endl ;



    // step.3 return head of the reversed list
    return prev ;

    // T.C(Time Complexcity) = O(n) bcz har node ko hum ek bar visit(traverse) kr rhe hai
    // S.C(Space Complexcity) = O(n) bcz if we have N nodes and the pair of reverse is K
    //  then in every recursion function call we take constant space and we call recursion funtion 
    //  N/K times so the S.C = O(N/K) = O(N) 
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
    cout<<endl ;
    // head = reverseLL(head) ;
    // cout<<"reverse list is"<<endl ;

    int k ;
    cout<<"enter the no. of pair"<<endl ;
    cin>>k ;

    head = reverseLL_kGroup(head , k) ;
    print(head) ;
    

}