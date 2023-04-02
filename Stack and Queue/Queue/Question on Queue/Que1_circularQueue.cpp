// 622. Design Circular Queue (LeetCode)

class MyCircularQueue {
public:
    int *arr ;
    int front, rear, n ;
    MyCircularQueue(int k) {
        arr = new int[k] ;
        n = k ;
        front = -1 ;
        rear = -1 ;
    }
    

    bool enQueue(int value) {
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
    
    bool deQueue() {
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
    
    int Front() {
        if(front == -1) 
            return -1 ;
        
        return arr[front] ;
    }
    
    int Rear() {
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

