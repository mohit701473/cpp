
// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> indegree(V,0) ;
	    queue<int> q ;
	    int count = 0 ;
	   
	    for(int i=0 ; i<V ; i++){
	        for(int j=0 ; j<adj[i].size() ; j++){
	            int neighbour = adj[i][j] ;
	            indegree[neighbour]++  ;
	        }
	    }
	    
	    for(int i=0 ; i<V ; i++){
	        if(indegree[i] == 0) 
	            q.push(i) ;
	    }
	    
	    
	    while(!q.empty()){
	        
	        int frontNode = q.front() ;
	        q.pop() ;
	        count++ ;
	        
	        for(int i=0 ; i<adj[frontNode].size() ; i++){
	            
	            int neighbour = adj[frontNode][i] ;
	            indegree[neighbour]-- ;
	            
	            if(indegree[neighbour] == 0) 
    	            q.push(neighbour) ;
	        }
	        
	    }
	    
	    if (count == V) return false ;
	    
	    return true ;
    }
};