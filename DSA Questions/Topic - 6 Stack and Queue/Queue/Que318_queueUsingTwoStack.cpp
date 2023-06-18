// GFG -> Queue using two Stacks
https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1



// Expected Time Complexity : O(1) for push() and O(N) for pop() or O(N) for push() and O(1) for pop()  
// Expected Auxilliary Space : O(1).

class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; 

void StackQueue :: push(int x)
{
    s1.push(x) ;
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top()) ;
            s1.pop() ;
        }
    }
    
    if(s2.empty())
        return -1 ;
        
    int ans = s2.top() ;
    s2.pop() ;
    
    return ans ;
}
