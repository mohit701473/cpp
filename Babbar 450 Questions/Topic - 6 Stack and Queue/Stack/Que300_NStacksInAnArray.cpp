https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?leftPanelTab=0




// Approch 1
class NStack
{
    int *arr, *tops, *links, *freeIndexs ;
    int freeSpot , size;
public:
    // Initialize your constructor
    NStack(int N, int S)
    {
        arr = new int[S] ;
        tops = new int[N] ; // it will store the top of all the stacks
        links = new int[S] ;
        freeIndexs = new int[S] ; // every index of this array will indicate the next freeSpot
        freeSpot = 0 ;
        size = S ;

        for(int i=0 ; i<N ; i++){
            tops[i] = -1 ;
        }

        for(int i=0 ; i<S ; i++){
            links[i] = -1 ;
            freeIndexs[i] = i+1 ;
        }

        freeIndexs[S-1] = -1 ;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freeSpot == -1)
            return false ;

        // step -> 1: find the index to insert value 
        int index = freeSpot ;

        // step -> 2: Update the freeSpot
        freeSpot = freeIndexs[index] ; // freeIndexs[index] it will give next freeSpot

        // step -> 3: insert the value into stack
        arr[index] = x ;

        // step -> 4: update links array
        links[index] = tops[m-1] ;  // tops[m-1] purane vale top ko dal do

        // step -> 5: update tops array
        tops[m-1] = index ;

        return true ;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    // in pop function reverse the flow of the push function
    int pop(int m)
    {
        if(tops[m-1] == -1)
            return -1 ;

        // step -> 1: find the index to pop the value
        int index = tops[m-1] ;

        // step -> 2: update tops array
        tops[m-1] = links[index] ;

        // step -> 3: store the pop value
        int ans = arr[index] ;

        // step -> 4: Update the freeIndexs array
        freeIndexs[index] = freeSpot ;

        // step -> 5: Update the freeSpot
        freeSpot = index ;

        return ans ;

    }
};




// Approch 2 mereg links and freeIndexs array into single array next
class NStack
{
    int *arr, *tops, *next ;
    int freeSpot , size;
public:
    // Initialize your constructor
    NStack(int N, int S)
    {
        arr = new int[S] ;
        tops = new int[N] ; // it will store the top of all the stacks
        next = new int[S] ; // every index of this array will indicate the next freeSpot
        freeSpot = 0 ;
        size = S ;

        for(int i=0 ; i<N ; i++){
            tops[i] = -1 ;
        }

        for(int i=0 ; i<S ; i++){
            next[i] = i+1 ;
        }

        next[S-1] = -1 ;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freeSpot == -1)
            return false ;

        // step -> 1: find the index to insert value 
        int index = freeSpot ;

        // step -> 2: Update the freeSpot
        freeSpot = next[index] ; // freeIndexs[index] it will give next freeSpot

        // step -> 3: insert the value into stack
        arr[index] = x ;

        // step -> 4: update links array
        next[index] = tops[m-1] ;  // tops[m-1] purane vale top ko dal do

        // step -> 5: update tops array
        tops[m-1] = index ;

        return true ;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(tops[m-1] == -1)
            return -1 ;

        // step -> 1: 
        int index = tops[m-1] ;

        // step -> 2: 
        tops[m-1] = next[index] ;

        // step -> 3: 
        int ans = arr[index] ;

        // step -> 4: 
        next[index] = freeSpot ;

        // step -> 5:
        freeSpot = index ;

        return ans ;

    }
};