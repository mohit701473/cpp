https://leetcode.com/problems/min-stack/description/



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