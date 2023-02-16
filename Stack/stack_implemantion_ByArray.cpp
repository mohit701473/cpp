#include<iostream>
using namespace std ;

class stack {
    public:
    int *arr = NULL; 
    int top ;
    int size ;

    // Constructor
    stack(int size) {
        this -> size = size ;
        arr = new int[size] ;
        top = -1 ;
    }
 


    void push(int d) {
        if(size - top > 1) {
            top++ ;
            arr[top] = d ;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top-- ;
        }

        else{
            cout<<"stack underflow"<<endl;
        }
    }

    int peek() {
        if(top >=0 && top < size) {
            return arr[top] ;
        }
        
        cout<<"stack is empty"<<endl;
        
    }

    bool empty() {
        if(top == -1) {
            return true ;
        }
        else {
            return false ;
        }
    }
};


int main() {

    stack st(4) ; 
    st.push(2) ;
    st.push(3) ;
    st.push(1) ;

    for(int i = 0 ; i<3 ; i++) {
        cout<<st.peek()<<" ";
        st.pop() ;
    }
}
