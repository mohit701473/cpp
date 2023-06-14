// GFG -> First non-repeating character in a stream
https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1




// Expected Time Complexity: O(26*n)
// Expected Space Complexity: O(26)
class Solution {
	public:
	    string FirstNonRepeating(string A){
		    
	        unordered_map<char, int> occureCount ;
		    queue<char> q ;
		    string ans = "" ;
		    
		    for(int i=0 ; i<A.length() ; i++){
		        
		        char ch = A[i] ;
		        occureCount[ch]++ ;
		        if(occureCount[ch] == 1){ // by this condition queue at max store only 26 characters
		            q.push(ch) ;
		        }
		        
		        while(!q.empty()){ // as at max queue has only 26 char then this loop at will run at max times
                    if(occureCount[q.front()] == 1){ // non repeating chracter h to ans m push kr do
		                ans.push_back(q.front()) ;
		                break ;
                    }
                    q.pop() ;
		        }
		        
		        if(q.empty()){
		            ans.push_back('#') ;
		        }
		    }
		    
		    return ans ;
		    
		}

};