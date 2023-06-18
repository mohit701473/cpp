// GFG -> Stack Using Two Queues
https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1



// Expected Time Complexity: O(1) for push() and O(N) for pop() (or vice-versa).
// Expected Auxiliary Space: O(1) for both push() and pop().
void QueueStack :: push(int x)
{
    q1.push(x) ;
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty())
        return -1 ;
        
    while(q1.size() != 1){
        q2.push(q1.front()) ;
        q1.pop() ;
    }
        
    int top = q1.front() ;
    q1.pop() ;
    
    while(!q2.empty()){
        q1.push(q2.front()) ;
        q2.pop() ;
    }
    
    return top ;
}