#include<iostream>
using namespace std;
int main()
{
    char ch = 'a';
    char ch1[6] = "abcde" ;
    char *p ;
    char *q ;
    p = &ch ;
   // int *q = &ch1 ;
   /*When q is a char pointer We can't assign char pointer to a string*/ 
   q = &ch1[0] ;

   cout<<"ch = "<<ch<<endl;
   cout<<"ch1 = "<<ch1<<endl;
   cout<<p<<endl;
   cout<<q<<endl;


}