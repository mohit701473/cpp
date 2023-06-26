

// T.C = O(N^2) in best case = O(N) and  avg & wort case = O(N^2)
// S.C = O(1)
class Solution
{
    public:
    void bubbleSort(int arr[], int n)
    {
        for(int i=0 ; i<n ; i++){
            bool flag = true ;
            
            for(int j=0 ; j<n-i-1 ; j++){
                if(arr[j] > arr[j+1]){
                    flag = false ;
                    swap(arr[j], arr[j+1]) ;
                }
            }
            
            if(flag)
                return ;
        }
    }
};