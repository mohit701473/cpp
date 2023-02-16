#include<iostream>
#include<array>
using namespace std ;

int main() {

    array<int , 5> arr ;

    for(int i = 0 ; i < 5 ; i++) {
        arr.at(i) = i ;
    }

    for(int i = 0 ; i < 5 ; i++) {
        cout<<arr.at(i)<<" " ;
    }cout<<endl;

    for(auto it = arr.begin() ; it != arr.end() ; it++) {
        cout<<it<<" ";
    }cout<<endl;

    for(auto it = arr.begin() ; it != arr.end() ; it++) {
        cout<<*it<<" ";
        cout<<sizeof(it)<<endl;
    }cout<<endl;

    for(auto it = arr.rbegin() ; it != arr.rend() ; it++) {
        cout<<*it<<" ";
    }cout<<endl;

    cout<<arr.size()<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;

    for(int it: arr) {
        cout<<it<<" ";
    }cout<<endl;

    for(auto it: arr) {
        cout<<it<<" ";
    }cout<<endl;

    for(auto it: arr) {
        cout<<&it<<" ";
    }cout<<endl;

    for(auto &it: arr) {
        cout<<it<<" ";
    }cout<<endl;

    for(auto &it: arr) {
        cout<<&it<<" ";
    }cout<<endl;
}