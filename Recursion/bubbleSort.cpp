#include<iostream>
using namespace std;

void sortedArray(int arr[] , int size)
{
    //base case- 
    if(size == 0 || size == 1){
        return ;
    }

    for(int i=0 ; i<size-1 ; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
    }

    sortedArray(arr , size-1);
}

int main()
{
    int arr[] = {4,3,7,2,9,0};
    sortedArray(arr,6);
    
    for(int i=0 ; i<6 ; i++){
        cout<<arr[i]<<" ";
    }
}