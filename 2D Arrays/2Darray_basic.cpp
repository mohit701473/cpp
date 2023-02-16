/* Bsic of 2D arrays i.e. decleartion , initilization , taking i/p row wise
& column wise , print matrix , print row sum & column sum , largest row or
column sum ,  
*/
#include<iostream>
using namespace std;

bool ispersent(int arr[][4] , int row , int target) 
/*in c++ we have to give column valuse when we pass 
2D array to a  function otherwies it give error.That is why we 
give here column vaue like 4*/
{
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<4 ; j++){
            if(target == arr[i][j]){
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int row =3 , col =4 ;
//    cout<<"enter row and column"<<endl;
//    cin>>row>>col;
    int arr[3][4];

    cout<<"enter the values"<<endl;
    //taking entries row wise
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>arr[i][j];
        }
    }

    //print
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<arr[i][j];
        }
    cout<<endl;
    }
    
    cout<<"enter the values"<<endl;
    //taking entries column wise
     for(int i=0 ; i<col ; i++){
        for(int j=0 ; j<row ; j++){
            cin>>arr[j][i];
        }
     }

    //print
       for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
     }

     //serach an element
     int target;
     cout<<"enter the element"<<endl;
     cin>>target;
     if(ispersent(arr , row , target))
        cout<<"Element found";
     else
        cout<<"Not found";
}