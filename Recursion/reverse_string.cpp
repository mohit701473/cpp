//reverse the string
/* Que : Can we use single pointer like use only i 
for optimization of our code. Hint use second pointer like
n-i-1 */
#include<iostream>
using namespace std;

/* bina referance variable ke string pass by value se function m jaye gi
or string ki copy str banegi jo name vali string ko change nhi karegi so
we use referance variable string &str here */
void reverseString( string &str , int i , int j )
{
    cout<<"call recive for : "<<str<<endl;
    //Base case 
    if( i > j )
        return ;

    swap( str[i] , str[j] ) ;
    i++;
    j--;

    //Recursive call 
    reverseString(str,i,j) ;
}

int main()
{
    string name = "abcde";
    cout<<"initial string is : "<<name<<endl;
    reverseString(name,0,name.length()-1);
    cout<<"reversed string is : "<<name<<endl;
}