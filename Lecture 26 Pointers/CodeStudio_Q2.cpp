#include<iostream>
using namespace std;
int main()
{
    char ch = 'a' ;
    char *ptr = &ch ;
    (*ptr)++ ;
    cout<<"->"<<*ptr<<endl;
    cout<<"ch :"<<ch<<endl;
}