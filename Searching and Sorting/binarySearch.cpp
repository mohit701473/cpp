#include<iostream>
using namespace std ;

int binarySearch(int arr[], int size, int key) {

    int s = 0 ;
    int e = size-1 ;

    while(s<e) {
        int mid = s + (e-s)/2 ;

        if(key == arr[mid]) {
            return mid ;
        }

        else if(key > arr[mid]) {
            s = mid + 1 ;
        }

        else {
            e = mid - 1 ;
        }
    }

    return -1 ;
}

int main() {
    int n ;
    cout<<"enter the size of the array"<<endl;
    cin>>n ;

    int arr[10000] ;

    cout<<"enter the sorted array values"<<endl;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i] ;
    }

    int key ;
    cout<<"enter the key"<<endl;
    cin>>key ;

    int ans = binarySearch(arr, n, key) ;
    cout<<ans<<endl;
    return 0 ;
}