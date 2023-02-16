// map are associative containers(i.e. store data in sorted order) that store elements formed by a combination of a key value pair
// element in associative container are referenced by their key & not by their absolute position in  the container
// Internally, the elemenst ina map always sorted by its key if keys are string or name than keys will store in alphabaticly order
// Unique Keys = No two elements in th econtainer can have equivalent keys 

#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std ;

int main() 
{

    // T.C. = O(log(N)) 
    map<string, int> mpp ;
    mpp["raj"] = 27 ;
    mpp["hima"] = 23 ;
    mpp["sandeep"] = 45 ;
    mpp["ravi"] = 10 ;
    mpp["raj"] = 34 ;  // map store unique keys thenm key raj store 34 i.e it overwrites tghe value

    mpp.emplace("raj" , 45) ; // also same as insertion

    // mpp.erase("raj") ; // this will delete key raj 
    // mpp.erase(mpp.begin()) ;
    mpp.erase(mpp.begin() , mpp.begin() + 2) ;
    // mpp.clear() ;

    // auto it = mpp.find("raj") ;
    // mpp.empty() ;

    // pair<int,int> pr ;
    // pr.first = 1 ;
    // pr.second = 10 ;

    for(auto it: mpp) {
        cout<<it.first <<" "<<it.second<<endl;
    }

}
