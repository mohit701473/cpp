#include<iostream>
using namespace std ;

class Hero
{
    public:
    int health ;
    char name[100] ;
    int level ;

};

int main()
{
    Hero h1 ;
    cout<<"size of :"<<sizeof(h1)<<endl;
}