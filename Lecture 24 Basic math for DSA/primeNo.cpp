//Count Primes (LeetCode que.=204)
#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    int n ;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    vector<bool> prime(n+1,true);
    prime[0] = prime[1] = false ;
    int count = 0 ;
    for(int i=0 ; i<n ; i++){
        if(prime[i]){
            count++ ;

            for(int j=2*i ; j<n ; j=j+i){
                prime[j]=0;
            }
        }
    }
    cout<<"total prime no is "<<count<<endl;
}