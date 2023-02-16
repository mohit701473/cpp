#include<iostream>
using namespace std;

// Destructor never takes an argument & never return any value




class Hero 
{
   private:
    int health ;

    public:
    char *name ;
    char level ;

    // this is how to create a static data memeber 
    static int timeToComplete ;
    
    //create a simple constructor
    Hero()
    {
        cout<<"create a simple counstructor"<<endl;
        name = new char[100] ; // Dynamic array allocation in Heap
    }    

    //create a parameterised constructor
    /* Jb hum constructor create kr dete h to inbuilt 
    constructor die ho jata h */
    Hero(int health , char level)
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

    //create a static function
    static int random(){
        // cout<<this -> health ; //it give error
        // cout<<health ; //it also give error

         return timeToComplete ;
    }  

    //create distructour
    ~Hero() {
        cout<<"Destructor is called"<<endl;
    }
};

// Here we initilize the static data member 
//static data members are initilized outside the class 
int Hero::timeToComplete = 5 ;

int main() 
{ 
    //static 
    Hero a ;
    /* jo bhi object static allocation se create krte h 
     unke liye destructor automatically call hota h */

    //Dynamic 
    Hero *b = new Hero ;
    // dynamic cearte object ke liye Destructor ko manualy call krna padta h 
    delete b ;

    Hero c ;

    cout<<Hero::timeToComplete<<endl;
    // i.e without creating a object we can excess the static data member 

    cout<<c.timeToComplete<<endl;
    /* we can not use to execess  static data member in this 
     way bcz our static member is not belong to the object  */

    Hero d ;
    d.timeToComplete = 10 ;
    cout<<c.timeToComplete<<endl;
    cout<<d.timeToComplete<<endl;
    cout<<endl;

    cout<<Hero::random()<<endl;
    return 0 ;
   
}