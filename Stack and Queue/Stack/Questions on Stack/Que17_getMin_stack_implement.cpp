// Design a stack that supports getMin() in O(1) time and O(1) extra space


// Approch 1
// T.C. = O(1) ;
// S.C = O(n)  bcz we use another array for storing minimum element for every size of the stack
class SpecialStack {

    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
    int *arr1 , *arr2 ;
    int it ;

    SpecialStack(){
        arr1 = new int[100000000] ;
        arr2 = new int[100000000] ;
        it = -1 ;
    }

        
    void push(int data) {

        it++ ;

        if(it == 0 ){
            arr1[it] = data ;
            arr2[it] = data ;
        }

        else{
            arr1[it] = data ;
            if(arr2[it-1] > data){
                arr2[it] = data ;
            }
            else{
                arr2[it] = arr2[it-1] ;
            }
        }

    }

    int pop() {
        if(it == -1)
            return -1 ;

        int val = arr1[it] ;
        it-- ;
        return val ;
        
    }

    int top() {
        if(it == -1)
            return -1 ;

        return arr1[it] ;
    }

    bool isEmpty() {
        if(it == -1)
            return true ;

        return false ;
    }

    int getMin() {
        if(it == -1)
            return -1 ;

        return arr2[it] ;
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

