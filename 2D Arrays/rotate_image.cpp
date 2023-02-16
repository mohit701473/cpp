//Rotate image (Leet code que = 48 )
/*You are given an n x n 2D matrix representing an image, rotate
the image by 90 degrees (clockwise).You have to rotate the image
in-place, which means you have to modify  the input 2D matrix directly.
the input 2D matrix directly. DO NOT allocate another 2D matrix 
and do the rotation.*/

#include<iostream>
using namespace std;
int main()
{
    int row , col ;
    cout<<"enter row & column"<<endl;
    cin>>row>>col;
    int arr1[row][col];
    int arr2[col][row];
    cout<<"enter the values"<<endl;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>arr1[i][j];
        }
    }
    int total = row * col ;
    int count = 0 ;
    int startingRow = 0 ;
    int stratingCol = 0 ;
    int endingCol = col - 1 ;
    int endingRow = row - 1 ;
    while (count < total){
        for(int index = stratingCol ; index < col ; index++){
            arr2[index][endingRow] = arr1[startingRow][index] ;
            count++;
        }
        startingRow++ ;
        endingRow-- ;
       // cout<<count<<" "<<startingRow<<" "<<endingCol;
    }
    for(int i=0 ; i<col ; i++){
        for(int j=0 ; j<row ; j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
}