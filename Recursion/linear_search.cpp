#include<iostream>
using namespace std;

bool findKey(int arr[] , int size , int key)
{
    if(size == 0)
    return false ;

    if(arr[0] == key)  
    return true ;
    
    else{
        bool remainingPart = findKey(arr+1 , size-1 , key);
        return remainingPart ;
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
    
    if(findKey( arr , size , key))
    cout<<"key found";
    else
    cout<<"key not found";
}