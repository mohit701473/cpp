https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-array


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int maxi = INT_MIN ;
        
        for(int i=0 ; i<n ; i++)
            maxi = max(maxi, arr[i]) ;
            
        return maxi ;
    }
};