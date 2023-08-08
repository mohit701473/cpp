


// Approch -> 1: Two Pointer + Sliding Approch
// T.C. = O(N^2)
// S.C. = O(1)
class Solution
{
  public:
    long long int substrCount (string str, int k) {
    	int n = str.size(), count = 0 ;

        for(int size = k ; size <= n ; size++){
            int i = 0 , j = size-1 ;
    
            unordered_map<char, int> freq ;
            for(int idx = i ; idx <= j ; idx++) 
                freq[str[idx]]++ ;
    
            if(freq.size() == k) count++ ;
            
            j++ ;
            while(j < n){
                freq[str[j]]++ ;
                freq[str[i]]-- ;
                if(freq[str[i]] == 0) freq.erase(str[i]) ;
                if(freq.size() == k) count++ ;
                i++, j++ ;
            }
        }
    
        return count ;
    }
};