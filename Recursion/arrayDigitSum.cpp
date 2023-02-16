#include<iostream>
using namespace std;

int digitSum(int arr[] , int size)
{
    if(size == 0)
    return 0 ;

    return digitSum(arr+1,size-1) + arr[0];
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

    cout<<digitSum(arr,size);
}