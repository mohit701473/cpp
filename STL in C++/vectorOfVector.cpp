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
    int row ;
    cout<<"enter the size of the row"<<endl;
    cin>> row ;

    vector<vector<int> > v; 
    // this ia a vector of vector  i.e. we declear a 2D vector which have dynamic row & dynamic column
    // row & column can grow & shrink
    // we can reach each element by v[i][j] where i = row no. & j = column no.

    for(int i=0 ; i<row ; i++){

        int size;
        cout<<"enter the size of the "<<i+1<<" vector"<<endl; 
        cin>>size; // size of the (i+1)th column vector

        vector<int> temp;

        // vector<int> () ; this is a 0 size vector
        // v.push_back(vector<int> () ); i.e. we are inserting a 0 size vector into a vector
        // By doing this after we use v[i].push_back(x) bcz now we have a 0th row vector which have 0 column

        for(int col=0 ; col<size ; col++){
            int x ;
            cout<<"enter the data :";
            cin>> x;
            temp.push_back(x) ;
            
            // v[i].push_back(x) ; we can't use this bcz initially we don't have 0th vector or 
            // we have 0 size of vector of vector or 0 size of 2D vector
        }
        v.push_back(temp) ;
    }

    for(int i=0 ; i<v.size() ; i++){
        printVec(v[i]) ;
    }

}