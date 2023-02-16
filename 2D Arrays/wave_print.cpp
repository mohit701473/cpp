//Print like a wave
/*for a given 2D array/list 'ARR' size(N*M), print theb 'ARR'
in a sine wave order,i.e.,print the 1st column top to bottom, 
net column bottom to top , and so on*/
#include<iostream>
using namespace std;
int main()
{
    int row , col ;
    cout<<"enter row and column"<<endl;
    cin>>row>>col;
    cout<<"enter the array entries";
    int arr[row][col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>arr[i][j];
        }
    }
    cout<<"result is "<<endl;
     for(int i=0 ; i<col ; i++){
        if(i&1){
            //top to bottom column print 
            for(int j=row-1 ; j>=0 ; j--){
                cout<<arr[j][i]<<" ";
            }
        } 
        else{
            //bottom to top column print 
            for(int j=0 ; j<row ; j++){
                cout<<arr[j][i]<<" ";
            }
        }     
    }
}