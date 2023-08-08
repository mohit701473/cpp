// GFG -> Count Substring
https://practice.geeksforgeeks.org/problems/count-substring/1


// Approch -> 3: Count all substrings which have at most K distinct char - Count all substrings which have at 
//               most K-1 distinct char
/*
Much simpler solution than all those mentioned in the comments....you just calculate all substrings having 
at most k characters and then subtract it from all subtrings having at most k-1 characters
*/
// T.C. = O(N) -> Most Optimize solution
// S.C. = O(1)
class Solution {
    
    int ok(string &s, int k, int n)
    {
       int i=0, j=0;
       vector<int>mp(26,0);
       int ans = 0 ;
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
    int countSubstring(string str) {
        int n = str.size() ;
    	int ans = ok(str,3,n) - ok(str,2, n);
        
        return ans;
    }
};