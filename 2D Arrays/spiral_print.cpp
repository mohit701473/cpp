//Spiral Print of a 2D matrix
/*given a m * n matrix , return all the element of the matrix in 
spiral order Leetcode que=54*/
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
    int total = row * col ;
    int count = 0;
    //index initialization 
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while( count < total ){
        //print starting row
        for(int index = startingCol ; index<=endingCol && count<total ; index++){
            cout<<arr[startingRow][index]<<" ";
            count++;
        }
        startingRow++;

        //print ending column
        for(int index = startingRow ; index<= endingRow && count<total ; index++){
            cout<<arr[index][endingCol]<<" ";
            count++;
        }
        endingCol--;

        //print ending row
        for(int index = endingCol ; index>= startingCol && count<total ; index--){
            cout<<arr[endingRow][index]<<" ";
            count++;
        }
        endingRow--;

        //print starting column
        for(int index = endingRow ; index>= startingRow && count<total ; index--){
            cout<<arr[index][startingCol]<<" ";
            count++;
        }
        startingCol++;
    }
}