#include<iostream>
using namespace std ;

int main() {

    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;

    int n ;
    // cout<<"enter the size of the array"<<endl;
    cin>>n ;

    int arr[1000] ;

    // cout<<"enter the array values"<<endl;
    for(int i=0 ; i<n ;i++){
        cin>>arr[i] ;
    }

    int key ;
    // cout<<"enter the key"<<endl;
    cin>>key ;

    for(int i=0 ; i<n ; i++){

        if(arr[i] == key) {
            cout<<"key found at "<<i<<" index"<<endl;
            return 0 ;
        }
    }

    cout<<"key not found"<<endl;
    return 0 ;
}