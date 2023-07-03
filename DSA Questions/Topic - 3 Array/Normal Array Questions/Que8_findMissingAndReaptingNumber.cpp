// GFG -> Find Missing And Repeating
https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1



// Approch -> 1: Simple Math
// T.C. = O(N)
// S.C. = O(1)
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int N) {
        long long n = arr.size(); // size of the array

        // Find Sn and S2n:
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    
        // Calculate S and S2:
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];
        }
    
        //S-Sn = X-Y:
        long long val1 = S - SN;
    
        // S2-S2n = X^2 - Y^2:
        long long val2 = S2 - S2N;
    
        //Find X+Y = (X^2-Y^2)/(X-Y):
        val2 = val2 / val1;
    
        //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
        // Here, X-Y = val1 and X+Y = val2:
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
    
        return {(int)x, (int)y};
    }
};