#include<iostream>
#include<limits.h>
using namespace std ;


// T.C. = O(1) for push, pop, getMid and deleteMid poeration in the following stack
// s.c. = O(N) bcz linked list take space
class stack{

    class Node{
        public:
        int data ;
        Node* next ;
        Node* prev ;

        Node(int d){
            this -> data = d ;
            this -> next = NULL ;
            this -> prev = NULL ;
        }
    };

    int *arr ;
    int len ;
    Node *head, *mid, *back ;

    public:
    stack(){
        arr = new int[1000] ;
        len = 0 ;
        head = back = mid = NULL ;
    }

    void push(int val){

        Node* temp = new Node(val) ;
        if(head == NULL){
            head = temp ;
            mid = temp ;
            len++ ;
            return ;
        }

        temp -> next = head ;
        head -> prev = temp ;
        head = temp ;
        len++ ;

        if(len%2 != 0){// odd length stack
            mid = back ;
        }

        back = mid -> prev ;
    }

    int pop(){
        if(head == NULL){
            cout<<"stack underflow " ;
            return INT_MAX ;
        }

        Node* temp = head ;
        int ans = temp -> data ;
        head = temp -> next ;
        delete temp ;
        len-- ;

        if(len%2 == 0){
            back = mid ;
            mid = mid -> next ;
        }

        return ans ;
    }

    int getMid(){
        if(head == NULL){
            cout<<"stack underflow " ;
            return INT_MAX ;
        }

        return mid -> data ;
    }

    void deleteMid(){
        if(head == NULL){
            cout<<"stack underflow "<<endl;
            return ;
        }

        if(mid == head){
            delete mid ;
            head = NULL ;
            return ;
        }

        Node* temp = mid ;
        back -> next = temp -> next;
        delete temp ;
        len-- ;

        if(len%2 == 0){ // even length stack
            mid = back -> next ;
            back = back ;
        }else{
            mid = back ;
            back = mid -> prev ;
        }
    }

};


int main()
{
    stack st ;
    st.push(20) ;
    st.push(2) ;
    st.push(30) ;
    st.push(10) ;
    st.push(16) ;
    // st.push(18) ;
    // st.push(22) ;

    cout<<"stack mid -> "<<st.getMid()<<endl;

    st.pop() ;
    st.pop() ;

    cout<<"stack mid -> "<<st.getMid()<<endl;

    st.deleteMid() ;
    st.deleteMid() ;

    cout<<"stack mid -> "<<st.getMid()<<endl;
}