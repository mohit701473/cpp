// 641. Design Circular Deque(LeetCode)

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

        // maintain circular flow 
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
        if( (front == 0 && rear == n-1) || (rear == (front-1) % (n-1)) ){
            return  true ;
        }

        return false ;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

