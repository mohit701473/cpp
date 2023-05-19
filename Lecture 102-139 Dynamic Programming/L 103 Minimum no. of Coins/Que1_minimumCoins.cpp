

//Minimum Elements  code studio




// Approch - 1 using recursion
// T.C. = O(3^N) 
// S.C. = O(3^N)
int solveRec(vector<int> &num, int x){

    if(x == 0)
        return 0 ;

    if(x < 0)
        return INT_MAX ;

    int mini = INT_MAX ;

    for(int i=0 ; i<num.size() ; i++){
        int ans = solveRec(num, x-num[i]) ;

        if(ans != INT_MAX)
            mini = min(mini, 1+ans) ;
    }

    return mini ;
}

int minimumElements(vector<int> &num, int x)
{
    int ans = solveRec(num, x) ;

    if(ans == INT_MAX) return -1 ;

    return ans ;
}