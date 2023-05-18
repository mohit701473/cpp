
// Expected Time Complexity: O(V*E).
// Expected Auxiliary Space: O(V).
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dis(V,100000000) ;
        
        dis[S] = 0 ;
        
        for(int i=1 ; i<V ; i++){
            for(int j=0 ; j<edges.size() ; j++){
                auto edge = edges[j] ;
                
                int u = edge[0] ;
                int v = edge[1] ;
                int weight = edge[2] ;
                
                
                if(dis[u] != 100000000 && dis[v] > dis[u] + weight)
                    dis[v] = dis[u] + weight ;
                
            }
        }
        
        for(int j=0 ; j<edges.size() ; j++){
            auto edge = edges[j] ;
                
            int u = edge[0] ;
            int v = edge[1] ;
            int weight = edge[2] ;
                
                
            if(dis[u] != 100000000 && dis[v] > dis[u] + weight){
                vector<int> temp ;
                temp.push_back(-1) ;
                return temp ;
            }
        }
        
        return dis ;
    }
};