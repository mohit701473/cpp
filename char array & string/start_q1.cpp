#include<iostream>
using namespace std;
void reverse(char ch[] , int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        swap( ch[i++] , ch[j--]);
    }
}
int getlength(char ch[])
{
    int count=0 , i=0;
    while(ch[i] != '\0'){
        count++;
        i++;
    }
    return count;

}
int main()
{
    char name[20];
    cout<<"Enter your name"<<endl;
    cin>>name; 

    cout<<"your name is"<<endl;
    cout<<name<<endl;
    
    int len;
    len=getlength(name);
    cout<<"length :"<<len<<endl;

    reverse(name ,len);
    cout<<name;
}