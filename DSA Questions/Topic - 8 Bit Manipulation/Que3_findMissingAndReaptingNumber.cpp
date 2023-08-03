// GFG -> Find Missing And Repeating
https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1




// Approch -> 2: Using Bit Manipulation 
/*
    Approch Steps:
        step -> 1: num = arr[i] ^ (1^2^3^......^N)
        step -> 2: find the first set bit in num, first set bit from right
        step -> 3: put the array element and 1 to N elemnt in two seperate clubs(0bit & 1bit club) and xor these two club to get ans
*/
// T.C. = O(N)
// S.C> = O(1)
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        // step -> 1: num = arr[i] ^ (1^2^3^......^N)
        int xr1 = 0, xr2 = 0 ;  // xr1 will store teh xor of array element and xr2 will store the xor on 1 to N no.
        for(int i=0 ; i<n ; i++){
            xr1 ^= arr[i] ;
            xr2 ^= i+1 ;
        }
        
        int xr = xr1 ^ xr2 ; 
        
        // step -> 2: find the first set bit in num, first set bit from right
        int bitIdx = xr & ~(xr-1) ;  // insted of this we do int num = xr & ~(xr-1)
        // while(1){
        //     if( (xr & (1 << bitIdx)) != 0 ) break ;
            
        //     bitIdx++ ;
        // }
        
        // step -> 3:
        int zeroBitClub = 0 ;
        int oneBitClub = 0 ;
        
        for(int i=0 ; i<n ; i++){
            // part of 1 club
            if( (arr[i] & ( bitIdx)) != 0 ){
                oneBitClub ^= arr[i] ;
            }
            // part of 0 club
            else{
                zeroBitClub ^= arr[i] ;
            }
        }
        
        for(int i=1 ; i<=n ; i++){
            // part of 1 club
            if( (i & ( bitIdx)) != 0 ){
                oneBitClub ^= i ;
            }
            // part of 0 club
            else{
                zeroBitClub ^= i ;
            }
        }
        
        int count = 0 ;
        for(int i=0 ; i<n ; i++){
            if(arr[i] == zeroBitClub) count++ ;
        }
        
        if(count == 2) return {zeroBitClub, oneBitClub} ;
        return {oneBitClub, zeroBitClub} ;
    }
};