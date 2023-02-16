#include<iostream>
using namespace std;

void sayDigit(int n , string arr[])
{
    if(n==0)
    return ;

    int digit = n%10;
    n = n/10 ;
    sayDigit(n,arr);    // Head recursion 
    cout<<arr[digit]<<" ";
}

int main()
{
    int n;
    cout<<"enter the no "<<endl;
    cin>>n;
    string arr[11] = {"zero" , "one" , "two" , "three" , "four" ,
                        "five" , "six" , "seven" , "eight" ,
                            "nine" , "ten" };

   sayDigit(n, arr);
}