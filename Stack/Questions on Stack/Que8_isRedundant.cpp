// Expression contains redundant bracket or not

// T.C. = O(n) 
int checkRedundancy(string s) {
        // code here
        stack<int> st ;
        
        for(int i=0; i<s.size(); i++) {
            
            char ch = s[i] ;
            
            // if open brckets or operators then push into stack
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch) ;
            }
            
            else {
                
                if( ch == ')' ){
                    bool isRedundant = true ;
                    
                    while(st.top() != '('){
                        
                        char top = st.top() ;
                        if(top == '+' || top == '-' || top == '*' || top == '/') {
                            isRedundant = false ;
                        }
                        st.pop() ;    
                    }
                    
                    if(isRedundant == true ){
                        return 1;
                    }
                    st.pop() ;
                }
            }
        }
        
        return 0 ;
    }