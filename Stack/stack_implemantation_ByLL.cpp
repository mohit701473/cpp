#include<iostream>
using namespace std ;


class Node {
    public:
    int data ;
    Node* next ;

    //constructor 
    Node (int d) {
        this -> data = d ;
        this -> next = NULL ;
    }
};

class stack {
    Node* head ;

    public:
    stack() {
        head = NULL ;
    }

    void push(int d) {
        Node* temp = new Node(d) ;

        if(!temp) {
            cout<<"stack overflow"<<endl;
            exit(1) ;
        }

        temp -> next = head ;
        head = temp ;
    }

    void pop() {
        Node* temp = head ;

        if(head == NULL) {
            cout<<"stack under flow"<<endl;
            exit(1) ;
        }

        head = head -> next ;
        temp -> next = NULL ;

        free(temp) ;
        
    }

    int top() {
        if(head == NULL) {
            cout<<"stack under flow1"<<endl;
            exit(1) ;
        }

        return head -> data ;
    }

    bool empty() {
        if(head == NULL) {
            return true ;
        }

        return false ;
    }
};


int main() {

    stack st ;
    st.push(2) ;
    st.push(3) ;
    st.push(7) ;
    st.push(6) ;

    cout<<st.top()<<endl;
    st.pop() ;
    cout<<st.empty()<<endl;

    cout<<st.top()<<endl;
    st.pop() ;
    cout<<st.empty()<<endl;

    cout<<st.top()<<endl;
    st.pop() ;
    cout<<st.empty()<<endl;

    cout<<st.top()<<endl;
    st.pop() ;
    cout<<st.empty()<<endl;

    // cout<<st.top()<<endl;
    // st.pop() ;
    // cout<<st.empty()<<endl;
    
    
}