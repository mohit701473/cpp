#include<bits/stdc++.h>
using namespace std ;

void print(set<string> &s){

    for(auto it: s){  // T.C. = O(nlog(n))
        cout<<it<<endl;
    }cout<<endl;

    for(auto it = s.begin(); it != s.end(); it++){
        cout<<(*it)<<endl;
    }cout<<endl;
}

int main()
{
    set<string> s ; // Decleration of set and this is a ordered set and store values in sorted order

    s.insert("abc") ;  // T.C. = O(log(n))  for inserting an element in ordered set
    s.insert("zxc") ;
    s.insert("bcv") ;
    s.insert("abc") ;

    auto it = s.find("abc") ; // T.C. = O(log(n))  for finding an element in ordered ste

    if(it != s.end()) {  // Bcz in s.find(value) if value is not preseen then this function will return end itrator of the set and without if condition this will give segmentation fault
        cout<<(*it)<<endl;
        s.erase(it) ; // T.C. = O(log(n)) 
        // s.erase("abc")  also write as this 
    }cout<<endl;


    print(s) ;
}