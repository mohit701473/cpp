// GFG -> Allocate minimum number of pages
https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1



// Approch -> 1: Brute Force Approch
// T.C. = O(N * (sum - max))
// S.C. = O(1)
class Solution 
{
    pair<int, int> getMaxAndSumOfArray(int A[], int N){
        int maxi = INT_MIN, sum = 0 ;
        for(int i=0 ; i<N ; i++){
            int it = A[i] ;
            maxi = max(maxi, it) ;
            sum += it ;
        }

        return {maxi, sum} ;
    }
    
    bool isPossibleAlloction(int A[], int N, int M, int low){
        int studentCnt = 0, pageSum = 0 ;
        for(int i=0 ; i<N ; i++){
            pageSum += A[i] ;
            if(pageSum > low){
                pageSum = A[i] ;
                studentCnt++ ;
            }
        }
        studentCnt++ ;
        if(studentCnt <= M) return true ;
        return false ;
    }
    
    public:
    int findPages(int A[], int N, int M) 
    {
        if(M > N) return -1 ;
        pair<int, int> p = getMaxAndSumOfArray(A, N) ;
        
        int low = p.first, high = p.second ;
        while(low <= high){
            if(isPossibleAlloction(A, N, M, low)) return low ;
            low++ ;
        }
        return low ;
    }
};






// Approch -> 1: Binary Search
// T.C. = O(N * log(sum - max))
// S.C. = O(1)
class Solution 
{
    pair<int, int> getMaxAndSumOfArray(int A[], int N){
        int maxi = INT_MIN, sum = 0 ;
        for(int i=0 ; i<N ; i++){
            int it = A[i] ;
            maxi = max(maxi, it) ;
            sum += it ;
        }

        return {maxi, sum} ;
    }
    
    int isPossibleAlloction(int A[], int N, int mid){
        int studentCnt = 0, pageSum = 0 ;
        for(int i=0 ; i<N ; i++){
            pageSum += A[i] ;
            if(pageSum > mid){
                pageSum = A[i] ;
                studentCnt++ ;
            }
        }
        studentCnt++ ;
        return studentCnt ;
    }
    
    public:
    int findPages(int A[], int N, int M) 
    {
        
        if(M > N) return -1 ;
        pair<int, int> p = getMaxAndSumOfArray(A, N) ;
        
        int low = p.first, high = p.second ;
        while(low <= high){
            int mid = low + (high-low)/2 ;
            int stdudentCount = isPossibleAlloction(A, N, mid) ;
            if(stdudentCount > M) low = mid +1 ;
            else high = mid-1 ;
        }
        return low ;
    }
};