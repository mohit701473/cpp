// GFG -> Sort a stack
https://practice.geeksforgeeks.org/problems/sort-a-stack/1


// Expected Time Complexity: O(N*N)
// Expected Auxilliary Space: O(N) recursive.
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