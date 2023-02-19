// Leet Code   Que: 2550. Count Collisions of Monkeys on a Polygon

// T.C. = O(log(n))
class Solution {
public:

    int myPow(int x, int n) { 
        if(n == 0) 
            return 1;

        long long int m = 1000000007 ;
        int ans = myPow(x, n/2)%m;
        
        if(n%2 == 0)
            return ((ans%m) * (ans%m))%m  ;

        else 
            return ((x%m) *(ans%m) * (ans%m))%m ;
    }

    int monkeyMove(int n) {
        long long int m = 1000000007 ;
        int ans = myPow(2,n) ;
        //cout<<ans<<endl;
        ans = ans % m ;
        ans = ans - 2 ;
        ans = ans % m ;

        // This if condition bcz in some case ans = 1 or may be ans = 0 so when we do ans = ans - 2 
        // this will give negative so we use this 
        if(ans < 0)
            ans+=m;
        return ans ;
    }
};
