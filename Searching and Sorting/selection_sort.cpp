#include<iostream>
#include<limits.h>
using namespace std ;

void selectionSort(int* arr, int size) {

    for(int i=0 ; i<size-1 ; i++) {

        int min = 10000 ;
        int index = i ;

        for(int j=i ; j<size ; j++) {
            if(arr[j] < min) {
                index = j ;
                min = arr[j] ;
            }
        }

        arr[index] = arr[i] ;
        arr[i] = min ;
    }
}

int main() {
    int n ;
    cout<<"enter the size of the array"<<endl;
    cin>>n ;

    int arr[10000] ;

    cout<<"enter the array values"<<endl;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i] ;
    }

    selectionSort(arr, n) ;
    cout<<"sorted array"<<endl;
    for(int i=0 ; i<n ; i++){
        cout<<arr[i] <<" ";
    }
}