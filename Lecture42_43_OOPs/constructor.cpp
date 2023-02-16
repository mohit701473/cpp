#include<iostream>
using namespace std;

// A constructor is a special memeber of the class which is execuited when we creat new objects of the class


class Hero 
{
    private:
    int health ;

    public:
    char *name ;
    char level ;
    
    //create a simple constructor
    Hero()
    {
        cout<<"create a simple counstructor"<<endl;
        name = new char[100] ; // Dynamic array allocation in Heap
    }    

    //create a parameterised constructor
    /* Jb hum constructor create kr dete h to inbuilt 
    constructor die ho jata h */
    Hero( int health , char level)
    {
        
        this -> health = health ;
        this -> level = level ;
    }
    
    //create a copy constructor
    //is copy constructor ki uajh se in built copy constructor hat jayr ga 
    Hero(Hero &temp)
    {
        cout<<"copy constructor is called"<<endl;
        this -> health = temp.health ;
        this -> level = temp.level ;
    }

    void print ()
    {
        cout<<endl;
        cout<<"name : "<<name<<endl;
        cout<<"health : "<<health<<endl;;
        cout<<"level : "<<level<<endl;
    }

    //how to excess the private data member out side the class
    int getHealth()
    {
        return health ;
    }
    
    char getLevel(){
        return level ;
    }

    void setHealth(int h){
        health = h ;
    }

    void setLevel(char ch){
        level = ch ;
    }

    void setName( char name[]){
        this -> name = name ;
    }
};

int main()
{
    
    Hero ramesh( 10,'A') ;
    cout<<"for ramesh"<<endl;
    ramesh.print() ;

    /* Hero ram ; this is showing error bcz inbuilt constructor is
    died and we using only parameterised counstructor */

    Hero mohan(70,'B') ;
    cout<<"for mohan"<<endl;
    mohan.print();
    cout<<endl;

    // Hero suresh ; this is not showing error bcz now at this time we create a simple constructor 

    Hero S(60,'C') ;
    cout<<"for S "<<endl;
    S.print() ;
    cout<<endl;

    Hero R(S) ;   /*here is  copy constructor is called and jb hum class likhte h to 
                   inbuilt ek copy constructor called ho jata h */
    cout<<"for R "<<endl ;  
    R.print() ;

    cout<<endl;
    cout<<"for hero1"<<endl;
    Hero hero1 ;
    hero1.setHealth(12) ;
    hero1.setLevel('D') ;
    char name[10] = "Mohit" ;
    hero1.setName(name) ;
    hero1.print() ;

    Hero hero2(hero1) ;
    hero2.print() ;
    
    hero1.name[0] = 'G' ;
    hero1.setLevel('F') ;
    hero1.print() ;
    hero2.print() ;

}

/* Constructor is a special memeber function of class which is used to create & initialize the object.
Feature :-
(1) A constructor can only have one access modifier which is publc.
(2) A constructor is never inherited & overiden
(3) Each and every c++ class has constructor either it is provided by 
the compiler or explicitly created by the user*/
