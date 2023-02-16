#include<iostream>
using namespace std ;

class Node {

    public :
    int data ;
    Node *next ;

    //constructor
    Node (int d ){
        this -> data  = d ;
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


void insertNode(Node* &tail , int element , int d) {

    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d) ;
        tail = newNode ;
        newNode -> next = newNode ;
    }

    else{
        // Non empty list
        // Assuming that data is persent in the list

        Node* current = tail ;

        while(current -> data != element){
            current = current -> next ;
        }

        // Element found & now current is representing the element 
        Node* temp = new Node(d) ;  // Creating a new Node
        temp -> next = current -> next ;
        current -> next = temp ;
    }
}


void print(Node* tail){

    Node* temp = tail ;

    if(tail == NULL){
        cout<<"list is empty"<<endl;
    }

    do{
        cout<<tail -> data <<" ";
        tail = tail -> next ;
    } while(tail != temp);

    cout<<endl;
    
    // // single node ko is se print nhi kr skte h
    // while(tail -> next != temp){
    //     cout<<tail -> data <<" ";
    //     tail = tail -> next ;
    // }
}


void deleteNode(Node* &tail , int value){

    // empty list
    if(tail == NULL){
        cout<<" List is empty"<<endl ;
        return ;
    }

    else{
        //non empty list 

        // Assuming that value is persent in the list
        Node* previous = tail ;
        Node* current = previous -> next ;

        while(current -> data != value){
            previous = current ;
            current = current -> next ;
        }

        previous -> next = current -> next ;

        // 1 node linked list
        if(current == previous){
            tail = NULL ;
        }

        // no. of node >= 2 
        else if(tail == current){
            // mtlb ki jis node ko delet krna ho & tail bhi usi ko point kre 
            // to hume tail ko update krna padega
            tail = previous ;
            // yah hum ne tail ko previous pr point krva diya circular 
            // linked list h to tail kisi ko point kre usk effect nhi pdata h
        }
        current -> next = NULL ;
        delete current ;
    }
}


int main()
{
    Node* tail = NULL ;

    //empty list 
    insertNode(tail , 5 , 3) ;
    print(tail) ;

    insertNode(tail , 3 , 5) ;
    print(tail) ;

     insertNode(tail , 5 , 7) ;
    print(tail) ;

    insertNode(tail , 7 , 5) ;
    print(tail) ;

    insertNode(tail , 5 , 10) ;
    print(tail) ;

    deleteNode(tail , 3) ;
    print(tail) ;
}
