#include<iostream>
#include<queue>
#include<limits.h>
using namespace std ;


// T.C. = O(n)
// S.C. = O(k)
int solveUsingQueue(int arr[], int k, int n){

    queue<int> q ;
    int mini = INT_MAX , maxi = INT_MIN, sum = 0 ;

    // stemp -> 1: insert first k elemnt into q and also find min and max element of in these k elements
    for(int i=0 ; i<k ; i++){
        int element = arr[i] ;
        q.push(element) ;
        mini = min(mini, element) ;
        maxi = max(maxi, element) ;
    }

    sum = mini + maxi ;

    // step -> 2: process on remaining n-k elements
    for(int i=k ; i<n ; i++){
        int element = arr[i] ;
        q.pop() ;
        q.push(element) ;
        mini = min(mini, element) ;
        maxi = max(maxi, element) ;
        sum += mini + maxi ;
    }

    return sum ;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = 7 ;
    int k = 6 ;

    int ans = solveUsingQueue(arr, k, n) ;
    cout<< "ans -> " << ans << endl;
}