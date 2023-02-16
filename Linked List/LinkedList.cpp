#include<iostream>
using namespace std ;

class Node
{
    public:
    int data ;
    int value ;
    Node* next ;

    Node(int d){
        this -> data = d ;
        //this -> value = v ;
        this -> next = NULL ;
        cout<<"constructor is called"<<endl;
    }
};


void print(Node* &head)
{
    int i = 6 ;
    Node *temp = head ;
    do{
        cout<<"data for node"<<i<<" is  :"<<temp->data<<endl;
        temp = temp->next ;
        i++ ;
    }while(temp!= NULL) ;

    head -> data = 100 ;
    cout<<"inside the print function head -> data :"<<head->data<<endl;
    cout<<"inside the print function head :"<<head<<endl;
    cout<<"inside the print function head :"<<&head<<endl;
}


int main()
{
    Node node1(10) ;
    cout<<"node1 data :"<<node1.data<<endl ;
    cout<<"node1 next :"<<node1.next<<endl ;
    //cout<<"node1 value :"<<node1.value<<endl;

    Node node2(20) ;
    cout<<"node2 data :"<<node2.data<<endl ;
    cout<<"node2 next :"<<node2.next<<endl ;

    // Node node1 , node2 , node3 ;
    // node1.data = 20 ;
    // node2.data = 30 ;
    // node3.data = 40 ;

    // node1.next = &node2 ;
    // node2.next = &node3 ;
    // node3.next = NULL ;

    // cout<<"node1 data :"<<node1.data<<endl;
    // cout<<"node2 data :"<<node2.data<<endl;
    // cout<<"node3 data :"<<node3.data<<endl;
    // cout<<"node2 data :"<<node1.next<<endl;
    // cout<<"node2 data :"<<node1.next->data<<endl;
    // cout<<"node2 data :"<<&node2<<endl;
    

    // Node node4 , node5 ;
   
    // cout<<"node2 data :"<<node3.next->data<<endl;


    // node4.data = 50 ;
    // node5.data = 60 ;
    // node3.next = &node4 ;
    // node4.next = &node5 ;
    // node5.next = NULL ;


    // cout<<"node4 data :"<<node4.data<<endl;
    // cout<<"node5 data :"<<node5.data<<endl;
    // cout<<"node2 data :"<<node3.next->data<<endl;
    // cout<<"node3 data :"<<node3.data<<endl;
    // cout<<"node4 data :"<<node3.next<<endl;
    // cout<<"node4 data :"<<&node4<<endl;
    // cout<<"node5 data :"<<node4.next->data<<endl;

    
    // cout<<"node4 data :"<<node3.next->data<<endl;



    // Node node6 , node7 , node8 ;
    // Node* head ;
    // cout<<"enter the data for node6 , node7 , node8"<<endl;
    // cin>>node6.data>>node7.data>>node8.data ;

    // cout<<"node6 data :"<<node6.data<<endl ;
    // cout<<"node7 data :"<<node7.data<<endl ;
    // cout<<"node8 data :"<<node8.data<<endl ;

    // head = &node6 ;
    // node6.next = &node7 ;
    // node7.next = &node8 ;
    // node8.next = NULL ;
    // print(head) ;

    // cout<<"inside the main function head -> data :"<<head->data<<endl;
    // cout<<"inside the main function head :"<<head<<endl;
    // cout<<"inside the main function head :"<<&head<<endl;

}