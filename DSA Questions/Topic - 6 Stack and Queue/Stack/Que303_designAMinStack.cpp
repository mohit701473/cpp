https://leetcode.com/problems/min-stack/description/



// Approch 1
// T.C. = O(1) ;
// S.C = O(n)  bcz we use another array for storing minimum element for every size of the stack
class MinStack {

    int *arr, *min, topIdx ;
public:
    MinStack() {
        arr = new int[100000] ;
        min = new int[100000] ;
        topIdx = -1 ;
    }
    
    void push(int val) {
        
        if(topIdx == -1){
            topIdx++ ;
            arr[topIdx] = min[topIdx] = val ;
            return ;
        }

        topIdx++ ;
        arr[topIdx] = val ;
        if(val < min[topIdx-1]) min[topIdx] = val ;
        else min[topIdx] = min[topIdx-1] ;
    }
    
    void pop() {
        if(topIdx == -1)
            return ;

        topIdx-- ;
    }
    
    int top() {
        if(topIdx == -1)
            return -1 ;

        return arr[topIdx] ;
    }
    
    int getMin() {
        if(topIdx == -1)
            return -1 ;
            
        return min[topIdx] ;
    }
};






// T.C. = O(1)
// S.C. = O(1)
// Imp formula in push "val = 2*curr - mini"  here curr = x in the push function
// Imp formula in pop "val = 2*mini - curr" here curr = s.top()
// these two formulas used here taki hum current minimum ka use krke previos minimum find kr ske 
class solution{
    
    int minEle;
    stack<int> s;
    
    public:
    
    int mini = INT_MAX ;
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty())
               return -1 ;
           
           return mini ;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty()) 
               return -1 ;
           
            int curr = s.top() ;
            s.pop() ;

            if(curr > mini)  
                return curr ;
            
            else{
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



