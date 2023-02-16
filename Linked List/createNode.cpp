#include<iostream>
using namespace std ;

class Node {

    public :
    int data ;
    Node *next ;

    //constructor
    Node (int data ){
        this -> data  = data ;
        this -> next = NULL ;
        
        cout<<endl;
        cout<<"inside the constructor"<<endl;
        cout<<"this : "<<this<<endl;
        cout<<this -> data<<endl;
        cout<<this -> next<<endl;
        cout<<endl;
    }
};

int main()
{
    Node *node1 = new Node(10) ;
    cout<<"*node1 : "<<node1<<endl;
    cout<< node1 -> data <<endl;
    cout<< node1 -> next <<endl;
    cout<<endl;
}