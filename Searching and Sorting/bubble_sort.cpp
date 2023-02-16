#include<iostream>
#include<limits.h>
using namespace std ;

void bubbleSort(int* arr, int size) {

    int count = 1 ;

    while(count < size) {
        for(int i=0 ; i<size-count ; i++) {
            if(arr[i] > arr[i+1]) {
                int temp = arr[i] ;
                arr[i] = arr[i+1] ;
                arr[i+1] = temp ;
            }
        }
        count++;
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

    bubbleSort(arr, n) ;
    cout<<"sorted array"<<endl;
    for(int i=0 ; i<n ; i++){
        cout<<arr[i] <<" ";
    }
}