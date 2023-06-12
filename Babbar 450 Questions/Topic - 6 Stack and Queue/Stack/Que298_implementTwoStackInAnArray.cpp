#include<iostream>
using namespace std ;

class towStack{

    int* arr ;
    int size, len1, len2 ;
    int top1, top2 ;

    public:
    stack(){
        size = 10000 ;
        arr = new int[10000] ;
        len1 = 0 ;
        len2 = 0 ;
        top1 = -1 ;
        top2 = size ;
    }

    void push1(int x){

        if(top1 >= size || top1+1 == top2)
            return ;
        
        top1++ ;
        arr[top1] = x ;
        len1++ ;
    }

    void push2(int x){

        if(top2 < 0 || top2-1 == top1)
            return ;

        top2-- ;
        arr[top2] = x ;
        len2++ ;
    }

    int pop1(){

        if(top1 == -1)
            return -1 ;
            
        int ans = arr[top1] ;
        top1-- ;
        len1-- ;
        return ans ;
    }

    int pop2(){

        if(top2 == size)
            return -1 ;
            
        int ans = arr[top2] ;
        top2++ ;
        len2-- ;
        return ans ;
    }

    int size1(){
        return len1 ;
    }

    int size2(){
        return len2 ;
    }

    bool empty1(){
        if(len1 == 0)
            return true ;

        return false ;
    }

    bool empty2(){
        if(len2 == 0)
            return true ;

        return false ;
    }

};


int main()
{
    towStack st() ;
}