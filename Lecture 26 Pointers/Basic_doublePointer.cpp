#include<iostream>
using namespace std;
int main()
{
    int x = 5 ;
    int* p = &x ;
    int** ptr = &p ;
    cout<<"value of x = "<<x<<endl;
    cout<<"address of x = "<<&x<<endl;
    cout<<"p stored = "<<p<<endl; //display the address of x
    cout<<"p is pointing to = "<<*p<<endl;//display the value of x
    cout<<"address of p = "<<&p<<endl;
    cout<<"ptr stored = "<<ptr<<endl;//display the address of the p
    cout<<"ptr is pointing to = "<<*ptr<<endl;//display the address of x
    cout<<"address of ptr =  "<<&ptr<<endl; 

    cout<<"\n"<<endl;
    
    cout<<"x = "<<x<<endl;
    cout<<"*p = "<<*p<<endl;
    cout<<"**ptr = "<<**ptr<<endl;

    cout<<"\n"<<endl;
    //only writing p+1 will not affect p
    p = p + 1 ;
    cout<<p<<endl;
    cout<<*ptr<<endl;//both the values are same 
}