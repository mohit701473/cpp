#include<iostream>
#include<map>
#include<unordered_map>

using namespace std ;


int main(){

// ordered map wiil store data in the sorted order & sorting of data will done according to the key value
// T.C. = O(log(n))   in ordered map in insertion, search, erase, find operation


    // declearation of ordered map
    map<string, int> m ;    // map<key, value> name ;


// --------------------------------------------  Different Operations & Functions in map  --------------------------------------------------------- 


// (1) Insertion in map
    // way -1
    pair<string, int> p1 = make_pair("Mohit", 3) ;
    m.insert(p1) ;

    // way -2 
    pair<string, int> p2("Kumar", 2) ;
    m.insert(p2) ;

    // way -3
    m.insert({"Name", 4}) ;

    // way -4
    m["Parjapat"] = 4 ;

    m["Kumar"] = 7 ;  // No duplicate entries are allowed so updation of value will be done to the corrosponding key



// (2) Search key in map
    // way -1
    cout<<m["Mohit"] << endl ; 

    // way -2
    cout<<m.at("Mohit") << endl ;

    // When we search a key that is not present in map
    cout<<m["unkonownkey"] << endl ;
    cout<<m.at("unkonownkey") << endl ;

    
// (3) Size of map
    cout<< m.size() << endl ;


// (4) To check presence of key
    cout<< m.count("bro") << endl ;  


// (5) Erase any key form map
    m.erase("Mohit") ;  // T.C. = O(log(n))
    cout<< m.size() << endl ; 


// (6) m.find(key)  
    auto it1 = m.find("Name") ;  // m.find(key) this function will give itrator corrosponding to the key value

    if(it1 == m.end()){  // It means that if key isn't present in the map than this function will give m.end() positioned itrator
        cout<<"No Value"<<endl; 
    }

    else{
        cout<< it1 -> first <<" "<< it1 -> second<<endl;
    }

// (7) m.clear()   this will erase entire map 
    // m.clear() ;
    // cout<<endl<<m.size()<<endl;

// (8) Traversing a map
    // way -1 using simple for each loop
    for(auto i: m)  // in map data store in the key value form thus here i will be a pair 
        cout<<i.first<<" "<<i.second<<endl ; // i is a pair so we use i.first & i.second

    cout<<endl;

    // way -2  using iterator 
    // map<string, int> :: iterator it; -> decleration of iterator
    // it = m.begin() ; -> initilization of iterator
    map<string, int> :: iterator it = m.begin() ;

    while(it != m.end()){  // T.C. = O(nlog(n))
        cout<< it->first <<" " << it->second <<endl ;
        it++ ;
    }



}



