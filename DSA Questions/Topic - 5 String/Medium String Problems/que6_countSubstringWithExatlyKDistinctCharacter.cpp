// GFG -> Count number of substrings
https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1
 


// Approch -> 1: Two Pointer + Sliding Approch
/*
Here we are generating all substrings whose size is K to N i.e first we generate all substrings whose size is 
equal to K and after that we check is this substring contains K distinct elements or not and then we generate all
K+1 substrings and check in those substrings which sustrings have K distinct elements
*/
// T.C. = O(N^2) -> TLE -> So optimize the T.C. to O(N)
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
            // Generating all substrings whose size is equal to size(outer for loop)
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





// Approch -> 2:

class Solution
{
  public:
    long long int substrCount (string str, int k) {
    	int n = str.size() ;
    	long long int count = 0 ;

        unordered_map<char, int> mapb ;
        unordered_map<char, int> maps ;
        int ib = -1 , is = -1 , j = -1 ;
        
        while(1){
            bool f1 = false , f2 = false , f3 = false ;
            
            // insert K distinct character in mapb
            while(ib < n-1){
                f1 = true ;
                ib++ ;
                char ch = str[ib] ;
                mapb[ch]++ ;
                if(mapb.size() == k+1){
                    mapb.erase(ch) ;
                    ib-- ;
                    break ;
                }
            }
            
            // insert K-1 distinct character in maps
            while(is < n){
                f2 = true ;
                is++ ;
                char ch = str[is] ;
                maps[ch]++ ;
                if(maps.size() == k){
                    maps.erase(ch) ;
                    is-- ;
                    break ;
                }
            }
            
            // release characters from map
            while(j < is){
                f3 = true ;
                j++ ;
                if(mapb.size() == k && maps.size() == k-1)
                    count += ib - is ;
                    
                char ch = str[j] ;
                mapb[ch]-- , maps[ch]-- ;
                if(mapb[ch] == 0) mapb.erase(ch) ;
                if(maps[ch] == 0) maps.erase(ch) ;
                
                if(mapb.size() < k || maps.size() < k-1) break ; 
            }
            
            if(f1 == false && f2 == false && f3 == false)
                break ;
            
        }
        
        
        return count ;
    }
};




// Approch -> 3: Count all substrings which have at most K distinct char - Count all substrings which have at 
//               most K-1 distinct char
/*
Much simpler solution than all those mentioned in the comments....you just calculate all substrings having 
at most k characters and then subtract it from all subtrings having at most k-1 characters
*/
// T.C. = O(N) -> Most Optimize solution
// S.C. = O(1)
class Solution
{
     long long ok(string &s, int k, int n)
    {
       int i=0, j=0;
       vector<int>mp(26,0);
       long long ans = 0 ;
       int distinct = 0;
       while( j<n)    // calculating substrings for atmost K
       {
           mp[s[j]-'a']++;
           if(mp[s[j]-'a']==1)distinct++;
           while(distinct>k)
           {
    
               if(mp[s[i]-'a']==1)
               {
                   distinct--;
                   mp[s[i]-'a']--;
               }
               else
                mp[s[i]-'a']--;
               i++;
           }
           ans+=(j-i+1);
           j++;
    
       }
    
       return ans;
    
    
    }
    
    
  public:
    long long int substrCount (string str, int k) {
    	int n = str.size() ;
    //	int ansk = ok(str,k,n) ;
    //	int ansk2 = ok(str,k-1,n) ;
    	//cout << ansk << " " << ansk2 <<endl;
    	long long ans = ok(str,k,n) - ok(str,k-1, n);
        
        return ans;
    }
};