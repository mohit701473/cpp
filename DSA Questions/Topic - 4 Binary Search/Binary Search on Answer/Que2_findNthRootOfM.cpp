// GFG -> Find Nth root of M
https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1



// Approch -> 1: Binary Search
// Expected Time Complexity: O(n* log(m))
// Expected Space Complexity: O(1)
class Solution{
    
    int func(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * mid;
            if (ans > m) return 2;
        }
        if (ans == m) return 1;
        return 0;
	}
    
	public:
	
	int NthRoot(int n, int m)
	{
	    int low = 1, high = m;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midN = func(mid, n, m);
            if (midN == 1) {
                return mid;
            }
            else if (midN == 0) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
	}  
};