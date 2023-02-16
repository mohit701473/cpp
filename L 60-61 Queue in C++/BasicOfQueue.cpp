#include<iostream>
#include<queue>
using namespace std ;

int main()
{
    int n ;
    cout<<"enter the n"<<endl;
    cin>>n ;
    queue<int> q ;
    for(int i=0 ; i<n ; i++){
        int data ;
        cout<<"enter data"<<endl;
        cin>>data ;
        q.push(data) ;
    }

    q.pop() ;
    q.pop() ;
    cout<<"size : "<<q.size()<<endl;
    cout<<"isEmpty : "<<q.empty()<<endl;
    cout<<"front : "<<q.front()<<endl;
    cout<<"rare : "<<q.back()<<endl;
    
}