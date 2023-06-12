#include<iostream>
#include<limits.h>
using namespace std ;

class stack{
    class Node{
        public:
        int data ;
        Node* next ;

        Node(int d){
            this -> data = d ;
            this -> next = NULL ;
        }
    };

    Node* head ;
    int len ;

    public:
    stack(){
        this -> head = NULL ;
        len = 0 ;
    }

    void push(int val){
        Node* temp = new Node(val) ;

        if(head == NULL){
            head = temp ;
            len++ ;
            return ;
        }

        temp -> next = head ;
        head = temp ;
        len++ ;
    }

    void pop(){
        if(head == NULL){
            cout<<"Stack Underflow"<<endl;
            return ;
        }

        Node* temp = head ;
        head = head -> next ;
        len-- ;
        delete temp ;
    }

    int top(){
        if(head == NULL){
            cout<<"Stack Underflow"<<endl;
            return INT_MIN ;
        }

        return head -> data ;
    }

    int size(){
        return len ;
    }

    bool empty(){
        if(head == NULL)
            return true ;

        return false ;
    }
};


int main()
{
    stack st ;
    st.push(20) ;
    st.push(2) ;
    st.push(30) ;

    cout<<"stack top -> "<<st.top()<<endl;
    cout<<"stack size -> "<<st.size()<<endl;
    cout<<"stack is empty -> "<<st.empty()<<endl;

    st.pop() ;
    st.pop() ;

    cout<<"stack top -> "<<st.top()<<endl;
    cout<<"stack size -> "<<st.size()<<endl;
    cout<<"stack is empty -> "<<st.empty()<<endl;

    st.pop() ;

    cout<<"stack top -> "<<st.top()<<endl;
    cout<<"stack size -> "<<st.size()<<endl;
    cout<<"stack is empty -> "<<st.empty()<<endl;

}