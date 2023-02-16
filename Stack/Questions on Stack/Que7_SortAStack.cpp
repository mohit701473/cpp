// Sort a stack

// Apporach 1 : Itrative Method
// T.C. = O(n*n) 
// S.C. = O(n)
void SortedStack :: sort()
{
   //Your code here
   stack<int> st ;
   
   while(!s.empty()) {
       
       int num = s.top() ;
       s.pop() ;
       while(!st.empty() && st.top() < num) {
           s.push(st.top()) ;
           st.pop() ;
       }
       
       st.push(num) ;
   }
   
   while(!st.empty()) {
       s.push(st.top()) ;
       st.pop() ;
   }
   
}


// Apporach 2 : Recursive Method
void sort(stack<int> &s , stack<int> &st , int num , int size) {
    if(s.empty() && st.size() == size) 
        return ;
    
    if(!st.empty()){
        if(num > st.top()) {
            s.push(st.top()) ;
            st.pop() ;
            sort(s , st , num , size) ;
        }
        
        else {
            st.push(num) ;
            if(!s.empty()){
                num = s.top() ;
                s.pop();
            }
            sort(s , st , num , size) ;
        }
    }
    
    else{
        st.push(num) ;
        num = s.top() ;
        s.pop() ;
        sort(s , st , num , size) ;
    }
}

void insert(stack<int> &s , stack<int> &st){
    if(st.empty()) 
        return ;
    
    int num = st.top() ;
    st.pop() ;
    s.push(num) ;
    insert(s , st) ;
}

void SortedStack :: sort()
{
    extern void sort(stack<int> &s , stack<int> &st , int num , int size) ;
    extern void insert(stack<int> &s , stack<int> &st) ;
    
    
    int size = s.size() ;
    stack<int> st ;
    int num = s.top() ;
    s.pop() ;
    
    // if we have only s contain only 1 element then
    if(s.empty()){
        s.push(num) ;
    }
    
    else{
        sort(s , st , num , size) ;
        insert(s , st) ;
    }
    
}


// Apporach 3 : Rcursive Mrthod 

void sortedInsert(stack<int> &s , int num ) {
    // base case 
    if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num) ;
        return ;
    }
    
    int n = s.top() ;
    s.pop() ;
    
    // recursive call
    sortedInsert(s , num) ;
    
    s.push(n) ;
}

void sortStack(stack<int> &s) {
    // base case 
    if(s.empty()) 
        return ;
        
    int num = s.top() ;
    s.pop() ;
    
    // recursive call
    sortStack(s) ;
    
    // jum stack empty ho jaye & hum vaps aaye to num ko uski sorted position m insert krne ke liye sortedInsert function ko call krte h
    sortedInsert(s , num) ;
}

void SortedStack :: sort()
{
    extern void sortStack(stack<int> &s) ;
    extern void sortedInsert(stack<int> &s , int num ) ;
    
    sortStack(s) ;
}