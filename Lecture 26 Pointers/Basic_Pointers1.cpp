//Basic operation on  a Pointers
// int *ptr1 = 5 ; pointer can't pointing to a constant value
#include<iostream>
using namespace std;
int main ()
{
    int x = 5 ;       // Decleartion + Initilization of a variable
    cout<<x<<endl;
    cout<<&x<<endl;  // It return the address of the varible x
 
    int *ptr ;            // Decleartion of a Pointer 
    cout<<ptr<<endl;     // It return the address of the Pointer
    cout<<*ptr<<endl;   // This will display the data where ptr is pointing
    cout<<&ptr<<endl;  // It return the address where pointer is stored
    cout<<"\n";

    ptr = &x ;            // Initilization of a pointer 
    cout<<ptr<<endl;     // It return the address of the x
    cout<<ptr+1<<endl;  // It return the address of next locatin after x
    ptr+1;//this will not affect bcz we only increasing by 4 byte but not store 
    cout<<*ptr<<endl;  // Dereferencing of a Pointer 
    cout<<&ptr<<endl; // It return the address where pointer is stored
    cout<<(*ptr)+1<<endl;
    cout<<*ptr+1<<endl;
    *ptr++;
    cout<<x<<endl;
    cout<<"\n";

    ptr++;              // It also give the address of next locatin after x
    cout<<ptr<<endl;   // It return the address of next locatin after x
    cout<<*ptr<<endl; // It give the value which is stored in the next location
}