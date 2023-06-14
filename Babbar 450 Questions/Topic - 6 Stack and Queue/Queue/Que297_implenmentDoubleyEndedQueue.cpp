// LeetCode -> 641. Design Circular Deque(LeetCode)
https://leetcode.com/problems/design-circular-deque/


// Follow these four condition to implement a doubley ended queue 
// condi. 1 -> if queue is full 
// condi. 2 -> insert/pop 1st element in/form queue
// condi. 3 -> maintain circular flow of the queue
// condi. 4 -> normal push/pop flow

// How front and rear change in the push/pop operation in dqueue
// 1. push_front(inserFront) -> front-- (only front will change)
// 2. push_back(insertLast)  -> rear++  (only rear will change and same as circular queue push operation)
// 3. pop_front(deleteFront) -> front++ (bcz push_front m front-- i.e front pichhe chala gya to pop_front m front aage aa jaye ga or pop_front in dqueue same as circular queue pop operation)
// 4. pop_back(deleteLast)   -> rear--  (bcz push_back m rear++ i.e rear aage chala gya to pop_back m rear pichhe aa jye ga)

class MyCircularDeque {
public:
    int *arr ;
    int front, rear , n ;
    MyCircularDeque(int k) {
        arr = new int[k] ;
        front = -1 ;
        rear = -1 ;
        n = k ;
    }
    
    // Jb dqueue m front m insert karenge to font pichhe jayega i.e front-- hoga 
    bool insertFront(int value) {
        // if queue is full
        if( (front == 0 && rear == n-1) || (rear == front-1) ){
            return false ;
        }

        // insert 1st element 
        if(front == -1){
            front = rear = 0 ;
            arr[front] = value ;
            return true ;
        }

        // if front is at 0th index then maintain circular flow i.e fornt ko n-1 pe le jao
        if(front == 0){
            front = n-1 ;
            arr[front] = value ;
            return true ;
        }

        // normal insertion 
        front-- ;
        arr[front] = value ;
        return true ;
    }
    

    // push_rear in dqueue same as circular queue push operation
    bool insertLast(int value) {
        // If queue is full
        if( (front == 0 && rear == n-1) || (rear == front-1) ){
            return false ;
        }

        // inert 1st element into queue
        if(front == -1 && rear == -1){
            front = rear = 0 ;
            arr[rear] = value ;
            return true ;
        }

        // if rear is at n-1 position and front is not at 0th position so apply circular condition on queue
        if(rear == n-1 && front != 0){
            rear = 0 ;
            arr[rear] = value ;
            return true ;
        }

        rear++ ;
        arr[rear] = value ;
        return true ;
    }
    

    // pop_front in dqueue same as circular queue pop operation
    bool deleteFront() {
        // If Queue is empty
        if(front == -1) 
            return false ;

        // Single element present in queue
        if(front == rear){
            front = rear = -1 ;
            return true ;
        }

        if(front == n-1){
            front = 0 ;
            return true ;
        }

        front++ ;
        return true ;
    }
    

    bool deleteLast() {
        // queue is empty
        if(front == -1 && rear == -1) 
            return false ;

        // single element in queue and pop_back is applied
        if(front == rear){
            front = rear = -1 ;
            return true ;
        }

        // maintain circular flow 
        if(rear == 0){
            rear = n-1 ;
            return true ;
        }

        //normal flow
        rear-- ;
        return true ;
    }
    
    int getFront() {
        if(front == -1) 
            return -1 ;
        
        return arr[front] ;
    }
    
    int getRear() {
        if(rear == -1) 
            return -1 ;

        return arr[rear] ;
    }
    
    bool isEmpty() {
        if(front == -1)
            return true ;
        
        return false ;
    }
    
    bool isFull() {
        if( (front == 0 && rear == n-1) || (rear == front-1) ){
            return  true ;
        }

        return false ;
    }
};


