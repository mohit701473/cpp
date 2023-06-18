#include<iostream>
#include <limits.h>
using namespace std ;

class stack{
    
    int *arr ;
    int count ;
    int topIdx ;

    public:
    stack(){
        arr = new int[1000] ;
        count = 0 ;
        topIdx = -1 ;
    }

    void push(int data){
        if(count >= 10000){
            cout<<"Stack Overflow"<<endl;
            return ;
        }

        topIdx++ ;
        arr[topIdx] = data ;
        count++ ;
    }

    void pop(){
        if(count == 0 || topIdx == -1){
            cout<<"Stack Underflow"<<endl;
            return ;
        }

        topIdx-- ;
        count-- ;
    }

    int top(){
        if(count == 0 || topIdx == -1){
            cout<<"Stack Underflow"<<endl;
            return INT_MIN;
        }

        return arr[topIdx] ;
    }

    int size(){
        return count ;
    }

    bool empty(){
        if(count == 0 || topIdx == -1){
            return true ;
        }

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