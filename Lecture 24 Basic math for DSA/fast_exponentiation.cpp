//Find x^n with optimal algorith 
//Compexcity is O(log(n))
#include<iostream>
using namespace std ;
int main()
{
    int  x , n ;
    cin>>x>>n;
    int result = 1 ;
    while( n > 0 ){
        if(n&1){
            result = result * x ;
        }
        x = x * x ;
        n = n>>1 ;//this is less expensive compare to normal divede
    }
    cout<<result;
}