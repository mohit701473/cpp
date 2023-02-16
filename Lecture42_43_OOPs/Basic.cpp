#include<iostream>
using namespace std;

class Hero
{
    private:
    int health ;

    public:
    char level ;

    //how to excess the private data member out side the class
    int getHealth()
    {
        cout<<"in getHealth function ";
        return health ;
    }
    
    char getLevel(){
        cout<<"in getlevel is :"<<endl;
        return level ;
    }

    void sethealth(int h){
        health = h ;
        cout<<"in sethealth is :"<<endl<<endl;
    }

    void setLevel(char ch){
        cout<<"in setHealth function"<<endl;
        level = ch ;
    }
};

int main()
{
    Hero ramesh ;
    ramesh.sethealth(70) ;
    ramesh.level = 'A' ;
    cout<<endl;
    cout<<"Health is : "<<ramesh.getHealth()<<endl;
    cout<<"Level is : "<<ramesh.level<<endl;
    cout<<endl;

}