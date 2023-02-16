// Count Ways To Reach The N-th Stairs(CodeStudio Que.=138)
#include<iostream>
using namespace std;

int ways(int n)
{
    //base case 
    if( n < 0 )
    return 0 ;
    if( n == 0 )//i.e 0th stair par h
    return 1 ;//return 1 mtlb 0ht stair pr pahunchane ke kitne ways h

    //recarence relation
    int ans = ways(n-1) + ways(n-2) ; //mtlb nth stair pr kese pahunch sakte h
                        /*(n-1)mtlb ek step lekar last vali stairs se or
                        (n-2) mtlb 2 step lekar 2nd last vali stair se */

    return ans ;
    
                        

}

int main()
{
    int n ;
    cout<<"enter the no of stairs"<<endl;
    cin>>n;
    cout<<"ways : "<<ways(n);


}