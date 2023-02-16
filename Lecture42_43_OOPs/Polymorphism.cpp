#include<iostream>
using namespace std ;

class A {

//Function Overloading    
    public:
    void sayHello() {
        cout<<"Hello Mohit"<<endl;
    }

    int sayHello(char name) {
        cout<<"Hello Mohit"<<endl;
        return 1 ;
    }

    void sayHello(string name) {
        cout<<"Hello "<<name<<endl;
    }


//Operator Overloading
    int a ;
    int b ;

    int add() {
        return a + b  ;
    }
    void operator+ (A &obj) {
        int value1 = this -> a ;
        int value2 = obj.a ;
        cout<<"output"<<value2 - value1 <<endl;
    }

    void operator() (){
        cout<<"I am a bracket "<<this->a <<endl;
    }
};

int main()
{
    A obj1 , obj2 ;
    obj1.a = 7 ;
    obj2.a = 4 ;

    obj1 + obj2 ; 

    obj1() ;

}