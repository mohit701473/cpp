#include<iostream>
using namespace std ;

class kQueue{
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;
    
    public:
    kQueue(int n, int k) {
        this -> n = n ;
        this -> k = k ;
        arr = new int[n] ;
        front = new int[k] ;       // each ith index will represent the front element of ith queue such that arr[front[ith-queue]] is front element of ith queue
        rear = new int [k] ;      // each ith index will store rear index of the ith queue
        next = new int[n] ; // this is use for finding next freespot and also use for inter link a same queue element
        freespot =  0 ;         // this will store next free sopt

        for(int i=0 ; i<k ; i++){
            front[i] = -1 ;
            rear[i] = -1 ;
        }
            
        

        for(int i=0 ; i<n ; i++)
            next[i] = i+1 ;
            
        next[n-1] = -1 ;
    }

    bool push(int data, int ith_queue){
        // chech overflow i.e. array is full or not
        if(freespot == -1)
            return false ;

        // find the index where we want to insert element 
        int index = freespot ;

        // update freespot 
        freespot = next[index] ;

        // inserting 1st element into the ith queue
        if(front[ith_queue -1] == -1){
            front[ith_queue - 1] = index ;
        }

        else {
            // link element of same queue to each other
            next[rear[ith_queue - 1]] = index ;
        }

        // update next bcz now this index is not free
        next[index] = -1 ;

        // update rear 
        rear[ith_queue - 1] = index ;

        // push element
        arr[index] = data ;
        return true ;
    }

    int pop(int ith_queue){
        // check wether queue is empty of not
        if(front[ith_queue -1] == -1){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        // find the index from which you want to pop element
        int index = front[ith_queue - 1] ;

        // update the front of ith_queue
        front[ith_queue -1] = next[index] ;

        // now update next array bcz element is removed from the index so this index is free now 
        next[index] = freespot ;
        freespot = index ;

        return arr[index] ;

    }
};

int main()
{
    kQueue q(10,3) ;
    cout<<"push 10 in queue 1: "<<q.push(10,1)<<endl ;
    cout<<"push 15 in queue 1: "<<q.push(15,1)<<endl ;
    cout<<"push 20 in queue 2: "<<q.push(20,2)<<endl ;
    cout<<"push 25 in queue 1: "<<q.push(25,1)<<endl ;

    cout<<q.pop(1)<<endl;
    cout<<q.pop(2)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;

    return 0 ;

}