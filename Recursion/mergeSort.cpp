#include<iostream>
using namespace std;

void print(int arr[], int n){

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl ;
}


void merge(int arr[], int l, int mid, int h) {

    int i, j, index ;
    int n1 = mid - l + 1 ; // length of Left subArray
    int n2 = h - mid ;    // length of Right subArray

    int left[n1] ;  // Left subArray
    int right[n2] ; // Right subArray

    // Copy data from main array to left subArray
    for(i=0 ; i<n1 ; i++)
        left[i] = arr[l + i] ;

    cout<<"Left subArray"<<endl;
    print(left, n1) ;

    // Copy data from main array to right subArray
    for(j=0 ; j<n2 ; j++)
        right[j] = arr[mid + 1 + j] ;
    
    cout<<"Right subArray"<<endl;
    print(right, n2) ;

    i = 0 ;     // Stariting index of left subArray
    j = 0 ;    // Starting index of right subArray
    index = l ; // Starting index of main subArray


    while(i<n1 && j<n2) {
        if(left[i] <= right[j]) {
            arr[index] = left[i] ;
            i++ ;
        }

        else{
            arr[index] = right[j] ;
            j++ ;
        }

        index++;
    }

    // Length of right subArray > Length of left subArray
    while(i<n1) {
        arr[index] = left[i] ;
        i++ ;
        index++;
    }

    // Length of left subArray > Length of right subArray
    while(j<n2) {
        arr[index] = right[j] ;
        j++ ;
        index++;
    }

    cout<<"sorted subArray"<<endl;
    print(arr, h+1) ;

}


void mergeSort(int arr[], int l, int h){

    if(l >= h)
        return ;

    int mid = (l+h) / 2;

    mergeSort(arr, l, mid) ;
    mergeSort(arr, mid+1, h) ;
    merge(arr, l, mid, h) ;
    
    cout<<"after merging"<<endl;
    print(arr,7) ;
    cout<<endl;
}

int main()
{
    int arr[] = {7, 2, 1, 11, 3, 4, 2};
    int size = 7 ;
    mergeSort(arr, 0, size - 1);
    
    cout<<endl<<"sorted array by Merge Sort"<<endl;
    print(arr, 7) ;

}