#include<iostream>
using namespace std;

bool binarySearch(int arr[] , int s , int e , int k)
{
    //base case 
    if(s>e)
        return false ;
    
    int mid = s +(e-s)/2;

    if(arr[mid] == k)
        return true ;
    
    // search key in right part of the array
    if(arr[mid]<k){
        return binarySearch(arr , mid+1 , e , k);
    }
    
    // search key in left part of the array
    else{
        return binarySearch(arr , s , mid -1 , k);
    }
    
}

int main()
{
    int size ;
    cout<<"enter the size : ";
    cin>>size;

    int arr[size];
    cout<<"enter the array values"<<endl;
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }

    int key ;
    cout<<"enter target : ";
    cin>>key;
    
    if(binarySearch(arr , 0 , size-1 , key))
    cout<<"key found";
    else
    cout<<"key not found";
}