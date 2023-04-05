#include<iostream>
using namespace std ;

class queue{
    int *arr, *rear, *front , *next;
    int freespot , n ,k ;
    public:

    queue(int k, int k) {
        this-> n = n ;
        this -> k = k ;
        arr = new int[n] ;
        front = new int[k] ;       // each ith index will represent the front element of ith queue such that arr[front[ith-queue]] is front element of ith queue
        rear = new int [k] ;      // each ith index will store rear index of the ith queue
        next = new int[n] ; // this is use for finding next freespot and also use for inter link a same queue element
        freespot =  0 ;         // this will store next free sopt

        for(int i=0 ; i<k ; i++){
            front[i] = rear[i] = -1 ;
            next[i] = i+1 ;

            if(i== n-1)
                next [i] = -1 ;
        }
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
            next[rear[ith_queue - 1]] = index
        }

        // update next
        next[index] = -1 ;

        // update rear 
        rear[ith_queue -1 ] = index ;

        // push element
        arr[index] = data ;
    }
}