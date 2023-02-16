#include<iostream>
using namespace std;
void print(int *q)
{
    cout<<"address = "<<q<<endl;
    cout<<"value = "<<*q<<endl;
    *q = ++*q;//it also change the value of x & *p
}
int main()
{
    int x = 5 ;
    int *p = &x ;
    cout<<"address of x = "<<&x<<endl;
    print(p);
    cout<<"x = "<<x<<endl;
    cout<<"*p = "<<*p<<endl;

}