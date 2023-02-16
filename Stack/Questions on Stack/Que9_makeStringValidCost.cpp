// Minimum Cost To Make String Valid (Code Studio )

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
    
    int len = str.length() ;
    if(len % 2 != 0) 
        return -1 ;
    
    stack<char> s ;
    
    for(int i =0 ; i<len ; i++) {

        char ch = str[i] ;
        if(ch == '{') 
            s.push(ch) ;
        
        else {
            if(!s.empty() && s.top() == '{') {
                s.pop() ;
            }
            else{
                s.push(ch) ;
            }
        }
    }
    
    if(s.empty()) 
        return 0 ;
    
    // a for open brackets counting
    // b for close brackets counting
    int a = 0 ;
    int b = 0 ;
    while(!s.empty()) {
        
        if(s.top() == '{'){
            a++ ;
        }
        
        else{
             b++ ;
        }    
        s.pop() ;
    }
    
    return ((a+1)/2 + (b+1)/2) ;
}