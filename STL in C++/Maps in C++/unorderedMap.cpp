#include<bits/stdc++.h>
using namespace std ;

void print(unordered_map<int, string> m){
    for(auto &pr: m){  
        cout<< pr.first <<" "<< pr.second<<endl;
    }
}

int main()
{
    unordered_map<int, string> m ;
    m[1] = "abc" ;  //   T.C = O(1) this is avg T.C. and  this is for insertion of data into unordered map
    m[3] = "wojs" ;
    m[5] = "wqd" ;
    m.insert({4, "dwsd"}) ;

    print(m) ;


//-------------------------------------------------***************************************************-----------------------------------------------

// Functions in map

// (1) m.find(key)  T.C. = O(1)
    auto it1 = m.find(3) ;  // m.find(key) this function will give itrator corrosponding to the key value

    if(it1 == m.end()){  // It means that if key isn't present in the map than this function will give m.end() positioned itrator
        cout<<"No Value"<<endl; 
    }

    else{
        cout<< it1 -> first <<" "<< it1 -> second<<endl;
    }

// (2) m.erase(key)  or   m.erase(itrator)   T.C. = O(1)
    // if key or itrator is not present in the map than this function will give segmentation fault
    cout<<endl;
    m.erase(1) ;
    m.erase(it1) ;
    print(m) ;


// (3) m.clear()   this will erase entire map 
    m.clear() ;
    cout<<endl<<m.size()<<endl;
}