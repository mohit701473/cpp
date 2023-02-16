#include<iostream>
#include<stack>
#include<string>
using namespace std ;

int main() 
{
    string str ;
    cout<<"enter the string"<<endl;
    getline(cin,str) ;

    int size = str.size() ;

    stack<char> st ;

    for(int i = 0 ; i < size ; i++) {
        st.push(str[i]) ;
    }

    cout<<endl<<"reversed string"<<endl;
    for(int i = 0 ; i < size ; i++) {
        cout<<st.top();
        st.pop() ;
    }cout<<endl;

    // T.C. = O(n) 
    // S.C. = O(n) bcz we use a stack 
}