#include<iostream>
#include<limits.h>
using namespace std ;

class queue{
    int* arr ;
    int frontIdx , rearIdx, len ;

    public:
    queue(){
        arr = new int[1000] ;
        frontIdx = -1 ;
        rearIdx = 0 ;
        len =  0 ;
    }

    void push(int x){
        if(rearIdx >= 1000){
            cout<<"Overflow"<<endl;
            return ;
        }

        if(frontIdx == -1){
            arr[rearIdx] = x ;
            len++ ;
            frontIdx++ ;
            rearIdx++ ;
            return ;
        }

        arr[rearIdx] = x ;
        len++ ;
        rearIdx++ ;
    }

    void pop(){
        if(frontIdx == rearIdx){
            cout<<"Underflow"<<endl;
            return ;
        }

        frontIdx++ ;
        len-- ;
    }

    int size(){
        return len ;
    }

    bool empty(){
        if(size() ==  0)
            return true ;

        return false ;
    }

    int front(){
        if(empty())
            return INT_MAX ;

        return arr[frontIdx] ;
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
}