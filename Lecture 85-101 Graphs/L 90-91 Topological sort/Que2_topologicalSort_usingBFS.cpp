
// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0) ;
	    queue<int> q ;
	    vector<int> ans ;
	   
	    for(int i=0 ; i<V ; i++){
	        for(int j=0 ; j<adj[i].size() ; j++){
	            int neighbour = adj[i][j] ;
	            indegree[neighbour]++  ; //= indegree[neighbour] + 1 ;
	        }
	    }
	    
	    for(int i=0 ; i<V ; i++){
	        if(indegree[i] == 0) 
	            q.push(i) ;
	    }
	    
	    
	    while(!q.empty()){
	        
	        int frontNode = q.front() ;
	        q.pop() ;
	        ans.push_back(frontNode) ; 
	        
	        for(int i=0 ; i<adj[frontNode].size() ; i++){
	            
	            int neighbour = adj[frontNode][i] ;
	            indegree[neighbour]-- ;
	            
	            if(indegree[neighbour] == 0) 
    	            q.push(neighbour) ;
	        }
	        
	    }
	    
	    return ans ;
	}
};