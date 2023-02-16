#include<iostream>
#include<vector>
using namespace std ;


int main()
{
    vector<int> v = {1, 4, 2, 7, 9};

    //Decleration of iterator for a vector
    vector<int> :: iterator it; // syntax data_type :: iterator name;
    it = v.begin();
    cout<< (*it)<<endl;
    cout<< *(it+2) <<endl;
    cout<< (*(it+3))<<endl;

    cout<< *(v.begin() + 1) <<endl;
    cout<< *(v.end() - 1) <<endl;

    for(it ; it<v.end() ; it++){
        cout<< (*it)<<endl;
    }

    vector<pair<int, int> > v_p = {{1,2}, {3,4}, {7,9}} ;

    // Decleration of iterator for vector<pair<int, int> > type data 
    // Syntax data_typre :: iterator name ;
    vector<pair<int, int> > :: iterator it2 ;
    it2 = v_p.begin() ; 
    cout<< (it2 -> first) <<" "<< (*it2).second<<endl; 
    it2 = it2 + 1;
    cout<< (it2 -> first) <<" "<< (*it2).second<<endl; 

    for(it2 = v_p.begin() ; it2 != v_p.end() ; it2++){
        cout<< ((*it2).first) <<" "<< (*it2).second<<endl; 
        cout<< (it2 -> first) <<" "<< (it2 -> second)<<endl; 
    }

}