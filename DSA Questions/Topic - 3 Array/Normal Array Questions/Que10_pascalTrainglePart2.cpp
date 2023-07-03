// GFG -> Pascal Traingle
https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1


// Approch -> 1:
// T.C. .= O(n^2)

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}





// Approch -> 2
// T.C. = O(N)
#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}




// Approch -> 3:
class Solution{
    
    long long modInverse(long long a, long long m) {
        long long m0 = m;
        long long y = 0, x = 1;
        if (m == 1)
            return 0;
        while (a > 1) {
            long long q = a / m;
            long long t = m;
            m = a % m, a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0)
            x += m0;
        return x;
    }
    
    
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<ll>list;
        ll int mod=1e9+7;
        ll ans=1;
        list.push_back(ans);
        for(int col=1;col<n;col++)
        {
            ans=(ans*(n-col))%mod;
            ans=(ans*modInverse(col,mod))%mod;

//ans=((ans/col)%mod )will not work always as ((ans/col)%mod) is not equal to ((ans%mod)*(col%mod)%mod).It is actually equal to 
//((ans%mod)*(col^-1%mod)%mod).Therefore to make this approach to work for all the test cases you have to take the modulo multiplicative 
//inverse of col.Modinverse function takes 1e9+7 and col as input and returns the modulo multiplicative inverse of col.

            ans=ans%mod;
            list.push_back(ans);
        }
        return list;
    }
};