// Delete middle element from stack


// Approach 1 : Itrative solution or using loop
// T.C. = O(n) , n = size of the stack
// S.C. = O(n) , bcz we use another stack st 
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
//     if(N==1 || N==0) {
//         cout<<"EMPTYSTACK"<<endl;
//         return ;
//     }
    
    int count = 0 ;
    stack<int> st ;
    while(!inputStack.empty()){
        st.push(inputStack.top()) ;
        inputStack.pop() ;
        
        if(count == N/2 ) {
            st.pop() ;
        }
        count++ ; 
    }
    
    while(!st.empty()){
        inputStack.push(st.top()) ;
        st.pop() ;
    }
}


// Approach 2 : Recursive solutio
// T.C. = O(n) 
// S.C. = O(1) 
void solve(stack<int>&inputStack, int count , int size ){
    if(count == size/2) {
        inputStack.pop() ;
        return ;
    }
    
    int num = inputStack.top() ;
    inputStack.pop() ;
    solve(inputStack , count+1 , size) ;
    inputStack.push(num) ;
}

void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0 ;
    solve(inputStack , count , N) ;
}