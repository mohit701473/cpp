

class Solution {
  public:
  
    void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, vector<int>adj[], int &timer, set<int> &st){
        
        int child = 0 ;
        
        vis[node] = true ;
        disc[node] = low[node] = timer++ ;
        
        for(auto nbr: adj[node]){
            if(nbr == parent)
                continue ;
                
            if(!vis[nbr]) {
                // step -> 1 dfs call for nbr
                dfs(nbr, node, disc, low, vis, adj, timer, st) ;
                
                // update low[node] 
                low[node] = min(low[node], low[nbr]) ;
                
                // check is this node a AP or not
                if(low[nbr] >= disc[node] && parent != -1)
                    st.insert(node) ;
                    
                
                child++ ;
            }
            
            else{ // nbr is visited
                low[node] = min(low[node], disc[nbr]) ;
            }
        }
        
        if(parent == -1 && child > 1){
            st.insert(node) ;
        }
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        int timer = 0 ;
        int parent = -1 ;
        vector<int> disc(V,-1) ;
        vector<int> low(V,-1) ;
        unordered_map<int, bool> vis ;
        set<int> st ;
        vector<int> ans ;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i])
                dfs(i, parent, disc, low, vis, adj, timer, st) ;
        }
        
        for(auto val: st){
            ans.push_back(val) ;
        }
        
        if(ans.size() == 0)
            ans.push_back(-1) ;
            
        
        
        return ans ;
    }
};