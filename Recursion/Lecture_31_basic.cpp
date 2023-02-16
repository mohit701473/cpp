#include<iostream>
using namespace std;

void print(int n)
{
    if(n==0)
    return ;
     //print(n-1);
    cout<<n<<endl;
    print(n-1);
}

int power( int a , int n )
{
    if(n==0)
    return 1;

   return a * power(a , n-1);
}

int factorial( int n)
{
    if(n==0)
    return 1;

    return n * factorial(n-1);
}


int main()
{
    int n ;
    cout<<"enter n : ";
    cin>>n;
    cout<<factorial(n)<<endl;


    int a ;
    cout<<"enter a : ";
    cin>>a;
    cout<<power(a , n)<<endl;
    cout<<endl;


    print(n);
    
}