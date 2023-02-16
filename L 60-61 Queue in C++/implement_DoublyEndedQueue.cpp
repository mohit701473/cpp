#include <bits/stdc++.h> 
class Deque
{
public:
    int size ;
    int* arr ;
    int front ;
    int rare ;
    
    Deque(int n)
    {
        size = n ;
        arr = new int[size] ;
        front = -1 ;
        rare = -1 ;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // In this operation front will move back side like front-- 
        
        // If queue is full
        if((front == 0 && rare == size-1) || rare == (front-1) % (size-1)){
            return false ;
        }
        
        // Insert 1st element 
        else if(front == -1) {
            front = rare = 0 ;
        }
        
        // Maintain circular flow
        else if(front == 0 && rare != size-1) {
            front = size-1 ;
        }
        
        // Normal flow
        else{
            front-- ;
        }
        
        arr[front] = x ;
        return true ;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // pushRear operation same as circular queue insertion operation
        
        // If queue is full 
        if((front == 0 && rare == size-1) || rare == (front-1) % (size-1)){
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
        
        arr[rare] = x ;
        return true ;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // popFront Operation same as circular queue pop operation
        
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // In this operation rear will move back side like rear-- 
        
        // If queue is empty
        if(front == -1) {
            return -1 ;
        }
        
        int val = arr[rare] ;
        
        // If queue has a single element the front == rare
         if(front == rare) {
            front = rare = -1 ;
        }
        
        // If front is at size-1 & Queue not full then change the rare to 0
        // To mantain cyclic nature
        else if(rare == 0) {
            rare = size-1 ;
        }
        
        // All other case
        else {
            rare-- ;
        }
        
        return val ;  
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()) 
            return -1 ;
        
        return arr[front] ;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()) 
            return -1 ;
        
        return arr[rare] ;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1) 
            return true ;
        
        return false ;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rare == size-1) || (front != 0 && rare == (front-1) % (size-1))){
            return true ;
        }
        
        return false ;
    }
};