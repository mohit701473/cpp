#include<iostream>
using namespace std;

/* Que : Can we use single pointer like use only i 
for optimization of our code. Hint use second pointer like
n-i-1 */

bool isPalindrome(string str , int i , int j)
{
    //base case
    if( i>j )
        return true ;

    if( str[i] != str[j] )
        return false ;

    else{
        i++;
        j--;
        return isPalindrome(str,i,j) ;
    }

}

int main()
{
    string str = "abbccbba" ;

    if(isPalindrome(str,0,str.length()-1))
        cout<<"This is a palindrome";
    else
        cout<<"this is not a palindrome";

}