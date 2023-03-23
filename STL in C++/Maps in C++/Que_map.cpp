/* Given N strings, print unique strings in lexiiographical order with their frequency
N <= 10^5
|S| <= 100
*/


#include<bits/stdc++.h>
using namespace std ;


void print_map(map<string, int> m){
    for(auto &pr: m){  
        cout<< pr.first <<" "<< pr.second<<endl;
    }
}


int main() 
{
    map<string, int> m ;
    int n ;  // no of strings
    cout<<"enter the no. of strings: ";
    cin>> n ;

    cout<<"enter strings"<<endl;
    for(int i=0 ; i<n ; i++){
        string s ;
        cin>> s ;
        m[s] = m[s] + 1 ; // this will store frequency of the string  also write   m[s]++
    }
    print_map(m) ;
}