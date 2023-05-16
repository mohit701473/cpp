
// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)
class Solution {
  public:
    void detectCycleDfs(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int node, bool &ans){
    
        for(int i=0; i<adj[node].size() ; i++){
            int adjacent = adj[node][i] ;
                
            // condition for cycle
            if(visited[adjacent] == true && adjacent != parent[node]){
                ans = true ;
                return ;
            }
            
                    
            // if adjacent/neighneighbor of frontNode is not visited
            else {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    parent[adjacent] = node ;
                    detectCycleDfs(adj, visited, parent, adjacent, ans) ;
                }
            }
            
            if(ans == true)
                return ;
        }
        
    }
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int, bool> visited ;
        unordered_map<int, int> parent ;

        for(int i=0 ; i<V ; i++){
            if(!visited[i]){
                visited[i] = true ;
                parent[i] = -1 ;
                bool ans = false ;
                detectCycleDfs(adj, visited, parent, i, ans) ;
                
                if(ans == true)
                    return true ;
            }
        }
    
        return false ;
    }
};