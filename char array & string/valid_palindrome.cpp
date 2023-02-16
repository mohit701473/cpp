#include<iostream>
using namespace std;
bool valid(char ch)
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        return 1;
    }
    return 0;
}

char tolowercase(char ch)
{
    if(ch>='a' && ch<='z'  || ch>='0' && ch<='9')
    return ch;
    else
    return ch - 'A' + 'a';
}

int  check_palindrome(string a)
{
    int st=0;
    int e=a.length()-1;
    while(st<e){
        if(a[st] != a[e] ){
            return 0;
        }
        else{
            st++;
            e--;
        }
    }
     return 1;
}

int main()
{
    string s;
    cout<<"enter the string"<<endl;
    cin>>s;
    //faltu character hatado
    string temp="";
    for(int j=0 ; j<s.length() ; j++){
        if(valid(s[j])){
            temp.push_back(s[j]);
        }
    }
    //lowercase kr do
    for(int j=0 ; j<temp.length() ; j++){
        temp[j] = tolowercase(temp[j]);
    }

    if(check_palindrome(temp))
    cout<<"It is a valid palindrome";
    else
    cout<<"Not a valid palindrome";
    

}