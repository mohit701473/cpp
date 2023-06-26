#include<iostream>
#include<limits.h>
using namespace std ;


// T.C = O(N^2) in best, avg & wort case = O(N^2)
// S.C = O(1)
void selectionSort(int arr[], int n){
    if(n==0 || n==1)
        return ;

    for(int i=0 ; i<n ; i++){
        int maxi = INT_MIN ;
        int idx = -1 ;
        for(int j=0 ; j<n-i ; j++){
            if(maxi < arr[j]){
                maxi = arr[j] ;
                idx = j ;
            }
        }

        swap(arr[idx], arr[n-i-1]) ;
    }
}


int main()
{
    int arr[] = {10, 6, 9, 2, 7, 3, 5, 1, 8} ;
    selectionSort(arr, 9) ;

    for(int i=0 ; i<9 ; i++)
        cout << arr[i] << " " ;

    cout << endl ;
}