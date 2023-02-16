// Set are container that store unique element in a specefic order  
// The value of the element in a set can not be modified once we insert in it
// Sets are typically implemented as Binary Search Trees

#include<bits/stdc++.h>
using namespace std ;

int main() 
{
    // given n element, find the no. of the unique elements
    // arr[] = {2, 5, 2, 1, 5}  no. of th eunique elemets is = 3 {1, 2, 5}

    set<int> st ; // this is a container of set
    int n ;
    cout<<"entre the value of the n" <<endl;
    cin>> n ;

    for(int i = 0 ; i<n ; i++) {
        int x ;
        cin>>x ;

// (1) set.insert(value)

        st.insert(x) ;  
        // set.insert(vaue) the tim ecomplexcity of this function  T.C. = O(log(N)) where N is the size of the set
        // set.insert(value)  this insert function is like push_back() function in vector
        // Also the values inserted in the sorted means 1st index contain 1st smallest element , 2nd index contain 2nd smallest element
        // And we can't excess set element like this st[0] 
        // By using *set.begin()  we can ecxess the set values

    }

    for(auto it = st.begin() ; it != st.end() ; it++){
        cout<<*it <<" ";
    }cout<<endl;

    // arr[] = {2, 5, 2, 1, 5}
    // st -> {1, 2, 5} 
    // st.erase(st.begin()) or st.erase(itrator)  this function will delete the 1st elemet of the set st
// (2) set.erase(from , were till) 
    st.erase(st.begin()) ;
    // T.C. = O(log(N))

    // st.erase(key)  this will delete the key 

    for(auto it = st.begin() ; it != st.end() ; it++){
        cout<<*it <<" ";
    }cout<<endl;

    // auto it = st.begin()+2
    // st.erase(st.begin() , it) ;
    // // st.rease(startingItrator , endItrator) -> [)

    // for(auto it = st.begin() ; it != st.end() ; it++){
    //     cout<<*it <<" ";
    // }cout<<endl;

    // ways pof the decleartion of the set
    set<int> st1 = {1 , 2 , 3 , 4 , 5} ;
    set<int> st2(st1.begin() , st.end()) ;

    auto it = st1.find(4) ; // T.C. = O(log(N)) it will be the itrator at 7 
    auto it = st.find(9) ;  // it = st.end() ;

    st.emplace(6) ; // st.insert(6)

    cout<<st.size() <<endl;


    unordered_set<int> st3 ;
    // This is also unique and it will store elements in random order and we can't find that which elemnt is 1st or last

    st3.insert(3) ;
    st3.insert(2) ;
    st3.insert(1) ;

    // Average T.C. = O(1) almost in all case in C.P
    // if in C.P TLE is occured then switch to set
    //but worst case T.C. = O(N)  N = set size


    multiset<int> ms ;
    // multiset is gives you an option to store all the element in the sorted fashion

    ms.insert(1) ;
    ms.insert(1) ;
    ms.insert(2) ;
    ms.insert(2) ;
    ms.insert(3) ;  // ms.emplace(3)  same as insert
    // ms -> {1 , 1 , 2 , 2 , 3}

    ms.erase(2)  // all the 2 will be erased

    auto it = ms.find(2)  // return an itartor pointing the first 2 if exist

    ms.clear()  // this will delete entire set
 
    ms.erase(ms.begin() , ms,end) ; // delete entirte element

    // T.C. = O(log(N))  for all the operations
 
    // Their are three 2 type of the deleting the value of the set
    // (1) set.clear()  delete the entire set
    // (2) set.erase(from , to_were) [) this type

}