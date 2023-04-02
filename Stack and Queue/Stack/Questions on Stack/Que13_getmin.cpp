// Get minimum element from stack (gfg)

// T.C. = O(1) 
// S.C. = O(n) 
class solutio{

    int minEle;
        stack<int> s;
        
        public:
        
        stack<int> st ;
        int min = INT_MAX ;
        
        /*returns min element from stack*/
        int getMin(){
            
            if(s.empty()){
                return -1 ;
                
            }
            
            if(!st.empty() && !s.empty()){
                return st.top() ;
            }
            
        }
        
        /*returns poped element from stack*/
        int pop(){
            
            if(s.empty()) {
                return -1 ;
            }
            
            else{
                int num = s.top() ;
                s.pop() ;
                if(!st.empty()){
                    st.pop() ;
                }
                
                return num ;
            }
            
        }
        
        /*push element x into the stack*/
        void push(int x){
            
            if(s.empty()) {
                
                st.push(x) ;
                s.push(x) ;
            }
            
            else {
                if(x < st.top()) {
                    
                    st.push(x) ;
                    s.push(x) ;
                }
                else{
                    st.push(st.top()) ;
                    s.push(x) ;
                }
            }
        }

};



// T.C. = O(1)
// S.C. = O(1)
// Imp formula in push "val = 2*curr - mini"   
// Imp formula in pop " val = 2*mini - curr" here curr = s.top()
class solution{
    
    int minEle;
    stack<int> s;
    
    public:
    
    int mini = INT_MAX ;
    
       /*returns min element from stack*/
       int getMin(){
           
           if(s.empty()){
               return -1 ;
               
           }
           
           return mini ;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           if(s.empty()) {
               return -1 ;
           }
           
           int curr = s.top() ;
           s.pop() ;
           if(curr > mini){
               
               return curr ;
           }
           
           else {
               int prevMin = mini ;
               int val = 2*mini - curr ;
               mini = val ;
               
               return prevMin ;
           }
    

       }
       
       /*push element x into the stack*/
       void push(int x){
          // int curr = x ;
           
           if(s.empty()) {
              s.push(x) ;
              mini = x ;
           }
           
           else {
               if(x < mini) {
                   int val = 2*x - mini ;
                   mini = x ;
                   s.push(val) ;
               }
               else{
                   s.push(x) ;
               }
           }
       }
};

