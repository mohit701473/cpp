#include<iostream>
#include<vector>

using namespace std ;

void printVec(vector<int> v){
    
    int size = v.size() ; // vector.size this function give the size of the vector & T.C. = O(1) of this function

    cout<<"size ->"<<size<<endl;
    for(int i=0 ; i<size ; i++){
        cout<< v[i] <<" ";
    }cout<<endl;
}

void printVecOfString(vector<string> v){
    
    int size = v.size() ; // vector.size this function give the size of the vector & T.C. = O(1) of this function

    cout<<"size ->"<<size<<endl;
    for(int i=0 ; i<size ; i++){
        cout<< v[i] <<" ";
    }cout<<endl;
}


int main()
{
    // Declearatoion of vector
    vector<int> v;
    int n;
    cin>> n;
    for(int i=0 ; i<n ; i++){
        int x ;
        cin>> x;

        v.push_back(x) ; // vector.push_back(value) this function insert value at the end of the vector & T.C. = O(1) of this function

        printVec(v) ;
    }

    printVec(v) ;

    vector<int> q(5) ; 
    // By this we can declear a given size of the vector & initially all the valuse of the vector is set to be 0 & 
    // we can also increase the size of the vector
    printVec(q) ;

    vector<int> r(4, 5); // this denote to vector<int> r(size, all_valuse_set_to_be) ;
    printVec(r) ;

    r.pop_back() ; // vector.pop_back()  this function remove the last element of the vector & decrease the size of the vector & T.C. = O(1) 
    r.pop_back() ;
    r.pop_back() ;

    printVec(r) ;

    // Copy vector
    vector<int> r2 = r ; // T.C. = O(n) of the copy operation
    printVec(r2) ;

    // Vector of type string
    vector<string> str;
    str.push_back("abcd");
    str.push_back("pqr");
    str.push_back("x yz");
    printVecOfString(str);

    vector<int> k ;
    k.push_back(1) ;
    k.push_back(2) ;
    k.push_back(3) ;

    for(auto x: k) {
        cout<<x<<" ";
    }

}