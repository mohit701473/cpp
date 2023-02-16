#include<iostream>
using namespace std ;

void swap(int *a, int *b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

// There we are using two pointer like st & end 
void reverseArray1(int arr[], int st, int end){

    if(st >= end) 
        return ;

    swap(arr[st] , arr[end]) ;
    reverseArray1(arr, st+1, end-1) ;
}

// Here we are using only one pointer i & n is size of the arry not an aditional pointer 
void reverseArray2(int arr[] , int i , int n){
    if(i > n/2)
        return ;

    swap(arr[i] , arr[n-i-1]) ;
    reverseArray2(arr, i+1, n-i-1) ;
}

void print(int arr[] , int n) {

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
}

int main()
{
    int n ;
    cin>> n ;
    int arr[10000] ;

    for(int i=0 ; i<n ; i++){
        cin>>arr[i] ;
    }
    print(arr, n) ;
    reverseArray1(arr, 0, n-1) ;
    print(arr, n) ;
    reverseArray2(arr, 0, n) ;
    print(arr, n) ;
}