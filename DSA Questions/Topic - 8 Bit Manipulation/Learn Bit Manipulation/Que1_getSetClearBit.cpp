https://www.codingninjas.com/studio/problems/bit-manipulation_8142533


// T.C. = O(1)
vector<int> bitManipulation(int num, int i){
    vector<int> ans(3,0) ;
    ans[0] = (num & (1 << (i-1))) ? 1 : 0 ; // Get the bit value at ith position
    ans[1] = num | (1 << (i-1)) ;  // Ste the ith bit
    ans[2] = num & ~(1 << (i-1)) ; // clear the ith bit
    return ans ;
}