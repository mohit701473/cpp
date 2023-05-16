// BFS for connected graph

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans ;
         
        unordered_map<int, bool> visited ;  // initially all the value marked false by default
        queue<int> q ;
        
        q.push(0) ;
        visited[0] = true ;
        
        while(!q.empty()){
            int frontNode = q.front() ;
            q.pop() ;
            
            // insert all the neighbour of frontNode into queue & make sure neighbour not visited
            for(int i=0 ; i<adj[frontNode].size() ; i++){
                if( !visited[adj[frontNode][i]] ){
                    // insert it into queue
                    q.push(adj[frontNode][i]) ;
                    visited[adj[frontNode][i]] = true ;
                }
            }
            
            ans.push_back(frontNode) ;
        }
        
        return ans ;
    }
};