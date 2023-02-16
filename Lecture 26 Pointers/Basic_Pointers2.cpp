#include<iostream>
using namespace std;
int main()
{
    int firstValue = 5 ;
    int secondValue = 15 ;
    char thirdValue = 'a' ;
    int *p1 , *p2 ;
    char *p3 ;
    p1 = &firstValue ;
    p2 = &secondValue ;
    p3 = &thirdValue ;
    cout<<"firstValue :"<<firstValue<<endl;
    cout<<"pointer p1 is pointing to :"<<*p1<<endl;
    cout<<"secondValue :"<<secondValue<<endl;
    cout<<"pointer p2 is pointing to :"<<*p2<<endl;
    cout<<"thirdValue :"<<thirdValue<<endl;
    cout<<"pointre p3 is pointing to :"<<*p3<<endl;
    cout<<"\n"<<endl;

    *p1 = 10 ;

    cout<<"firstValue :"<<firstValue<<endl;
    cout<<"pointer p1 is pointing to :"<<*p1<<endl;
    *p2 = *p1 ;
    cout<<"secondValue :"<<secondValue<<endl;
    cout<<"pointer p2 is pointing to :"<<*p2<<endl;
     
    cout<<"\n"<<endl;

    cout<<"befor copied p1 stored :"<<p1<<endl;
    p1 = p2 ; //Pointer copied 
    cout<<"after copied  p1 stored :"<<p1<<endl;
    cout<<"pointer p1 is pointing to :"<<*p1<<endl;
    cout<<"pointer p2 is pointing to :"<<*p2<<endl;

    cout<<"\n"<<endl;

    *p1 = 20 ;
    *p3 = 'b' ;
    cout<<"firstValue :"<<firstValue<<endl;
    cout<<"secondtValue :"<<secondValue<<endl;
    cout<<"thirdValue :"<<thirdValue<<endl;
}