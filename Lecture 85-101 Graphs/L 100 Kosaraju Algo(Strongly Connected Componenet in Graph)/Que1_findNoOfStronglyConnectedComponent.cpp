
// Expected Time Complexity: O(V+E).
// Expected Auxiliary Space: O(V+E).
class Solution
{
	public:
	
	void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s, vector<vector<int>>& adj){
	    
	    vis[node] = true ;
	    
	    for(auto nbr: adj[node]){
	        if(!vis[nbr])
	            dfs(nbr, vis, s, adj) ;
	    }
	    
	    s.push(node) ;
	}
	
	
	void revdfs(int node, unordered_map<int, bool> &vis, vector<vector<int>>& transpose){
	    vis[node] = true ;
	    
	    for(auto nbr: transpose[node]){
	        if(!vis[nbr])
	            revdfs(nbr, vis, transpose) ;
	    }
	}
	
	
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        unordered_map<int, bool> vis ;
        stack<int> s ;
        
        // step -> 1 Sort all the vertices on the basis of their finishing time that mean topological sort
        for(int i=0 ; i<V ; i++){
            if(!vis[i])
                dfs(i, vis, s, adj) ;
        }
        
        // step -> 2 transpose the graph
        vector<vector<int>> transpose(V) ;
        
        for(int i=0 ; i<V ; i++){
            vis[i] = false ;
            for(auto nbr: adj[i]){
                transpose[nbr].push_back(i) ;
            }
        }
        
        int count = 0 ;
        // step -> 3 call dfs according to the ordering
        while(!s.empty()){
            int top = s.top() ;
            s.pop() ;
            
            if(!vis[top]){
                count++ ;
                revdfs(top, vis, transpose) ;
            }
        }
        
        return count ;
        
    }
};

