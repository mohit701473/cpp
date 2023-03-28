#include<bits/stdc++.h>
using namespace std ;

int main()
{
    // Any data structure which is compareble is used as key in map for nesting vector is also comparable
    // At value position any data structue is inserted in map

    map<pair<int, int> , int> m ;  // In map inserting a value 1st comparsion is done so here pair is compared

    pair<int, int> p1, p2 ;
    p1 = {1,2} ;
    p2 = {1,1} ;
    cout<< (p1 > p2)<<endl;  // Comparing pari p1 & p2
    // In comparing of two pair 1st first value(in p1 1 & in p2 1) is compared and if it is same than second value(in p1 2 & in p2 1) is compared and if p1 > p2 is true than o/p is 1 else 0


    map<set<int>, int> m1 ; // Here set is compared

    set<int> s1 = {1,2,3} ;
    set<int> s2 = {2,3} ;
    cout<< (s1 < s2) <<endl ; // Set is compared value by value
}