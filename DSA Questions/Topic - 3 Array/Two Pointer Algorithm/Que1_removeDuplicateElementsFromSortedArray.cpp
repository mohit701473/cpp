// GFG -> https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1

// LeetCode -> https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/



// Approch -> Two Pointer Algorith
// T.C. = O(N)
// S.C. = O(1)
class Solution{
public:
    int remove_duplicate(int a[],int n){
        
        int i=0, j=0 ;
        
        while(j<n){
            a[i] = a[j] ;
            i++ ;
            
            int temp = a[j] ;
            
            while(j<n && temp == a[j])
                j++ ;
        }
        
        return i ;
    }
};