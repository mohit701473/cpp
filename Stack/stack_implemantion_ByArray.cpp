#include<iostream>
using namespace std ;

class stack{
    public:
    int i, j, len ;
    int* arr ;

    // Constructor
    stack() {
        i = 0 ;
        j = -1 ;
        len = 0 ;
        arr = new int[100000] ;
    }

    void push(int data) {

        if(len >= 100000){
            cout<<"Stack Overflow"<<endl ;
            exit(1) ;
        }

        arr[i] = data ;
        i++ ;
        j++ ;
        len++ ;
    }

    void pop(){
        if(i==0){
            cout<<"Stack Underflow"<<endl ;
            exit(1) ;
        }

        i-- ;
        j-- ;
        len-- ;
    }

    int top(){
        if(i==0){
            cout<<"Stack Underflow"<<endl ;
            exit(1) ;
        }

        return arr[j] ;
    }

    int size(){

        return len ;
    }

    bool empty(){
        if(i==0)
            return 1 ;

        return 0 ;
    }
};

int main() {
    stack s;
    s.push(10) ;
    s.push(1) ;
    s.push(12) ;
    s.push(1) ;
    cout<<s.top() <<endl;
    s.pop() ;
    cout<<s.top() <<endl;
    cout<<s.size() <<endl;
    cout<<s.empty() <<endl;

}