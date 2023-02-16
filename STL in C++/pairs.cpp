#include<iostream>
using namespace std ;

int main()
{
    // Declearation of pair container
    pair<int, int> p;
    p.first = 3;
    p.second = 5;
    cout<< p.first << " " << p.second << endl;

    // Taking user i/p in pair
    pair<int, int> q;
    cin>> q.first >> q.second;
    cout<< q.first << " " << q.second << endl;

    // Copy a pair into another
    p = q ;
    cout<< p.first << " " << p.second << endl;

    // Declear a array of pair
    pair<int, float> pair_array[3] ;
    for(int i=0 ; i<3 ; i++) {
        cin >> pair_array[i].first >> pair_array[i].second ;
    }

    for(int i=0 ; i<3 ; i++) {
        cout<< pair_array[i].first <<" "<< pair_array[i].second<< endl;
    }
}