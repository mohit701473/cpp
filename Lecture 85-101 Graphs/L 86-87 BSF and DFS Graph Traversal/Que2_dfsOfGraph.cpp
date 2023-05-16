

// Recursive 
// T.C. = O(V+E)
// S.C. = O(V)
class Solution {
  public:
    
    void dfs(vector<int> adj[], vector<int> &ans, unordered_map<int, bool> &visited, int node, int V){
        
        if(ans.size() == V)
            return ;
            
        ans.push_back(node) ;
        
        for(int i=0 ; i<adj[node].size() ; i++){
            if(!visited[adj[node][i]]){
                visited[adj[node][i]] = true ;
                dfs(adj, ans, visited, adj[node][i], V) ;
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans ;
        unordered_map<int, bool> visited;
        visited[0] = true ;
        
        dfs(adj, ans, visited, 0, V) ;
        
        return ans ;
    }
};



// Itrative 
// T.C. = O(V+E)
// S.C. = O(V)
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans ;
        
        unordered_map<int, bool> visited;
        stack<int> st ;
        st.push(0) ;
        visited[0] = true ;
        
        for(int i=0 ; i<V ; i++){
            cout<<i << " -> " ;
            for(int j=0 ; j<adj[i].size() ; j++){
                cout<<adj[i][j] <<", ";
            }cout<<endl;
        }
        
        while(!st.empty()){
            int topNode = st.top() ;
            st.pop() ;
            
            ans.push_back(topNode) ;
            
            for(int i=adj[topNode].size() -1 ; i>=0 ; i--){
                if(!visited[adj[topNode][i]]){
                    st.push(adj[topNode][i]) ;
                    visited[adj[topNode][i]] = true ;
                }
            }
        }
        
        return ans ;
    }
};