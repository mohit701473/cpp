
// Approch 1 
// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)
class Solution {
  public:
    bool detectCycle(vector<int> adj[], unordered_map<int, bool> &visited, int src){
        unordered_map<int, int> parent ;

        queue<int> q ;
        q.push(src) ;
        visited[src] = true ;
        parent[src] = -1 ;
    
        while(!q.empty()){
            int frontNode = q.front() ;
            q.pop() ;
    
            for(int i=0; i<adj[frontNode].size() ; i++){
                int adjacent = adj[frontNode][i] ;
                
                // condition for cycle
                if(visited[adjacent] == true && adjacent != parent[frontNode]){
                   // cout<<"enter"<<endl;
                    return true ;
                }
                    
                // if adjacent/neighneighbor of frontNode is not visited
                else {
                    if (!visited[adjacent]) {
                        q.push(adjacent);
                        visited[adjacent] = true;
                        parent[adjacent] = frontNode;
                    }
                }
            }
        }
        
        return false ;

    }
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int, bool> visited ;

        for(int i=0 ; i<V ; i++){
            if(!visited[i]){
                bool ans = detectCycle(adj, visited, i) ;
                //cout<<ans<<endl;
                if(ans == true)
                    return true ;
            }
        }
    
        return false ;
    }
};



// Approch 2 using colour method
// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)
class Solution {
  public:
    // white(W) -> Node/Vertex is not visited
    // Gray(G)  -> Node/Vertex is visited & inserted into queue but not completly explored
    // Black(B) -> Node/Vertex is poped from queue and completly explored
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, char> colour ;
        
        for(int i=0 ; i<V ; i++){  
                if(colour[i] != 'W')
                    colour[i] = 'W' ;
        }
        
        queue<int> q ;
        
        for(int i=0 ; i<V ; i++){
            if(colour[i] == 'W'){
                // call bfs 
                q.push(i) ;
                colour[i] = 'G' ;
                while(!q.empty()){
                    int frontNode = q.front() ;
                    q.pop() ;
                    
                    for(int i=0 ; i<adj[frontNode].size() ; i++){
                        if(colour[adj[frontNode][i]] == 'G')
                            return true ;
                            
                        else if(colour[adj[frontNode][i]] == 'W'){
                            q.push(adj[frontNode][i]) ;
                            colour[adj[frontNode][i]] = 'G' ;
                        }
                    }
                    
                    colour[frontNode] = 'B' ;
                }
            }
        }
        
        return false ;
    }
};