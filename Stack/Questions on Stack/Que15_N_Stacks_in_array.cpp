// N Stacks In An Array


// Approch 1
// In this approch memory utilization is not proper
#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    int *arr ;
    int *index ;
    int size ;
    int *count ;
    NStack(int N, int S)
    {
        // Write your code here.
        arr = new int[S] ;
        index = new int[N] ;
        count = new int[N] ;
        size = S/N ;

        for(int j=0 ; j<N ; j++)
            count[j] = 0 ;

        for(int k=0 ; k<N ; k++){
            index[k] = size*k ;
        }
    }

    

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        bool ans = false ;
        if(count[m-1] < size){
            arr[index[m-1]] = x ;
            index[m-1] = index[m-1] + 1 ;
            count[m-1] = count[m-1] + 1 ;
            //cout<<"stack no: "<<m<<endl;
            ans = true ;
        }
        return ans ;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(count[m-1] == 0)
            return -1 ;
        else{
            int val = arr[index[m-1]] ;
            index[m-1] = index[m-1] - 1 ;
            count[m-1] = count[m-1] - 1 ;
            return val ;
        }
    }
};



// Approch 2
// memory utilization is optimal
#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    int *arr, *top, *next ;
    int freeSpot ;

    NStack(int N, int S)
    {
        // Write your code here.
        arr = new int[S] ;
        top = new int[N] ;   // top[] represent index of the top element of the stack
        next = new int[S] ; //  next[]  represent two things 1st point to next element after stack top if arr[index] is filled
                            // 2nd thing is point to next free space when arr[index] is not filled
        freeSpot = 0 ;

        // Initially top array contains -1 bcz all stacks are empty at starting
        for(int i=0 ; i<N ; i++)
            top[i] = -1 ;

        // At starting arr[i] is not filled so next contain next free spce 
        for(int i=0 ; i<S ; i++){
            next[i] = i + 1 ; 
            if(i == S-1)
                next[i] = -1 ;
        } 
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Check for stack overflow
        if(freeSpot == -1)
            return false ;

        // 1st step -> find the free space 
        int index = freeSpot ;

        // 2nd step -> update freeSpot
        freeSpot = next[index] ;

        // 3rd step -> insert x into arrary 
        arr[index] = x ;

        // 4th step -> update next bcz arr[index] is filled
        next[index] = top[m-1] ; // at this next[] point to the next element after stack top

        // 5th step -> update top
        top[m-1] = index ;

        return true ;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Stack underflow
        if(top[m-1] == -1)
            return -1 ;

        int index = top[m-1] ;

        top[m-1] = next[index] ;

        next[index] = freeSpot ;

        freeSpot = index ;

        return arr[index] ;
    }
};