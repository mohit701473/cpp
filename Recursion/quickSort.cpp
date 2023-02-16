#include<iostream>
#include<vector>
using namespace std ;
int n;
void print(int arr[], int n){

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl ;
}

void swap(int* a, int* b) {

    int temp = *a ;
    *a = *b ;
    *b = temp ;
}


int partition(int v[], int s, int e) {

    int pivot = v[e] ;

    int i = s-1 ;
    int j = s ;

    for(j ; j<e ; j++) {

        if(v[j] <= pivot) {
            i++ ;
            swap(&v[i] , &v[j]) ;
        }
    }

    i++ ;
    swap(&v[i] , &v[j]) ;

    cout<<endl<<"pivot index = "<<i<<endl;
    print(v , n) ;
    cout<<endl;

    return i ;
}

void quickSort(int v[], int s, int e) {

    
    if(s < e) {
        //count++ ;
        int q = partition(v, s, e) ;
        quickSort(v, s, q-1) ;
        quickSort(v, q+1, e) ;
    }
}

int main() 
{
    cout<<"enter the size"<<endl;
    cin>>n;

    //vector<int> v(n) ; // Declear a vector of size n and values inside this 0
    
     int v[n] ;
    

    cout<<"Input array"<<endl;
    for(int i=0 ; i<n ; i++) {
        cin>>v[i] ;
    }

    // for(auto it: v) {
    //     cout<<it <<" ";
    // }

    quickSort(v, 0 , n-1) ;
    cout<<endl<<"Output array"<<endl;
    for(int i=0 ; i<n ; i++) {
        cout<<v[i] <<" ";
    }
    
    
}