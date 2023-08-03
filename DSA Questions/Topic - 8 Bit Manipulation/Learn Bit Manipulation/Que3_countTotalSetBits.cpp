

// Approch -> 1:
// T.C. - O(Nlog(N))
int countSetBits(int N)
{
    int count = 0 ;
    for(int i=1 ; i<=N ; i++){
        int num = i ;
        while(num>0){
            if(num&1 == 1) count++ ;
            num >>= 1 ;
        }
    }
    return count ;
}




// Approch -> 2:
// T.C. = O(32Log(N))

int largesstPowerOf2InRangeOfN(int N){
    int x = 0 ;
    while((1 << x) <= N) x++ ;
    return x-1 ;
}


int countSetBits(int N)
{
    if(N == 0) return 0 ;
    
    int x = largesstPowerOf2InRangeOfN(N) ;
    int countSetBitTill2PowerX = x * (1 << (x-1)) ;
    int msbSetBitCountFrom2PowerXToN = N - (1 << x) + 1 ;
    int rest = N - (1 << x) ;
    int ans = countSetBitTill2PowerX + msbSetBitCountFrom2PowerXToN + countSetBits(rest) ;
    return ans ;
}