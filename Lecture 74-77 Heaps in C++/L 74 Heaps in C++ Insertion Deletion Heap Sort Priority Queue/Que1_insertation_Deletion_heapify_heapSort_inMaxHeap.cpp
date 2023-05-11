#include<iostream>
using namespace std ;

class Heap{
    public:
    int arr[100] ;
    int size ;

    // Construction Creation
    Heap(){
        arr[0] = -1 ;
        size = 0 ;
    }

    // Function for inserting value into Heap(Max Heap)
    // T.C. (of insert funtion) = O(log(n))  n = no. of Nodes parsent in heap
    void insert(int val){

        size = size+1 ;
        int index = size ; // Index tells us where to insert the value into heap

        // step -> 1  Insert value at teh end of the array
        arr[index] = val ;

        // step -> 2  Put the value to its correct postion(to find the correct position compare val to its parent)
        while(index > 1){

            int parent = index / 2 ; 
            if(arr[parent] < arr[index]){ 
                swap(arr[parent], arr[index]) ;  
                index = parent ;
            }

            else return ;
        }
    }

    void print(){
        for(int i=1 ; i<=size ; i++){
            cout<<arr[i]<< " ";
        }cout<<endl;
    }

    // Function for deleting root from Heap
    // T.C. (of deletion funtion) = O(log(n))  n = no. of Nodes parsent in heap
    void deleteFromHeap(){
        if(size == 0){
            cout<<"heap is empty"<<endl;
            return ;
        }

        // step -> 1 put last index data on 1st index
        arr[1] = arr[size] ;

        // step -> 2 delete last index
        size-- ; // i.e. no one can excess last index

        // step -> 3 put the 1st index element to its correct position
        int i = 1 ;
        while(i <= size){
            int leftChild = 2*i ;
            int rightChild = 2*i + 1 ;

            int maxIndex = i ;

            
            if(leftChild <= size && rightChild <= size){
                if(arr[leftChild] < arr[rightChild]){
                    maxIndex = rightChild ;
                }

                else maxIndex = leftChild ;
            }

            else{
                if(leftChild <= size)
                    maxIndex = leftChild ;

                else if(rightChild <= size)
                    maxIndex = rightChild ;

                else return ;
            }

            if(arr[i] < arr[maxIndex]){
                swap(arr[i], arr[maxIndex]) ;
                i = maxIndex ;
            }
            else return ;
        }
    }

};


void heapify(int arr[], int i, int n){
    int largest = i ;
    int left = 2*i ;
    int right = 2*i + 1 ;

    if(left <= n && arr[left] > arr[largest])
        largest = left ;

    if(right <= n && arr[right] > arr[largest]) 
        largest = right ;

    if(largest != i){
        swap(arr[i], arr[largest]) ;
        heapify(arr, largest, n) ;
    }
}

void heapSort(int arr[], int n){
    int size = n ;

    while(size > 1){
        // step -> 1  swap 1st and last element 
        swap(arr[size], arr[1]) ;
        size-- ;

        // step -> 2 
        heapify(arr, 1, size) ;
    }
}

int main()
{
    Heap h ;
    h.insert(55) ;
    h.insert(53) ;
    h.insert(54) ;
    h.insert(50) ;
    h.insert(52) ;

    h.print() ;
    h.deleteFromHeap() ;
    h.print() ;

    int arr[6] = {-1, 54, 53, 55, 50, 52} ;
    int n = 5 ;

    for(int i=n/2 ; i>=1 ; i--){
        heapify(arr, i, n) ;
    }

    heapSort(arr, n) ;

    for(int i=1 ; i<=n ; i++){
        cout<<arr[i] <<" " ;
    }cout<<endl;
    // h.insert(60) ;
    // h.insert(50) ;
    // h.insert(40) ;
    // h.insert(30) ;
    // h.insert(20) ;
    // h.print() ;

    // h.insert(55) ;
    // h.print() ;

    // h.insert(70) ;
    // h.print() ;
}