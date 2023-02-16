#include<iostream>
using namespace std;
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    cout<<arr<<endl;
    cout<<&arr<<endl;
    int *arr1 = arr;
    cout<<*arr1<<endl;
    cout<<arr1<<endl;
    cout<<arr1+1<<endl;
    arr1++;
    cout<<arr1<<endl;
    cout<<arr[1]<<endl;
    cout<<*(arr+1)<<endl;
    cout<<1[arr]<<endl;
}