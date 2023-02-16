//Basic operation of Pointers and charachter 
#include<iostream>
using namespace std;
int main()
{
    char ch = 'a';
    char *p = &ch ;
    char *q = NULL;
    cout<<ch<<endl;//Yah 'a' print karega 
    cout<<p<<endl;//Yah tb tk print karega jb tk Null charcter nhi mil jaye 
    cout<<*p<<endl;//Yah keval or keavl 'a' ko hi print karega
    cout<<*p+5<<endl;//Yah integer value dega 
    cout<<char(*p+5)<<endl;//Yah char value dega 
    (*p)++;//Is se ch m increment ho jaye ga
    cout<<*p<<endl;//Yah next value 'b' dega
    q = p ; //pointers are copied mtlb q bhi ch ko point kr rha h
    cout<<*q<<endl;
    *p++;//Is se pointer ek new address(purane m ek increment ho jayega) store kr lega
    ++*p;//It is same as (*p)++
    
    
}
