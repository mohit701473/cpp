


// T.C = O(N^2) in best case = O(N) and  avg & wort case = O(N^2)
// S.C = O(1)
void insertionSort(int arr[], int n)
    {
        for(int i=1 ; i<n ; i++){
            int temp = arr[i] ;
            int j = i-1 ;
            
            while(j >= 0 && arr[j] > temp){
                arr[j+1] = arr[j] ;
                j-- ;
            }
            
            arr[j+1] = temp ;
        }
    }

