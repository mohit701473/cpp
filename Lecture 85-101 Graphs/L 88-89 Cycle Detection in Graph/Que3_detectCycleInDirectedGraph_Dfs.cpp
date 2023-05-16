
// Approch 1 

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
#include<list>
#include<unordered_map>
bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj){

  visited[node] = true ;
  dfsVisited[node] = true ;

  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      bool cycleDetected = checkCycleDfs(neighbour, visited, dfsVisited, adj) ;
      if(cycleDetected)
        return true ;
    }

    else {
      if(dfsVisited[neighbour])
        return true ;
    }
  }

  dfsVisited[node] = false ;
  return false; 
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    unordered_map<int, list<int>> adj ;

    // Create adjacency list
    for(int i = 0; i<edges.size(); i++) {
      int u = edges[i].first ;
      int v = edges[i].second ;

      adj[u].push_back(v);
    }

    unordered_map<int, bool> visited ;
    unordered_map<int, bool> dfsVisited ; 
    // call dfs fro all components
    for(int i=1 ; i<=n ; i++){

      if(!visited[i]){
        bool cycleFound = checkCycleDfs(i, visited, dfsVisited, adj) ;

        if(cycleFound)
          return true ;
      }
    }

    return false ;
}


// Approch 2 using colour method

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
class Solution {
  public:
    
    void dfsCheckCycle(vector<int> adj[], unordered_map<int, char> &colour, int node, bool &ans){
        
        for(int i=0; i<adj[node].size() ; i++){
            int adjacent = adj[node][i] ;
            
            if(colour[adjacent] == 'G'){
                ans = true ;
                return ;
            }
            
            else if(colour[adjacent] == 'W'){
                colour[adjacent] = 'G' ;
                dfsCheckCycle(adj, colour, adjacent, ans) ;
            }
            
            if(ans)
                return ;
        }
        
        colour[node] = 'B' ;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, char> colour ;
        
        // Initially all vertex have White(W) colour
        for(int i=0 ; i<V ; i++)
            colour[i] = 'W' ;
            
        for(int i=0 ; i<V ; i++){
            if(colour[i] == 'W'){
                bool ans = false ;
                // call dfs ton check cycle
                dfsCheckCycle(adj, colour, i, ans) ;
                
                if(ans)
                    return true ;
            }
        }
        
        return false ;
    }
};