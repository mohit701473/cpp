// Search a 2D Matrix II (LeetCode que=240)
/* Write an efficient algorithm that searches for a value target in an  
m x n integer matrix matrix.This matrix has the following properties:
(a) Integers in each row are sorted in ascending from left to right.
(b) Integers in each column are sorted in ascending from top to bottom */

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
    int target ;
    cout<<"enter the target"<<endl;
    cin>>target;
    int rowIndex = 0 ;
    int colIndex = col - 1 ;
    
    while( rowIndex < row && colIndex >= 0 ){
        int element = arr[rowIndex][colIndex];
        if( target == element ){
            cout<<"element found at ("<<rowIndex<<","<<colIndex<<")"<<endl;
            return 0 ;
        }
        else if ( target < element){
            colIndex--;
        }
        else{
            rowIndex++;
        }
    }
}