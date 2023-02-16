#include<iostream>
#include<vector>
using namespace std ;


int main()
{
    vector<int> v = {1, 4, 2, 7, 9};

    // For each loop
    // auto menas automatically decide the data type of veraible value
    // here copy of 
    for(auto value : v) {
        // cout<<sizeof(value)<<endl; by this we can check the data type of veriable
        cout<<value<<" " ;
    }
}