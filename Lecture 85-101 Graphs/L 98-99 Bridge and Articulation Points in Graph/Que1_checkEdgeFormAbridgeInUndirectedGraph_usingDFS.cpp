

// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).
class Solution
{
	public:
    void dfs(int node, unordered_map<int, bool> &visited, vector<int> adj[], int &d, bool &ans){
        visited[node] = true ;
        
        for(auto neighbour: adj[node]){
            if(neighbour != -1 && !visited[neighbour]){
                
                if(neighbour == d){  // that mean their is still a path exist form vertex c to d
                    ans = true ;
                    return ;
                }
                //cout<<"visited size -> "<<visited.size()<<endl ;
                dfs(neighbour, visited, adj, d, ans) ;
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        
        if( c == d)  // self loop edge not a bridge 
            return 0 ;
        
        for(auto &i: adj[c]){
            if(i == d){
                i = -1 ;
            }
        }
        
        for(auto &j: adj[d]){
            if(j == c)
                j = -1 ;
        }
        
        unordered_map<int, bool> visited ;
        bool ans = false ; // we assume that edge(c,d) is not a bridge 
        
        dfs(c, visited, adj, d, ans) ;
        
        if(ans)  return 0 ;  // if edge(c,d) is not a bridge
        
        return 1 ; // edge(c,d) is a bridge
    }
};