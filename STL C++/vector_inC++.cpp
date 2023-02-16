#include<iostream>
#include<vector>
using namespace std ;

int main() 
{
    // vector<int> vec ;
    // cout<<"size -> "<<vec.size()<<endl;
    // cout<<"capacity -> "<<vec.capacity()<<endl;

    // vec.push_back(2) ;
    // cout<<"size -> "<<vec.size()<<endl;
    // cout<<"capacity -> "<<vec.capacity()<<endl;

    // vec.push_back(3) ;
    // cout<<"size -> "<<vec.size()<<endl;
    // cout<<"capacity -> "<<vec.capacity()<<endl;
    // cout<<"is empty -> "<<vec.empty()<<endl;

    // vec.push_back(4) ;
    // cout<<"size -> "<<vec.size()<<endl;
    // cout<<"capacity -> "<<vec.capacity()<<endl;

    // vec.pop_back() ;
    // cout<<"size -> "<<vec.size()<<endl;
    // cout<<"capacity -> "<<vec.capacity()<<endl;

    // vec.pop_back() ;
    // cout<<"size -> "<<vec.size()<<endl;
    // cout<<"capacity -> "<<vec.capacity()<<endl;

    // vec.clear() ;
    // cout<<"size -> "<<vec.size()<<endl;
    // cout<<"capacity -> "<<vec.capacity()<<endl;

    // cout<<"is empty -> "<<vec.empty()<<endl;
    // cout<<"size -> "<<vec.size()<<endl;
    // cout<<"capacity -> "<<vec.capacity()<<endl;


    // cout<<"front -> "<<vec.front()<<endl;
    

    // Copy a vector in another vector
    vector<int> vec1(4,10) ;
    vector<int> vec2(vec1) ;

    for(int i : vec2) {
        cout<<i <<" ";
    }cout<<endl;

   // Copy only some part of the vector [) this type of copying 
   vector<int> vec3(vec1.begin() , vec1.begin() + 2) ;
    for(int i : vec3) {
        cout<<i <<" ";
    }cout<<endl;


    // 2D vector

    vector<vector<int>> vec ;
    vector<int> raj1 ;
    raj1.push_back(1) ;
    raj1.push_back(2) ;

    vector<int> raj2 ;
    raj2.push_back(10) ;
    raj2.push_back(22) ;

    vector<int> raj3 ;
    raj3.push_back(10) ;
    raj3.push_back(22) ;
    raj3.push_back(24) ;

    vec.push_back(raj1) ;
    vec.push_back(raj2) ;
    vec.push_back(raj3) ;

    for(auto it : vec) {
        for(auto it1 : it) {
            cout<<it1<<" " ;
        }cout<<endl;
    }

    cout<<vec[2][2]<<endl;

    for(int i = 0 ; i < 2 ; i++) {
        cout<<raj3[i] <<" " ;
    }cout<<endl;
    
    for(int i = 0 ; i<vec.size() ; i++) {
        for(int j = 0 ; j<vec[i].size() ; j++) {
            cout<<vec[i][j]<<" ";
        }cout<<endl;
    }

    // define 10 x 20 size 2D vextor
    vector<vector<int>> vec4(10,vector<int> (20,1)) ;

    vector<int> arr[4] ; // it means we create a arry size 4 & data type is vector<int> means it store vector<int> 

    // 3D vector 10 x 20 x 30 size vector
    vector<vector<vector<int>>> vec5(10 , vector<vector<int> > (20,vector<int> (30,1))) ;

}