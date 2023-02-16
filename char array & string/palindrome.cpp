//chake palindroem and given string is case sensitive
#include<iostream>
using namespace std;


char tolowercase(char ch)
{
    if(ch>='a' && ch<='z')
    return ch;
    else
    return ch - 'A' + 'a';
}


int  check_palindrome( char ch[] , int n)
{
    int st=0;
    int e=n-1;
    while(st<e){
        if( tolowercase( ch[st] ) != tolowercase( ch[e] ) ){
            return 0;
        }
        else{
            st++;
            e--;
        }
    }
     return 1;
}

int getlength(char ch[])
{
    int count=0 , i=0 ;
    while(ch[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

int main()
{
    char s1[20];
    cout<<"Enter the name"<<endl;
    cin>>s1;
    
    int len;
    len = getlength(s1);

    if(check_palindrome(s1,len))
    cout<<"It is a palindrome";
    else
    cout<<"Not a palindrome";
}