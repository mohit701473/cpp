// Implement two stacks in an array

#include<iostream>
using namespace std ;

class twoStack {
    int* arr ;
    int size ;
    int top1 ;
    int top2 ;

    public:

    // create a constructor 
    twoStack(int n) {
        this -> size = n ;
        arr = new int[n] ;
        top1 = - 1 ;
        top2 = n ;
    }

    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top2 - top1 > 1) {
            top1++ ;
            arr[top1] = x ;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if(top2 - top1 > 1) {
            top2-- ;
            arr[top2] = x ;
        }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1 >= 0) {
            int ans = arr[top1] ;
            top1-- ;
            return ans ;
        }
        
        return -1 ;
    }

    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2 < size) {
            int ans = arr[top2] ;
            top2++ ;
            return ans ;
        }
        
        return -1 ;
    }
};

int main() 
{
    int n ;
    cout<<"enter the size"<<endl;
    cin>> n ;

    twoStack st(n) ;

    st.push1(2);
    st.push1(3);
    st.push2(4);
    cout<<st.pop1()<<endl;
    cout<<st.pop2()<<endl;
    cout<<st.pop2()<<endl;
}