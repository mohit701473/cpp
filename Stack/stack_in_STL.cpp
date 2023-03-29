#include<bits/stdc++.h>
using namespace std ;


int main()
{
    stack<string> s;
    s.push("abc");
    s.push("kldsn");
    s.push("qwd");

    while(!s.empty()) {
        cout<<s.top() <<endl;
        s.pop();
    }
}