#include<iostream>
using namespace std;
#pragma pack(1)
class Hero 
{
   public:
   char c ;
   short s ;
   char ch ;
   int i ;

};

int main()
{
    Hero ramesh ;
    cout<<"size is : "<<sizeof(ramesh);

}