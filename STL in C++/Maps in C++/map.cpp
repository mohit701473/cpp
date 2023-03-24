#include<bits/stdc++.h>
using namespace std ;

void print_map(map<int, string> m){
    for(auto &pr: m){  // &pr is used bcz we don't want that copy of the pair will created
        cout<< pr.first <<" "<< pr.second<<endl;
    }
}


int main()
{
    map<int, string> m ;  // Declearation of a map 

    // Inserting data into map 
    // map_name[key] = value
    m[1] = "abc" ;   // T.C = O(log(n))  &  n is the current size of the map
    m[5] = "cdc" ;
    m[3] = "acd" ;

    // Another way of inserting data into map
    m.insert({4, "afg"}) ;



    // Printing map data
    map<int, string> :: iterator it ;  // Decleraing an iterator

    for(it = m.begin(); it != m.end(); it++){
        cout<<(*it).first<<" "<<(*it).second << endl;
        // Also we can write
        // cout<< it -> first <<" "<< it -> second <<endl<<endl;   
    }

    cout<<endl;

    // Another way of printing map data
    for(auto &pr: m){  // &pr is used bcz we don't want that copy of the pair will created
        cout<< pr.first <<" "<< pr.second<<endl;
    } // This for loop take O(nlog(n)) time to run 

    cout<<m.size()<<endl; // This function will give current size of the map



    map<string, string> mp ;
    m["abcd"] = "abcd"  //  insertion T.C. = O(string.size() * log(n))


// -----------------------------------------------***************************************************-------------------------------------------------

// Functions in map

// (1) m.find(key)  T.C. = O(log(n))
    auto it1 = m.find(3) ;  // m.find(key) this function will give itrator corrosponding to the key value

    if(it1 == m.end()){  // It means that if key isn't present in the map than this function will give m.end() positioned itrator
        cout<<"No Value"<<endl; 
    }

    else{
        cout<< it1 -> first <<" "<< it1 -> second<<endl;
    }

    

// (2) m.erase(key)  or   m.erase(itrator)   T.C. = O(log(n))
    // if key or itrator is not present in the map than this function will give segmentation fault
    cout<<endl;
    m.erase(1) ;
    m.erase(it1) ;
    print_map(m) ;

// (3) m.clear()   this will erase entire map 
    m.clear() ;
    cout<<endl<<m.size()<<endl;
}