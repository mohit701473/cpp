#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int size ;
    int* arr ;
    int front ;
    int rare ;
    
    CircularQueue(int n){
        size = n  ;
        arr = new int[size] ;
        front = -1 ;
        rare = - 1 ;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // If queue is full 
        if((front == 0 && rare == size-1) || (rare == (front-1) % (size-1))){
            return false ;
        }
        
        // Insert 1st element 
        else if(front == -1) {
            front = rare = 0 ;
        }
        
        // If rare is at size-1 & Queue not full then change the rare to 0
        // To mantain cyclic nature
        else if(rare == size-1 && front != 0) {
            rare = 0 ;
        }
        
        // All other case come here
        else{
            rare++ ;
        }
        
        arr[rare] = value ;
        return true ;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // If queue is empty
        if(front == -1) {
            return -1 ;
        }
        
        int val = arr[front] ;
        
        // If queue has a single element the front == rare
         if(front == rare) {
            front = rare = -1 ;
        }
        
        // If front is at size-1 & Queue not full then change the rare to 0
        // To mantain cyclic nature
        else if(front == size-1 && rare != 0) {
            front = 0 ;
        }
        
        // All other case
        else {
            front++ ;
        }
        
        return val ;
    }
};