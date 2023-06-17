// Code Studio -> Implement Stack Using Deque
https://www.codingninjas.com/codestudio/problems/stack-using-deque_1170512?leftPanelTab=0



// T.C. = O(1) for each operation
// S.C. = O(1) for each operation
#include <bits/stdc++.h> 
class Stack
{
    deque<int> dq ;
    int len ;
public:
    // Initialize your data structure.
    Stack()
    {
        len = 0 ;
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        dq.push_front(x) ;
        len++ ;
        return true ;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        if(len == 0)
            return -1 ;

        int ele = dq.front() ;
        dq.pop_front() ;
        len-- ;
        return ele ;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if(len == 0)
            return -1 ;

        return dq.front() ;
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        if(len == 0)
            return true ;

        return false ;
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return len ;
    }
};