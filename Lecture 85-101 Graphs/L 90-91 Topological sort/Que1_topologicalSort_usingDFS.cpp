
// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).
class Solution
{
	public:
	
	void dfs(int node, vector<int> adj[], unordered_map<int, bool> &visited, stack<int> &s){
	    
	    for(int i=0 ; i<adj[node].size() ; i++){
	        int adjacent = adj[node][i] ;
	        
	        if(!visited[adjacent]){
	            visited[adjacent] = true ;
	            dfs(adjacent, adj, visited, s) ;
	        }
	    }
	    s.push(node) ;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans ;
	    stack<int> s ;
	    unordered_map<int, bool> visited ;
	    
	    for(int i=0 ; i<V ; i++){
	        if(!visited[i]){
	            visited[i] = true ;
	            dfs(i, adj, visited, s) ;
	        }
	    }
	    
	    while(!s.empty()){
	        ans.push_back(s.top()) ;
	        s.pop() ;
	    }
	    
	    return ans ;
	}
};

