// Shortest path in Undirected Graph having unit distance
/*You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex 
and if it is unreachable to reach any vertex, then return -1 for that vertex.
*/

class Solution {
  public:
  
    void solve(int src, unordered_map<int, int> &parent, vector<int> &ans, int desti, int &count, int &trackDesti){
        
        if(src == desti) {
            ans[trackDesti] = count ;
            return ;
        }
            
        count++ ;
        solve(src, parent, ans, parent[desti], count, trackDesti) ;
        
    }  

    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N] ;
        unordered_map<int, int> parent ;
        unordered_map<int, bool> visited ;
        vector<int> ans(N,-1) ;
        queue<int> q ;
        
        // create adjacency list
        for(auto i: edges){
            int u = i[0] ;
            int v = i[1] ;
            
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
            
        }
        
        q.push(src) ;
        visited[src] = true ;
        parent[src] = -1 ;
        
        while(!q.empty()){
            int frontNode = q.front() ;
            q.pop() ;
            
            for(int i=0 ; i<adj[frontNode].size() ; i++){
                int neighbour = adj[frontNode][i] ;
                
                if(!visited[neighbour]){
                    visited[neighbour] = true ;
                    parent[neighbour] = frontNode ;
                    q.push(neighbour) ;
                }
            }
        }
        
        for(int i=0 ; i<N ; i++){
            
            if(visited[i])
                int count = 0  ;
                solve(src, parent, ans , i, count, i) ;
        }

        return ans ;
    }
};