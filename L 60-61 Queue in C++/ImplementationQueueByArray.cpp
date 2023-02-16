#include<iostream>
using namespace std ;

class queue{

    int size ;
    int* arr ;
    int front ;
    int rare ;

    public:

    // Constructor 
    queue(int n) {
        this -> size = n ;
        arr = new int[n] ;
        this -> front = 0 ;
        this -> rare = 0 ;
    }

    // For push operation
    void push(int data) {

        if(rare >= size) {
            cout<<"queue overflow"<<endl;
            exit(1) ;
        }

        else{
            arr[rare] = data ;
            rare++ ;
        }

    }

    // For pop operation
    void pop() {
        if(rare == front ) {
            cout<<"Queue underflow"<<endl;
            exit(1) ;
        }

        else{
            arr[front] = -1 ;
            front++ ;
            if(front == rare) {
                front = 0;
                rare = 0 ;
            }
        }
    }

    // For front operation
    int top() {
        if(front == rare) {
            cout<<"queue underflow"<<endl;
            exit(1) ;
        }

        return arr[front] ;
    }

    // For empty operation
    bool empty() {
        if(front == rare ) {
            return true ;
        }

        return false ;
    }
};

int main() 
{
    queue q(5) ;

    q.push(4) ;
    q.push(5) ;
    q.push(2) ;

    cout<<"front: "<<q.top()<<endl;
    cout<<"is Empty: "<<q.empty()<<endl;

    q.pop() ;

    cout<<"front: "<<q.top()<<endl;
    cout<<"is Empty: "<<q.empty()<<endl;

    q.pop() ;
    q.pop() ;
    
    cout<<"is Empty: "<<q.empty()<<endl;
    cout<<"front: "<<q.top()<<endl;
    

}