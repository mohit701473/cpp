#include<iostream>
#include<limits.h>
using namespace std ;

class queue{
    class Node{
        public:
        int data ;
        Node* next ;

        Node(int d){
            this -> data = d ;
            this -> next = NULL ;
        }
    };

    Node *head, *tail ;
    int len ;

    public:
    queue(){
        head = tail = NULL ;
        len = 0 ;
    }

    void push(int x){
        Node* temp = new Node(x) ;

        if(head == NULL){
            head = tail = temp ;
            len++ ;
            return ;
        }

        tail -> next = temp ;
        tail = temp ;
        len++ ;
    }

    void pop(){
        
        if(head == NULL){
            cout<<"Underflow"<<endl;
            return ;
        }

        Node* temp = head ;
        head = head -> next ;
        delete temp ;
        len-- ;
    }

    int size(){
        return len ;
    }

    bool empty(){
        if(size() == 0)
            return true ;

        return false ;
    }

    int front(){
        if(head == NULL){
            return INT_MAX ;
        }

        return head -> data ;
    }
};


int main()
{
    queue q ;

    q.push(1) ;
    q.push(4) ;
    q.push(5) ;

    cout<<"front -> "<<q.front() <<endl ;
    cout<<"isEmpty -> "<<q.empty() << endl ;
    cout<<"size -> "<<q.size() << endl ;

    q.pop() ;

    cout<<"front -> "<<q.front() <<endl ;
    cout<<"isEmpty -> "<<q.empty() << endl ;
    cout<<"size -> "<<q.size() << endl ;

    q.pop() ;
    q.pop() ;

    cout<<"front -> "<<q.front() <<endl ;
    cout<<"isEmpty -> "<<q.empty() << endl ;
    cout<<"size -> "<<q.size() << endl ;

    q.pop() ;
}

