


int setBits(int N){
    int num = N ;
    int x = 0 ;
    while(num > 0 && (num & 1) == 1){
        x++ ;
        num >>= 1 ;
    }
    if(num == 0) return N ;
    return N | (1 << x) ;
}