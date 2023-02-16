// Binary search in 2D arrays (LeetCode que = 74)
/* Time complecity in Binary search in 2D arrays is "O(log(row*col))". 
For binary search in 2D arrays 1st conside entire array as single 
inear arary & find start , end & mid and appled binary search like as 
liner array */
#include<iostream>
using namespace std;
int main()
{
    int row , col ;
    cout<<"enter row and column "<<endl;
    cin>>row>>col;
    cout<<"enter the array entries"<<endl;
    int arr[row][col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>arr[i][j];
        }
    }
    int key ;
    cout<<"enter the key"<<endl;
    cin>>key;
    int start = 0 ;
    int end = row * col - 1 ;
    int mid = (start + end) / 2 ;
    while ( start <= end ){
        if( key == arr[mid/col][mid%col] ){
            cout<<"Fount at : "<<mid ;
            return 0 ;
        }
        else if (key > arr[mid/col][mid%col]){
            start = mid + 1;
        }
        else{
            end = mid -1;
        }
        mid = (start + end) / 2 ;
    }
    cout<<"Key not found";
}
