#include<iostream>
using namespace std;

bool isSorted(int arr[] , int size)
{
    if(size == 0 || size == 1)
    return true ;
      
    if(arr[0] > arr[1])
    return false;
    else{
        bool remainingPart = isSorted(arr+1 , size-1);
        return remainingPart;
    }
}

int main()
{
    int n ;
    cout<<"enter the n : ";
    cin>>n;

    int arr[n];
    cout<<"enter the array values"<<endl;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    if(isSorted(arr,n))
    cout<<"Sorted array";
    else
    cout<<"Unsorted array";
}