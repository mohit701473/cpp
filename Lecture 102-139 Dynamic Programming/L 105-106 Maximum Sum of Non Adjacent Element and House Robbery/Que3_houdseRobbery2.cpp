



// Approch -> 1 recursive approch
// T.C. => exponential
// S.C. => Exponentiallong long int solveRecursive(vector<int>& valueInHouse, int N, int i){
    if( i>=N )
        return 0 ;

    int incl = valueInHouse[i] + solveRecursive(valueInHouse, N, i+2) ;
    int excl = solveRecursive(valueInHouse, N, i+1) + 0 ;

    return max(incl, excl) ;
}

long long int houseRobber(vector<int>& valueInHouse)
{   
    int n = valueInHouse.size() ;

    if(n==1)
        return valueInHouse[0] ;


    return max(solveRecursive(valueInHouse, n-1, 0), solveRecursive(valueInHouse, n, 1)) ;
}