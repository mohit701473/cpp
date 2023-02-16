#include<iostream>
#include<vector>

using namespace std ;

void printVec(vector<int> &v){
    
    int size = v.size() ; // vector.size this function give the size of the vector & T.C. = O(1) of this function

    cout<<"size ->"<<size<<endl;
    for(int i=0 ; i<size ; i++){
        cout<< v[i] << " ";
    }cout<<endl;
}


int main() 
{
    int n ;
    cout<<"enter the size of the array"<<endl;
    cin>> n ;

    vector<int> v[n] ; // Arrays of vector i.e. we declear a array of size n which having data vector
    // or we say that we declear a array of vector<int> type
    // or it like to a 2D array which have variable size of the column bcz columns are vectors
    // we can reach each element by v[i][j] where i = row no. & j = column no.

    for(int i=0 ; i<n ; i++){

        int size;
        cout<<"enter the size of the "<<i+1<<" vector"<<endl;
        cin>>size;

        for(int j=0 ; j<size ; j++){
            int x ;
            cout<<"enter the data :";
            cin>> x;
            v[i].push_back(x) ;
        }
    }

    for(int i=0 ; i<n ; i++){
        printVec(v[i]) ;
    }

}