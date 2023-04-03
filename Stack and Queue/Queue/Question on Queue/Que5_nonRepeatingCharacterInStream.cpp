// First non-repeating character in a stream

// Expected Time Complexity: O(26 * n)
// Expected Space Complexity: O(26)
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char, int> count ;
		    queue<char> q ;
		    string ans = "" ;
		    
		    for(int i=0 ; i<A.length() ; i++){
		        char ch = A[i] ;
		        
		        // increase count of ch 
		        count[ch]++ ;
		        
		        // push ch into queue
		        q.push(ch) ;
		        
		        while(!q.empty()){
		            // repeating chracter h to pop kr do
		            if(count[q.front()] > 1){
		                q.pop() ;
		            }
		            
		            // non repeating h to push kr do
		            else{
		                ans.push_back(q.front()) ;
		                break ;
		            }
		        }
		        
		        if(q.empty()){
		            ans.push_back('#') ;
		        }
		    }
		    
		    return ans ;
		    
		}

};

