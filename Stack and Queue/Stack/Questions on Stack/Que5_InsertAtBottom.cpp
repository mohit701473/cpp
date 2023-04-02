// Insert An Element At Its Bottom In A Given Stack

// Approach 1 : Itrative solution
// T.C. = O(n) 
// S.C. = O(n)
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    stack<int> st ;
    
    while(!myStack.empty()) {
        st.push(myStack.top()) ;
        myStack.pop() ;
    }
    
    myStack.push(x) ;
    
    while(!st.empty()){
       myStack.push(st.top()) ;
        st.pop() ;
    }
    
    return myStack ;
}


// Apporach 2 : Recursive Method
void solve(stack<int> &st , int x) {
    if(st.empty()){
        st.push(x) ;
        return ;
    }
    
    int num = st.top() ;
    st.pop() ;
    solve(st , x) ;
    st.push(num) ;
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack , x) ;
    
    return myStack ;
}