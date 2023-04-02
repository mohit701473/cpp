// Reverse Stack Using Recursion

void insertAtBottom(stack<int> &st , int x) {
    if(st.empty()){
        st.push(x) ;
        return ;
    }
    
    int num = st.top() ;
    st.pop() ;
    insertAtBottom(st , x) ;
    st.push(num) ;
}

void reverse(stack<int> &s){
    if(s.empty())
        return ;
    
    int num = s.top() ;
    s.pop() ;
    reverse(s) ;
    
    insertAtBottom(s , num) ;
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    reverse(stack) ;
}