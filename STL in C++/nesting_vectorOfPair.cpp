#include<iostream>
#include<vector>

using namespace std ;

void printVec(vector<pair<int, int> > &v){
    
    int size = v.size() ; // vector.size this function give the size of the vector & T.C. = O(1) of this function

    cout<<"size ->"<<size<<endl;
    for(int i=0 ; i<size ; i++){
        cout<< v[i].first <<" "<< v[i].second<<endl;
    }cout<<endl;
}


int main() 
{
    vector<pair<int, int> > v = {{1,2}, {3,4}, {7,0}};
    printVec(v) ;

    vector<pair<int, int> > v1 ;
    int n ;
    cin>>n ;
    for(int i=0 ; i<n ; i++){
        int x, y;
        cin>>x >>y;
        v1.push_back({x, y});
    }

    printVec(v1) ;
    
}