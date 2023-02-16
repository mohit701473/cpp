#include<iostream>
using namespace std ;

struct Node {
    int data;
    float fol;
    char x;

    Node(int d , float f , char y) {
        data = d ;
        fol = f ;
        x = y ;
    }
};

int main() {
    // Node raj;
    // raj.data = 12 ;
    // raj.fol = 3.5 ;
    // raj.x = 'w' ;

    // cout<<raj.data<<endl;
    // cout<<raj.fol<<endl;
    // cout<<raj.x<<endl;

    Node *Mohit = new Node(12 , 3.2 , 's') ;
    cout<<Mohit->data<<endl;
    cout<<Mohit->fol<<endl;
    cout<<Mohit->x<<endl;
}