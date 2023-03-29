#include<iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;

    // Constructor
    Node(int data){
        this -> data = data ;
        this -> next = NULL ;
    }
};

class stack{
    public:
    int len ;
    Node* head ;

    // Constructor
    stack(){
        len = 0 ;
        head = NULL ;
    } 

    void push(int val){
        Node* temp = new Node(val) ;
        if(head == NULL){
            head = temp ;
            len++ ;
        }

        else{
            temp -> next = head ;
            head = temp ;
            len++ ;
        }
        
    }

    void pop() {

        if(head == NULL){
            cout<<"stack underflow"<<endl;
            exit(0) ;
        }

        Node* temp = head ;
        head = head -> next ;
        temp -> next = NULL ;
        len-- ;
        delete temp ;
    }

    int top() {
        if(head == NULL){
            cout<<"stack underflow"<<endl;
            exit(0) ;
        }

        return head -> data ;
    }

    int size(){
        return len ;
    }

    bool empty(){
        if(len == 0)
            return 1 ;
        
        return 0 ;
    }
};


int main()
{
    stack s ;
    s.push(10) ;
    s.push(12) ;
    s.push(2) ;

    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl;

    s.pop() ;
    s.pop() ;

    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl;
}