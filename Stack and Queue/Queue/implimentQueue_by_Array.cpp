#include <bits/stdc++.h> 
class Queue {
public:
    int *arr ;
    int top, rear ;
    Queue() {
        arr = new int[10000000] ;
        top = 0 ;
        rear = 0 ;

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
         if(top == rear)
            return true ;
        
        return false ;
    }

    void enqueue(int data) {
        arr[rear] = data ;
        rear = rear + 1 ;
    }

    int dequeue() {
        if(top == rear)
            return -1 ;

        int val = arr[top] ;
        top = top + 1 ;
        return val ;
    }

    int front() {
        if(top == rear)
            return -1 ;

        return arr[top] ;
    }
};

